//
// Created by spyteamalex on 12.06.22.
//

#include <QPainter>
#include <utility>
#include "selector_ring.h"

QPainterPath drawRing(int x, int y, double r1, double r2, double frm, double ang){
    QPainterPath path = QPainterPath(QPointF(x + r2 * cos(frm * PI / 180), y - r2 * sin(frm * PI / 180)));
    path.arcTo(x - r2, y - r2, 2 * r2, 2 * r2, frm, ang);
    path.arcTo(x - r1, y - r1, 2 * r1, 2 * r1, frm + ang, -ang);
    path.closeSubpath();
    return path;
}

void SelectorRing::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), Qt::transparent);
    for(int i = 0; i < data.size(); i++)
        drawSector(i, painter, i == selected);
}

bool SelectorRing::shown = false;

//void SelectorRing::redraw() {
//
////    painter.end();
//}

void SelectorRing::drawSector(int i, QPainter &painter, bool isSelected = false) {
    double ang = (finishAngle - startAngle) / data.size();
    if(isSelected){
        painter.setPen(selectedSectorBorder);
        painter.setBrush(selectedSectorColor);
    }else {
        painter.setPen(sectorBorder);
        painter.setBrush(sectorColor);
    }
    painter.drawPath(drawRing(width() / 2, height() / 2, innerRadius, outerRadius, startAngle + (ang * i + sectorBuf), ang - 2 * sectorBuf));

    double iconPosAngle = startAngle + (ang * i + sectorBuf) + (ang - 2 * sectorBuf) / 2.0;
    iconPosAngle *= PI / 180;
    QPointF iconPos = QPointF(
            width() / 2.0 + (innerRadius+outerRadius) / 2.0 * cos(iconPosAngle) - iconSize.width()/2.0,
            height() / 2.0 - (innerRadius+outerRadius) / 2.0 * sin(iconPosAngle) - iconSize.height()/2.0);
    painter.drawPixmap(iconPos, data.at(i).getIcon().pixmap(iconSize));
}

double SelectorRing::getInnerRadius() const {
    return innerRadius;
}

double SelectorRing::getOuterRadius() const {
    return outerRadius;
}

double SelectorRing::getStartAngle() const {
    return startAngle;
}

double SelectorRing::getFinishAngle() const {
    return finishAngle;
}

const QColor &SelectorRing::getSelectedSectorBorder() const {
    return selectedSectorBorder;
}

void SelectorRing::setSelectedSectorBorder(const QColor &v) {
    SelectorRing::selectedSectorBorder = v;
    update();
}

const QBrush &SelectorRing::getSelectedSectorColor() const {
    return selectedSectorColor;
}

void SelectorRing::setSelectedSectorColor(const QBrush &v) {
    SelectorRing::selectedSectorColor = v;
    update();
}

const QColor &SelectorRing::getSectorBorder() const {
    return sectorBorder;
}

void SelectorRing::setSectorBorder(const QColor &v) {
    SelectorRing::sectorBorder = v;
    update();
}

const QBrush &SelectorRing::getSectorColor() const {
    return sectorColor;
}

void SelectorRing::setSectorColor(const QBrush &v) {
    SelectorRing::sectorColor = v;
    update();
}

double SelectorRing::getSectorDistance() const {
    return sectorBuf;
}

void SelectorRing::setSectorDistance(double v) {
    SelectorRing::sectorBuf = v;
    update();
}

void SelectorRing::setInnerRadius(double v) {
    SelectorRing::innerRadius = v;
    update();
}

void SelectorRing::setOuterRadius(double v) {
    SelectorRing::outerRadius = v;
    update();
}

void SelectorRing::setStartAngle(double v) {
    SelectorRing::startAngle = v;
    update();
}

void SelectorRing::setFinishAngle(double v) {
    SelectorRing::finishAngle = v;
    update();
}

void SelectorRing::setSelected(int v) {
    SelectorRing::selected = v;
    update();
}

int SelectorRing::getSelected() const {
    return selected;
}

SelectorRing::SelectorRing(double innerRadius, double outerRadius, double startAngle, double finishAngle, QSize iconSize, QWidget *parent) : QWidget(parent),
                                                                                             innerRadius(innerRadius),
                                                                                             outerRadius(outerRadius),
                                                                                             startAngle(startAngle),
                                                                                             iconSize(iconSize),
                                                                                             selected(0),
                                                                                             finishAngle(finishAngle) {
    setWindowFlags(Qt::WindowType::WindowStaysOnTopHint
            | Qt::WindowType::FramelessWindowHint
            | Qt::WindowType::WindowDoesNotAcceptFocus
            | Qt::WindowType::Tool);
    setAttribute(Qt::WidgetAttribute::WA_TranslucentBackground);
    setAttribute(Qt::WidgetAttribute::WA_TransparentForMouseEvents);
    setAttribute(Qt::WidgetAttribute::WA_ForceDisabled);

#ifdef SECTOR_DISTANCE
    sectorBuf = SECTOR_DISTANCE;
#endif
#ifdef SECTOR_COLOR
    sectorColor = SECTOR_COLOR;
#endif
#ifdef SECTOR_BORDER
    sectorBorder = SECTOR_BORDER;
#endif
#ifdef SELECTED_SECTOR_BORDER
    selectedSectorBorder = SELECTED_SECTOR_BORDER;
#endif
#ifdef SELECTED_SECTOR_COLOR
    selectedSectorColor = SELECTED_SECTOR_COLOR;
#endif

}

bool SelectorRing::show() {
    if(shown)
        return false;
    QWidget::showFullScreen();
    shown = true;
    return true;
}

void SelectorRing::close() {
    QWidget::close();
    shown = false;
}

const QVector<SelectorRingItem> &SelectorRing::getData() const {
    return data;
}

void SelectorRing::setData(const QVector<SelectorRingItem> &v) {
    SelectorRing::data = v;
    update();
}

const QSize &SelectorRing::getIconSize() const {
    return iconSize;
}

void SelectorRing::setIconSize(const QSize &v) {
    SelectorRing::iconSize = v;
    update();
}

const QIcon &SelectorRingItem::getIcon() const {
    return icon;
}

SelectorRingItem::SelectorRingItem(QIcon icon, std::function<void(void)> action) : icon(std::move(icon)),
                                                                                                 action(std::move(action)) {}

const std::function<void(void)> &SelectorRingItem::getAction() const {
    return action;
}

SelectorRingItem::SelectorRingItem(SelectorRingItem &&a) noexcept : icon(std::move(a.icon)),
                                                           action(std::move(a.action))  {}

SelectorRingItem::SelectorRingItem(const SelectorRingItem &a) = default;

//
// Created by spyteamalex on 12.06.22.
//

#include <QPainter>
#include "selector_ring.h"

QPainterPath drawRing(int x, int y, double r1, double r2, int frm, int ang){
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
    for(int i = 0; i < sectorCount; i++)
        drawSector(i, painter, i == selected);
}

//void SelectorRing::redraw() {
//
////    painter.end();
//}

void SelectorRing::drawSector(int i, QPainter &painter, bool isSelected = false) {
    int ang = (finishAngle - startAngle) / sectorCount;
    if(isSelected){
        painter.setPen(selectedSectorBorder);
        painter.setBrush(selectedSectorColor);
    }else {
        painter.setPen(sectorBorder);
        painter.setBrush(sectorColor);
    }
    painter.drawPath(drawRing(width() / 2, height() / 2, innerRadius, outerRadius, startAngle + (ang * i + sectorBuf), ang - 2 * sectorBuf));
}

double SelectorRing::getInnerRadius() const {
    return innerRadius;
}

double SelectorRing::getOuterRadius() const {
    return outerRadius;
}

int SelectorRing::getSectorCount() const {
    return sectorCount;
}

int SelectorRing::getStartAngle() const {
    return startAngle;
}

int SelectorRing::getFinishAngle() const {
    return finishAngle;
}

const QColor &SelectorRing::getSectorBorderSelected() const {
    return selectedSectorBorder;
}

void SelectorRing::setSectorBorderSelected(const QColor &v) {
    SelectorRing::selectedSectorBorder = v;
    update();
}

const QBrush &SelectorRing::getSectorColorSelected() const {
    return selectedSectorColor;
}

void SelectorRing::setSectorColorSelected(const QBrush &v) {
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

int SelectorRing::getSectorDistance() const {
    return sectorBuf;
}

void SelectorRing::setSectorDistance(int v) {
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

void SelectorRing::setSectorCount(int v) {
    SelectorRing::sectorCount = v;
    update();
}

void SelectorRing::setStartAngle(int v) {
    SelectorRing::startAngle = v;
    update();
}

void SelectorRing::setFinishAngle(int v) {
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

SelectorRing::SelectorRing(double innerRadius, double outerRadius,
                           int sectorCount, int startAngle, int finishAngle, QWidget *parent) : QWidget(parent),
                                                                                             innerRadius(innerRadius),
                                                                                             outerRadius(outerRadius),
                                                                                             sectorCount(sectorCount),
                                                                                             startAngle(startAngle),
                                                                                             finishAngle(finishAngle) {
    setWindowFlags(Qt::WindowType::WindowStaysOnTopHint
            | Qt::WindowType::FramelessWindowHint
            | Qt::WindowType::WindowDoesNotAcceptFocus
            | Qt::WindowType::Tool);
    setAttribute(Qt::WidgetAttribute::WA_TranslucentBackground);
    setAttribute(Qt::WidgetAttribute::WA_TransparentForMouseEvents);
    setAttribute(Qt::WidgetAttribute::WA_ForceDisabled);
}

void SelectorRing::show() {
    QWidget::showFullScreen();
}

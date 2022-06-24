//
// Created by spyteamalex on 12.06.22.
//

#ifndef GYROGLOVECPP_SELECTOR_RING_H
#define GYROGLOVECPP_SELECTOR_RING_H


#include <QLabel>
#include <QIcon>
#include "../Tools/my_math.h"
#include "../global.h"

class SelectorRingItem : public QObject{
    Q_OBJECT

private:
    QIcon icon;
    std::function<void (void)> action;
public:

    explicit SelectorRingItem(QObject *, QIcon icon = QIcon(), std::function<void(void)> action = [](){});

    SelectorRingItem(SelectorRingItem&&) noexcept;

    SelectorRingItem(const SelectorRingItem &ringItem);

    [[nodiscard]] const QIcon &getIcon() const;

    [[nodiscard]] const std::function<void(void)> &getAction() const;
};

class SelectorRing : public QWidget{
    Q_OBJECT


protected:
    void paintEvent(QPaintEvent *event) override;

private:

    double innerRadius;
    double outerRadius;
    double startAngle;
    double finishAngle;
    int selected;
    QSize iconSize;
    static bool shown;

    QVector<SelectorRingItem*> data;

    QColor selectedSectorBorder = Qt::white;
    QBrush selectedSectorColor = Qt::white;
    QColor sectorBorder = Qt::white;
    QBrush sectorColor = Qt::black;
    double sectorBuf = 0;

    void drawSector(int i, QPainter &painter, bool isSelected);

public:
    explicit SelectorRing(
            double innerRadius = INNER_RADIUS_DEFAULT,
            double outerRadius = OUTER_RADIUS_DEFAULT,
            double startAngle = START_ANGLE_DEFAULT,
            double finishAngle = FINISH_ANGLE_DEFAULT,
            QSize iconSize = QSize(ICON_WIDTH_DEFAULT, ICON_HEIGHT_DEFAULT));

    [[nodiscard]] double getInnerRadius() const;

    void setInnerRadius(double v);

    [[nodiscard]] double getOuterRadius() const;

    void setOuterRadius(double v);

    [[nodiscard]] double getStartAngle() const;

    void setStartAngle(double v);

    [[nodiscard]] double getFinishAngle() const;

    void setFinishAngle(double v);

    [[nodiscard]] int getSelected() const;

    void setSelected(int v);

    [[nodiscard]] const QColor &getSelectedSectorBorder() const;

    void setSelectedSectorBorder(const QColor &v);

    [[nodiscard]] const QBrush &getSelectedSectorColor() const;

    void setSelectedSectorColor(const QBrush &v);

    [[nodiscard]] const QColor &getSectorBorder() const;

    void setSectorBorder(const QColor &v);

    [[nodiscard]] const QBrush &getSectorColor() const;

    void setSectorColor(const QBrush &v);

    [[nodiscard]] double getSectorDistance() const;

    void setSectorDistance(double v);

    [[nodiscard]] const QVector<SelectorRingItem*> &getData() const;

    void setData(const QVector<SelectorRingItem*> &v);

    [[nodiscard]] const QSize &getIconSize() const;

    void setIconSize(const QSize &v);

    bool show();

    void close();
};


#endif //GYROGLOVECPP_SELECTOR_RING_H
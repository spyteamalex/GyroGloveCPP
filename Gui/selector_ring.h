//
// Created by spyteamalex on 12.06.22.
//

#ifndef GYROGLOVECPP_SELECTOR_RING_H
#define GYROGLOVECPP_SELECTOR_RING_H


#include <QLabel>
#include "../Tools/my_math.h"
#include "../global.h"

class SelectorRing : public QWidget {
    Q_OBJECT


protected:
    void paintEvent(QPaintEvent *event) override;

public:
    SelectorRing(double innerRadius, double outerRadius, int sectorCount, int startAngle, int finishAngle,
                 QWidget *parent = nullptr);

private:

    double innerRadius;
    double outerRadius;
    int sectorCount;
    int startAngle;
    int finishAngle;
    int selected;

    QColor selectedSectorBorder = Qt::white;
    QBrush selectedSectorColor = Qt::white;
    QColor sectorBorder = Qt::white;
    QBrush sectorColor = Qt::black;
    int sectorBuf = 0;

    void drawSector(int i, QPainter &painter, bool isSelected);

public:

    [[nodiscard]] double getInnerRadius() const;

    void setInnerRadius(double v);

    [[nodiscard]] double getOuterRadius() const;

    void setOuterRadius(double v);

    [[nodiscard]] int getSectorCount() const;

    void setSectorCount(int v);

    [[nodiscard]] int getStartAngle() const;

    void setStartAngle(int v);

    [[nodiscard]] int getFinishAngle() const;

    void setFinishAngle(int v);

    [[nodiscard]] int getSelected() const;

    void setSelected(int v);

    [[nodiscard]] const QColor &getSectorBorderSelected() const;

    void setSectorBorderSelected(const QColor &v);

    [[nodiscard]] const QBrush &getSectorColorSelected() const;

    void setSectorColorSelected(const QBrush &v);

    [[nodiscard]] const QColor &getSectorBorder() const;

    void setSectorBorder(const QColor &v);

    [[nodiscard]] const QBrush &getSectorColor() const;

    void setSectorColor(const QBrush &v);

    [[nodiscard]] int getSectorDistance() const;

    void setSectorDistance(int v);

    void show();
};


#endif //GYROGLOVECPP_SELECTOR_RING_H
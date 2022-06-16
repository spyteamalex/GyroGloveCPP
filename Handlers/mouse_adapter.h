//
// Created by spyteamalex on 09.06.22.
//

#ifndef GYROGLOVECPP_MOUSE_ADAPTER_H
#define GYROGLOVECPP_MOUSE_ADAPTER_H

#include "../Tools/my_math.h"
#include "../Tools/mouse_mover.h"
#include "../Tools/quaternion.h"
#include "../Tools/decoder.h"
#include "../global.h"
#include "adapter.h"
#include "../Gui/selector_ring.h"
#include <cmath>
#include <QTimer>
#include <QStyle>
#include <QFile>
#include <QJsonDocument>
#include "../Tools/tools.h"
#include <QJsonObject>
#include <QJsonArray>


/**
 * https://askdev.ru/q/suschestvuet-li-algoritm-preobrazovaniya-kvaternionnyh-vrascheniy-v-uglovye-vrascheniya-eylera-112001/
 * https://www.desmos.com/calculator/ifss3bpxcd?embed
*/

class MouseAdapter: public QObject, public Adapter{
    Q_OBJECT
private:
    QTimer timer;
    enum State{
        None,
        Move,
        Drag,
        Scroll,
        SetVolume,
        AltTab,
        SelectAction
    };

    //Move constants
    static constexpr double xa_m = -939.68;
    static constexpr double ya_m = -939.68;
    static constexpr double xb_m = 2.285;
    static constexpr double yb_m = 2.285;

    //Scroll constants
    static constexpr double xa_s = -46.984;
    static constexpr double ya_s = -46.984;
    static constexpr double xb_s = 2.285;
    static constexpr double yb_s = 2.285;

    //Key constants
    static constexpr double xa_k = -0.3559;
    static constexpr double ya_k = -9.3968;
    static constexpr double xb_k = 1.65;
    static constexpr double yb_k = 2.285;
    static constexpr double xStep_k = -0.10;
    static constexpr double yStep_k = -0.10;

    double xDebt_m = 0, yDebt_m = 0;
    double xDebt_s = 0, yDebt_s = 0;
    double xDebt_k = 0, yDebt_k = 0;
    int lastXValue_k = 0;
    int lastYValue_k = 0;
    int getXSpeed(double v);
    int getYSpeed(double v);
    int getXScroll(double v);
    int getYScroll(double v);
    int getXKeySignal(double v);
    int getYKeySignal(double v);
    int getXStepDiff(double v);
    int getYStepDiff(double v);
    int getXStep(double v);
    int getYStep(double v);
    void drop();

    const Mouse &m;
    double lastX = 0, lastY = 0;
    SelectorRing *selector = nullptr;
    QVector<SelectorRingItem> menu1;
    QVector<SelectorRingItem> menu2;


    State state = None;

private slots:
    void loop();
public:
    MouseAdapter(const Mouse &m);

    ~MouseAdapter();

    void setAnglesByQuaternion(const Quaternion &q);

    void setAngles(double x, double y);

    void moveEvent(const Quaternion &quaternion) override;

    void clickEvent(int event, int count, int button) override;

    void parseConfig(const QString& file);
};


#endif //GYROGLOVECPP_MOUSE_ADAPTER_H

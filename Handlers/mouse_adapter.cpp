//
// Created by spyteamalex on 09.06.22.
//

#include "mouse_adapter.h"

#define prefix "MouseAdapter"

//https://www.flaticon.com/authors/pixel-perfect - иконки

int MouseAdapter::getXSpeed(double v) {
    double spd = sign(v) * xa_m * std::pow(std::abs(v), xb_m);
    xDebt_m += spd;
    int mv = (int)xDebt_m;
    xDebt_m -= (double)mv;
    return mv;
}

int MouseAdapter::getYSpeed(double v) {
    double spd = sign(v) * ya_m * std::pow(std::abs(v), yb_m);
    yDebt_m += spd;
    int mv = (int)yDebt_m;
    yDebt_m -= (double)mv;
    return mv;
}

int MouseAdapter::getXScroll(double v) {
    double spd = sign(v) * xa_s * std::pow(std::abs(v), xb_s);
    xDebt_s += spd;
    int mv = (int)xDebt_s;
    xDebt_s -= mv;
    return mv;
}

int MouseAdapter::getYScroll(double v) {
    double spd = sign(v) * ya_s * std::pow(std::abs(v), yb_s);
    yDebt_s += spd;
    int mv = (int)yDebt_s;
    yDebt_s -= mv;
    return mv;
}

int MouseAdapter::getXStepDiff(double v) {
    int steps = getXStep(v);
    int res = steps - lastXValue_k;
    lastXValue_k = steps;
    return res;
}

int MouseAdapter::getYStepDiff(double v) {
    int steps = getYStep(v);
    int res = steps - lastYValue_k;
    lastYValue_k = steps;
    return res;
}

int MouseAdapter::getXStep(double v) {
    return (int)(v / xStep_k);
}

int MouseAdapter::getYStep(double v) {
    return (int)(v / yStep_k);
}

int MouseAdapter::getXKeySignal(double v) {
    double spd = sign(v) * xa_k * std::pow(std::abs(v), xb_k);
    xDebt_k += spd;
    int mv = (int)xDebt_k;
    xDebt_k -= mv;
    return mv;
}

int MouseAdapter::getYKeySignal(double v) {
    double spd = sign(v) * ya_k * std::pow(std::abs(v), yb_k);
    yDebt_k += spd;
    int mv = (int)yDebt_k;
    yDebt_k -= mv;
    return mv;
}

void MouseAdapter::setAnglesByQuaternion(const Quaternion &q) {
    double res[3];
    q.quaternion2Euler(res, Quaternion::RotSeq::zxy);
    double x = res[0];
    double y = res[1];
    lastX = x;
    lastY = y;
}

void MouseAdapter::setAngles(double x, double y){
    lastX = x;
    lastY = y;
}

void MouseAdapter::drop(){
    xDebt_k = 0;
    xDebt_m = 0;
    xDebt_s = 0;
    yDebt_k = 0;
    yDebt_m = 0;
    yDebt_s = 0;
    lastXValue_k = 0;
    lastYValue_k = 0;
    delete selector;
    selector = nullptr;
}

void MouseAdapter::loop() {
    switch(state){
        case Scroll:
            m.scroll(getXScroll(lastX), getYScroll(lastY));
            break;
        case Drag:
        case Move:
            m.move(getXSpeed(lastX), getYSpeed(lastY));
            break;
        case AltTab: {
            int v = getXStepDiff(lastX);
            for(int i = 0; i < abs(v); i++){
                if(v > 0){
                    m.click(Mouse::TAB);
                }else{
                    m.click({Mouse::SHIFT, Mouse::TAB});
                }
            }
            break;
        }
        case SetVolume:{
            int v = getXStepDiff(lastX);
            for(int i = 0; i < abs(v); i++){
                if(v > 0){
                    m.click(Mouse::VOLUME_UP);
                }else{
                    m.click(Mouse::VOLUME_DOWN);
                }
            }
            break;
        }
        case SelectAction: {
            int v = getXStep(lastX);
            v = mod(-v, selector->getData().count());
            selector->setSelected(v);
            break;
        }
    }
}

MouseAdapter::MouseAdapter(const Mouse& m) : m(m) {
    connect(&timer, &QTimer::timeout, this, &MouseAdapter::loop);
    timer.setInterval(10);
    timer.start();
}

MouseAdapter::~MouseAdapter(){
    delete selector;
}

void MouseAdapter::moveEvent(const Quaternion &q) {
    setAnglesByQuaternion(q);
//    logln(prefix,
//            "move " + tos(q.getWidth()) + " " + tos(q.getX()) + " " + tos(q.getY()) + " " +
//            tos(q.getZ()));
}

#define __ 0)||(true
#define CASE(ev, cnt, btn) if((event == (ev)) && (count == (cnt)) && (button == (btn)))
void MouseAdapter::clickEvent(int event, int count, int button) {
    CASE(EV_RELEASE, __, __) {
        state = None;
    }
    CASE(EV_PRESS, __, __) {
        if(state != None){
            return;
        }
        drop();
    }
    logln(prefix, tos(event)+ " " +tos(count)+" " + tos(button));

    CASE(EV_PRESS, 1, ID_A) {
        state = Move;
    }
    CASE(EV_RELEASE, 1, ID_A) {
        setAngles(0, 0);
    }

    CASE(EV_PRESS, 2, ID_A){
        state = Drag;
        m.setKey(Mouse::LEFT, true);
    }
    CASE(EV_RELEASE, 2, ID_A){
        setAngles(0, 0);
        m.setKey(Mouse::LEFT, false);
    }

    CASE(EV_PRESS, 3, ID_A){
        state = SetVolume;
    }
    CASE(EV_RELEASE, 3, ID_A){}

    CASE(EV_PRESS, 1, ID_B){
        state = Scroll;
    }
    CASE(EV_RELEASE, 1, ID_B){
        setAngles(0, 0);
    }

    CASE(EV_PRESS, 2, ID_B) {
        state = AltTab;
        m.setKey(Mouse::ALT, true);

        m.click({Mouse::SHIFT, Mouse::TAB});
        m.click(Mouse::TAB);
    }
    CASE(EV_RELEASE, 2, ID_B) {
        m.setKey(Mouse::ALT, false);
    }

    CASE(EV_PRESS, 3, ID_B) {
        state = SelectAction;
        //todo переписать в конфиг
        selector = new SelectorRing(225,335,-90,270,QSize(80,80));
        selector->show();
    }
    CASE(EV_RELEASE, 3, ID_B) {
        //todo сделать выполнение
        println(prefix, selector->getSelected());
        selector->close();
    }

    CASE(EV_CLICK, 1, ID_A){
        m.click(Mouse::LEFT);
    }

    CASE(EV_CLICK, 2, ID_A){
        m.click(Mouse::RIGHT);
    }

    CASE(EV_CLICK, 3, ID_A){
        m.click(Mouse::MIDDLE);
    }

    CASE(EV_CLICK, 1, ID_B){
        m.click(Mouse::PLAY_PAUSE);
    }
}
#undef check
#undef __

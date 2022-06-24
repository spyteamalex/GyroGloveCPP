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

int MouseAdapter::getXStep(double v) const {
    return (int)(v / dx_sel);
}

int MouseAdapter::getYStep(double v) const {
    return (int)(v / dy_sel);
}

//int MouseAdapter::getXKeySignal(double v) {
//    double spd = sign(v) * xa_k * std::pow(std::abs(v), xb_k);
//    xDebt_k += spd;
//    int mv = (int)xDebt_k;
//    xDebt_k -= mv;
//    return mv;
//}
//
//int MouseAdapter::getYKeySignal(double v) {
//    double spd = sign(v) * ya_k * std::pow(std::abs(v), yb_k);
//    yDebt_k += spd;
//    int mv = (int)yDebt_k;
//    yDebt_k -= mv;
//    return mv;
//}

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
//    xDebt_k = 0;
    xDebt_m = 0;
    xDebt_s = 0;
//    yDebt_k = 0;
    yDebt_m = 0;
    yDebt_s = 0;
    lastXValue_k = 0;
    lastYValue_k = 0;
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
            if(selector->getData().count() > 0) {
                int v = getXStep(lastX);
                v = mod(-v, selector->getData().count());
                selector->setSelected(v);
            }
            break;
        }
    }
}

QColor parseColor(const QString& s, const QColor& def = Qt::transparent){
    {
        QRegExp re;
        re.setPattern("^#?([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})$");
        if (re.exactMatch(s)){
            auto grps = re.capturedTexts();
            return {grps[1].toInt(nullptr, 16),grps[2].toInt(nullptr, 16),grps[3].toInt(nullptr, 16)};
        }
    }
    {
        QRegExp re;
        re.setPattern("^#?([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])$");
        if (re.exactMatch(s)){
            auto grps = re.capturedTexts();
            return {grps[1].toInt(nullptr, 16),grps[2].toInt(nullptr, 16),grps[3].toInt(nullptr, 16)};
        }
    }
    {
        QRegExp re;
        re.setPattern("^#?([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})$");
        if (re.exactMatch(s)){
            auto grps = re.capturedTexts();
            return {grps[2].toInt(nullptr, 16),grps[3].toInt(nullptr, 16),grps[4].toInt(nullptr, 16),grps[1].toInt(nullptr, 16),};
        }
    }
    {
        QRegExp re;
        re.setPattern("^#?([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])$");
        if (re.exactMatch(s)){
            auto grps = re.capturedTexts();
            return {grps[2].toInt(nullptr, 16),grps[3].toInt(nullptr, 16),grps[4].toInt(nullptr, 16),grps[1].toInt(nullptr, 16),};
        }
    }
    return def;
}

void MouseAdapter::initFromConfig(const QString& f){
    menu1.clear();
    menu2.clear();
    QString val;
    QFile file(f);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    if(!d.isObject()) return;
    QJsonObject dObject = d.object();
    std::string user = exec("echo -n $USER");
    if(user == "root"){
        user = exec("echo -n $SUDO_USER");
    }

    {
        QJsonArray m1 = dObject["menu1"].toArray();
        for (QJsonValueRef i: m1) {
            if (!i.isObject()) continue;
            QJsonObject item = i.toObject();

            std::string cmd = item["command"].toString("").toStdString();
            menu1.append(new SelectorRingItem(this, QIcon(item["icon"].toString("")), [cmd, user]() {
                if (!cmd.empty()) {
                    exec("sudo -u " + user + " " + cmd + " & ");
                }
            }));
        }
    }

    {
        QJsonArray m2 = dObject["menu2"].toArray();
        for (QJsonValueRef i: m2) {
            if (!i.isObject()) continue;
            QJsonObject item = i.toObject();

            std::string cmd = item["command"].toString("").toStdString();
            menu2.append(new SelectorRingItem(this, QIcon(item["icon"].toString("")), [cmd, user]() {
                if (!cmd.empty())
                    exec("sudo -u " + user + " " + cmd + " & ");
            }));
        }
    }

    {
        QJsonObject obj = dObject["input_constants"].toObject();
        xa_m = obj["xa_m"].toDouble(XA_M_DEFAULT);
        ya_m = obj["ya_m"].toDouble(YA_M_DEFAULT);
        xb_m = obj["xb_m"].toDouble(XB_M_DEFAULT);
        yb_m = obj["yb_m"].toDouble(YB_M_DEFAULT);

        xa_s = obj["xa_s"].toDouble(XA_S_DEFAULT);
        ya_s = obj["ya_s"].toDouble(YA_S_DEFAULT);
        xb_s = obj["xb_s"].toDouble(XB_S_DEFAULT);
        yb_s = obj["yb_s"].toDouble(YB_S_DEFAULT);

        dx_sel = obj["dx_sel"].toDouble(DX_SEL_DEFAULT);
        dy_sel = obj["dy_sel"].toDouble(DY_SEL_DEFAULT);
    }

    {
        QJsonObject obj = dObject["style_constants"].toObject();
        selector = new SelectorRing();

        selector->setSectorBorder(parseColor(obj["sector_border"].toString(""), SECTOR_BORDER_DEFAULT));
        selector->setSelectedSectorBorder(parseColor(obj["selected_sector_border"].toString(""), SELECTED_SECTOR_BORDER_DEFAULT));
        selector->setSectorColor(parseColor(obj["sector_color"].toString(""), SECTOR_COLOR_DEFAULT));
        selector->setSelectedSectorColor(parseColor(obj["selected_sector_color"].toString(""), SELECTED_SECTOR_COLOR_DEFAULT));

        selector->setSectorDistance(obj["sector_distance"].toDouble(SECTOR_DISTANCE_DEFAULT));
        selector->setInnerRadius(obj["inner_radius"].toDouble(INNER_RADIUS_DEFAULT));
        selector->setOuterRadius(obj["outer_radius"].toDouble(OUTER_RADIUS_DEFAULT));
        selector->setStartAngle(obj["start_angle"].toDouble(START_ANGLE_DEFAULT));
        selector->setFinishAngle(obj["finish_angle"].toDouble(FINISH_ANGLE_DEFAULT));
        selector->setIconSize(QSize(obj["icon_width"].toInt(ICON_WIDTH_DEFAULT), obj["icon_height"].toInt(ICON_HEIGHT_DEFAULT)));
    }
}

MouseAdapter::MouseAdapter(QObject * parent, const Mouse& m) : m(m), QObject(parent) {

    initFromConfig(CONFIG);

    connect(&timer, &QTimer::timeout, this, &MouseAdapter::loop);
    timer.setInterval(10);
    timer.start();
}

MouseAdapter::~MouseAdapter(){
    timer.stop();
    delete selector;
    qDeleteAll(menu1);
    qDeleteAll(menu2);
}

void MouseAdapter::moveEvent(const Quaternion &q) {
    setAnglesByQuaternion(q);
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
        selector->setData(menu1);
        selector->show();
    }

    CASE(EV_RELEASE, 3, ID_B) {
        if(menu1.size() > selector->getSelected())
            menu1[selector->getSelected()]->getAction()();
        selector->close();
    }

    CASE(EV_PRESS, 4, ID_B) {
        state = SelectAction;
        selector->setData(menu2);
        selector->show();
    }

    CASE(EV_RELEASE, 4, ID_B) {
        if(menu2.size() > selector->getSelected())
            menu2[selector->getSelected()]->getAction()();
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

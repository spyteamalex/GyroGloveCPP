#include "mouse_mover.h"

#include "global.h"

#define prefix "mouse mover"

void emit(int fd, int type, int code, int value) {
    struct input_event ev;
    memset(&ev, 0, sizeof(struct input_event));
    ev.type = type;
    ev.code = code;
    ev.value = value;
    if (write(fd, &ev, sizeof(struct input_event)) < 0)
        errorln(prefix, "error: write");
}

Mouse::Mouse() {
    fd = open("/dev/input/uinput", O_WRONLY | O_NONBLOCK);
    if(fd < 0)
        fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);

    if(fd < 0)
        errorln(prefix, "error: open \"/dev/input/uinput\" and \"/dev/uinput\"");

    if(ioctl(fd, UI_SET_EVBIT, EV_KEY) < 0)
        errorln(prefix, "error: ioctl(fd, UI_SET_EVBIT, EV_KEY)");
    if(ioctl(fd, UI_SET_KEYBIT, BTN_LEFT) < 0)
        errorln(prefix, "error: ioctl(fd, UI_SET_KEYBIT, BTN_LEFT)");

    if(ioctl(fd, UI_SET_EVBIT, EV_REL) < 0)
        errorln(prefix, "error: ioctl(fd, UI_SET_EVBIT, EV_REL)");
    if(ioctl(fd, UI_SET_RELBIT, REL_X) < 0)
        errorln(prefix, "error: ioctl(fd, UI_SET_RELBIT, REL_X)");
    if(ioctl(fd, UI_SET_RELBIT, REL_Y) < 0)
        errorln(prefix, "error: ioctl(fd, UI_SET_RELBIT, REL_Y)");

    memset(&uidev, 0, sizeof(uidev));
    strcpy(uidev.name, "GloveMouse");
//    snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "uinput-sample");
    uidev.id.bustype = BUS_USB;
    uidev.id.vendor  = 0x1;
    uidev.id.product = 0x1;
    uidev.id.version = 1;

    if(write(fd, &uidev, sizeof(uidev)) < 0)
        errorln(prefix, "error: write &uidev");

    if(ioctl(fd, UI_DEV_CREATE) < 0)
        errorln(prefix, "error: ioctl UI_DEV_CREATE");
}

Mouse::~Mouse(){
    if(ioctl(fd, UI_DEV_DESTROY) < 0)
        errorln(prefix, "error: ioctl UI_DEV_DESTROY");
    close(fd);
}

void Mouse::move(int dx, int dy) {
    emit(fd, EV_REL, REL_X, dx);
    emit(fd, EV_REL, REL_Y, dy);
    emit(fd, EV_SYN, SYN_REPORT, 0);
}
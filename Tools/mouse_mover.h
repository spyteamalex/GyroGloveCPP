//
// Created by spyteamalex on 09.06.22.
//

#ifndef GYROGLOVECPP_MOUSE_MOVER_H
#define GYROGLOVECPP_MOUSE_MOVER_H

#include <linux/uinput.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <cerrno>
#include <linux/input.h>
#include <linux/uinput.h>
#include <initializer_list>

/**
 * https://www.unknowncheats.me/forum/counterstrike-global-offensive/204642-tutorial-simulating-hardware-mouse-event-linux.html
 * https://www.kernel.org/doc/html/v4.12/input/uinput.html
*/

class Mouse{
public:
    enum Keys{
        LEFT = BTN_LEFT,
        RIGHT = BTN_RIGHT,
        MIDDLE = BTN_MIDDLE,
        PLAY_PAUSE = KEY_PLAYPAUSE,
        TAB = KEY_TAB,
        SHIFT = KEY_LEFTSHIFT,
        ALT = KEY_LEFTALT,
        VOLUME_UP = KEY_VOLUMEUP,
        VOLUME_DOWN = KEY_VOLUMEDOWN,
        META = KEY_LEFTMETA
    };

    Mouse();
    ~Mouse();
    void move(int dx, int dy) const;
    void setKey(Keys key, bool state) const;
    void scroll(int dx, int dy) const;
    void click(Keys key) const;
    void click(std::initializer_list<Keys> list) const;

private:
    int fd;
    struct uinput_user_dev uidev;

};


#endif //GYROGLOVECPP_MOUSE_MOVER_H

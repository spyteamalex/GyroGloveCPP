//
// Created by spyteamalex on 09.06.22.
//

#ifndef GLOVEMOUSECPP_MOUSE_MOVER_H
#define GLOVEMOUSECPP_MOUSE_MOVER_H

#include <linux/uinput.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <cerrno>
#include <linux/input.h>
#include <linux/uinput.h>

/**
 * https://www.unknowncheats.me/forum/counterstrike-global-offensive/204642-tutorial-simulating-hardware-mouse-event-linux.html
 * https://www.kernel.org/doc/html/v4.12/input/uinput.html
*/

class Mouse{
public:
    static const int LEFT = BTN_LEFT;
    static const int RIGHT = BTN_RIGHT;
    static const int MIDDLE = BTN_MIDDLE;

    Mouse();
    ~Mouse();
    void move(int dx, int dy);
    void key(int key, bool state);
    void scroll(int dx, int dy);

private:
    int fd;
    struct uinput_user_dev uidev;

};


#endif //GLOVEMOUSECPP_MOUSE_MOVER_H

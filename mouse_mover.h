//
// Created by spyteamalex on 09.06.22.
//

#ifndef GLOVEMOUSECPP_MOUSE_MOVER_H
#define GLOVEMOUSECPP_MOUSE_MOVER_H

#include <linux/uinput.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <linux/uinput.h>

/**
 * https://www.unknowncheats.me/forum/counterstrike-global-offensive/204642-tutorial-simulating-hardware-mouse-event-linux.html
 * https://www.kernel.org/doc/html/v4.12/input/uinput.html
*/

class Mouse{
public:
    Mouse();
    ~Mouse();
    void move(int dx, int dy);

private:
    int fd;
    struct uinput_user_dev uidev;
};


#endif //GLOVEMOUSECPP_MOUSE_MOVER_H

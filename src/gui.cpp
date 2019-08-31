//built from *http://math.msu.su/~vvb/2course/Borisenko/CppProjects/GWindow/xintro.html*
#include "../hdr/gui.h"

Gui::Gui() {init_x();}
Gui::~Gui() {close_x();}

void Gui::init_x()
{
    // black and white, cause this is tutorial copy mainly. Further details in section apparently.
    unsigned long black, white;
    
    // Info from DISPLAY variable to create X connection.
    dis     =   XOpenDisplay((char *)0);
    screen  =   DefaultScreen(dis);
    black   =   BlackPixel(dis, screen); // black color
    white   =   WhitePixel(dis, screen); // white color
    
    // With display initialized, create window. 200 by 300 pixels across and down. foreground white
    // backgroound black
    win     =   XCreateSimpleWindow( dis, DefaultRootWindow(dis), 0, 0, 
                    200, 300, 5, white, black );
    
    // set window properties. 3rd & 4th items indicate name at top and minimized window.
    XSetStandardProperties(dis, win, "My window", "HI!", None, NULL, 0, NULL);

    // determine allowed input. details in section
    XSelectInput(dis, win, ExposureMask|ButtonPressMask|KeyPressMask);

    // graphics context
    gc      =   XCreateGC(dis, win, 0, 0);
    
    // Another routine, set fore- and background colors _currently_ in use in window
    XSetBackground(dis, gc, white);
    XSetForeground(dis, gc, black);

    // Clear window and bring to top of other windows. 
    XClearWindow(dis, win);
    XMapRaised(dis, win);
    
} // !init_x

void Gui::close_x()
{
    // good practice to return system resources once closed. 
    XFreeGC(dis, gc);
    XDestroyWindow(dis, win);
    XCloseDisplay(dis),
    _exit(1);
} // !close_x

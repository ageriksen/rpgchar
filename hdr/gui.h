
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

class Gui
{
public:
    Gui();
    ~Gui();
    
    void init_x();
    void close_x();
private:
    Display *dis;
    int screen;
    Window win;
    GC gc;
};// !Gui

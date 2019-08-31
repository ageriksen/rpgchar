#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/utsname.h>

int main(int argc, char **argv)
{
Display *dspl = XOpenDisplay(NULL);
if ( dspl == NULL )
{
    fprintf(stderr, "Cannot open display\n");
    exit(1);
}
int screen = DefaultScreen(dspl);
Window win = XCreateSimpleWindow(dspl, RootWindow(dspl, screen), 10, 10, 660, 200, 1,
                BlackPixel(dspl, screen), WhitePixel(dspl, screen));
XSelectInput(dspl, win, ExposureMask | KeyPressMask);
XMapWindow(dspl, win);

XStoreName(dspl, win, "X11 window");

Atom WM_DELETE_WINDOW = XInternAtom(dspl, "WM_DELETE_WINDOW", False);
XSetWMProtocols(dspl, win, &WM_DELETE_WINDOW, 1);


bool uname_ok = false;

struct utsname sname;
int ret = uname(&sname);
if ( ret != -1 ) uname_ok = true;

XEvent e;

while (1)
{
XNextEvent(dspl, &e);
if (e.type == Expose) 
{
int y_offset = 20;

const char *s1 = "X11 test app";
XDrawString(dspl, win, DefaultGC(dspl, screen), 10, y_offset, s1, strlen(s1));
y_offset += 20;
const char *s2 = "boop!";
XDrawString(dspl, win, DefaultGC(dspl, screen), 10, y_offset, s2, strlen(s2));
y_offset += 20;

if (uname_ok) 
{
char buf[256] = {0};

sprintf(buf, "system informatio:");
XDrawString(dspl, win, DefaultGC(dspl, screen), 10, y_offset, buf, strlen(buf));
y_offset += 15;

sprintf(buf, "- system: %s", sname.sysname);
XDrawString(dspl, win, DefaultGC(dspl, screen), 10, y_offset, buf, strlen(buf));
y_offset += 15;

sprintf(buf, "- Release: %s", sname.release);
XDrawString(dspl, win, DefaultGC(dspl, screen), 10, y_offset, buf, strlen(buf));
y_offset += 15;

sprintf(buf, "- Version: %s", sname.version);
XDrawString(dspl, win, DefaultGC(dspl, screen), 10, y_offset, buf, strlen(buf));
y_offset += 15;

sprintf(buf, "- Machine: %s", sname.machine);
XDrawString(dspl, win, DefaultGC(dspl, screen), 10, y_offset, buf, strlen(buf));
y_offset += 20;
} // !uname_ok

XWindowAttributes winattr;
XGetWindowAttributes(dspl, win, &winattr);
int width = winattr.width;
int height = winattr.height;
char buf[128]  = {0};
sprintf(buf, "Current window size: %dx%d", width, height);
XDrawString(dspl, win, DefaultGC(dspl, screen), 10, y_offset, buf, strlen(buf));
y_offset += 20;
}// !if e.type == Expose

if (e.type == KeyPress) 
{
char buf[128] = {0};
KeySym keysym;
int Len = XLookupString(&e.xkey, buf, sizeof buf, &keysym, NULL);
if (keysym == XK_Escape) break;
} // !e.type == KeyPress

if ((e.type == ClientMessage) &&
    (static_cast<unsigned int>(e.xclient.data.l[0]) == WM_DELETE_WINDOW))
{
break;
} // !e.type == ClienMessage && e.xclient.data == WM_DELETE_WINDOW

} // !(1)

//GC gc;
XDestroyWindow(dspl, win); 
XCloseDisplay(dspl);
return 0;
} // !main

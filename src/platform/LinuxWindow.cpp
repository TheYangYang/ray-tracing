#ifdef __linux__
#include "platform/LinuxWindow.h"

LinuxWindow::LinuxWindow(uint32_t width, uint32_t height, const std::wstring &title, platform::Platform platform)
    :platform::Window(width, height, title, platform)
{
    display = XOpenDisplay(nullptr);
    if(display == nullptr)
    {
        std::cerr << "Failed to open X display\n";
        return;
    }

    screen = DefaultScreen(display);

    window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        100, 100,
        width, height,
        1,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    XSelectInput(display, window, ExposureMask | KeyPressMask);

    XMapWindow(display, window);

}

void LinuxWindow::Run()
{
    while (running)
    {
        XNextEvent(display, &event);

        switch (event.type)
        {
        case Expose:
            XFillRectangle(display, window, DefaultGC(display, screen), 20, 20, 100, 100);
            break;
        case KeyPress:
            running = false;
            break;
        }
    }
    
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}

#endif
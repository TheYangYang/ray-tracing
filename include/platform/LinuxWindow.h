#ifdef __linux__
#include "pch.h"
#include "Window.h"

class LinuxWindow: public platform::Window
{
public:
    LinuxWindow(uint32_t width, uint32_t height, const std::wstring &title, platform::Platform platform);
    void Run() override;
private:
    bool running = true;
    Display* display;
    ::Window window;
    XEvent event;
    int screen;
};

#endif
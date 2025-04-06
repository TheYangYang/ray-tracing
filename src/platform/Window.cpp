#include "platform/Window.h"

Window::Window(uint32_t width, uint32_t height, const std::wstring &title, Platform platform)
    : specification({width, height, title}), platform(platform)
{
}
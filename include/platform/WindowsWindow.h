#pragma once
#ifdef _WIN32
#include "Window.h"
#include "Canvas.h"

class WindowsWindow : public platform::Window
{
public:
    WindowsWindow(uint32_t width, uint32_t height, const std::wstring &title, platform::Platform platform);
    void Run() override;

private:
    HWND hwnd;
    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    std::vector<uint8_t> pixelData; 
    void BlitToWindow(HDC hdc);
};

#endif

#ifdef _WIN32
#include "platform/WindowsWindow.h"

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;
const std::wstring TITLE = L"Ray-Tracing";

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int)
{
    std::unique_ptr<Window> window = std::make_unique<WindowsWindow>(WIDTH, HEIGHT, TITLE, Platform::WINDOWS);
    window->Run();
    return 0;
}
#endif
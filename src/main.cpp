#ifdef _WIN32
#include "platform/WindowsWindow.h"
#elif __linux__
#include "platform/LinuxWindow.h"
#endif

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;
const std::wstring TITLE = L"Ray-Tracing";

#ifdef _WIN32
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int)
{
    Scope<platform::Window> window = SCOPE(WindowsWindow, WIDTH, HEIGHT, TITLE, platform::Platform::WINDOWS);
    window->Run();
    return 0;
}
#else
int main()
{
#ifdef __linux__
    Scope<platform::Window> window = SCOPE(LinuxWindow, WIDTH, HEIGHT, TITLE, platform::Platform::LINUX);
    window->Run();
#elif __APPLE__
#endif
    return 0;
}
#endif
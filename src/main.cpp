
#ifdef _WIN32
#include "platform/WindowsWindow.h"
constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;
const std::wstring TITLE = L"Ray-Tracing";

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int)
{
    Scope<platform::Window> window = SCOPE(WindowsWindow, WIDTH, HEIGHT, TITLE, platform::Platform::WINDOWS);
    window->Run();
    return 0;
}
#elif __linux__
#include "platform/LinuxWindow.h"

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;
const std::wstring TITLE = L"Ray-Tracing";

int main()
{
    Scope<platform::Window> window = SCOPE(LinuxWindow, WIDTH, HEIGHT, TITLE, platform::Platform::LINUX);
    window->Run(); 

    return 0;
}

#endif
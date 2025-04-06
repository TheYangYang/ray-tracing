// #include "Canvas.h"
// #include "math/Vector3.h"
// #include "WindowsWindow.h"

// constexpr uint32_t CANVAS_WIDTH = 256;
// constexpr uint32_t CANVAS_HEIGHT = 256;

// int main()
// {
//     // Camera Camera;
//     // auto &canvas = Canvas::GetInstance(CANVAS_WIDTH, CANVAS_HEIGHT, Camera);
//     // canvas.Draw();
    
//     return 0;
// }

#ifdef _WIN32
#include "platform/WindowsWindow.h"
constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;
const std::wstring TITLE = L"Ray-Tracing";


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int) {

    std::unique_ptr<Window> window(new WindowsWindow(WIDTH, HEIGHT, TITLE, Platform::WINDOWS));
    window->Run();
    return 0;
}
#endif
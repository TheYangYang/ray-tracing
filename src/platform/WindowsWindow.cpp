#ifdef _WIN32
#include "platform/WindowsWindow.h"

WindowsWindow::WindowsWindow(uint32_t width, uint32_t height, const std::wstring &title, platform::Platform platform)
    : Window(width, height, title, platform), pixelData(width * height * RGBA_NUM)
{
    Canvas::GetInstance().Initialize(width, height, Camera());
    const wchar_t CLASS_NAME[] = L"MyWindowClass";
    WNDCLASS wc = {};
    wc.lpfnWndProc = [](HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT
    {
        WindowsWindow *window = reinterpret_cast<WindowsWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        if (window)
        {
            return window->WindowProc(hwnd, msg, wParam, lParam);
        }
        return DefWindowProc(hwnd, msg, wParam, lParam);
    };
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    std::wstring wtitle(title.begin(), title.end());

    hwnd = CreateWindowEx(
        0, CLASS_NAME, wtitle.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        nullptr, nullptr, GetModuleHandle(nullptr), nullptr);

    SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

    ShowWindow(hwnd, SW_SHOWDEFAULT);
}

void WindowsWindow::Run()
{
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT WindowsWindow::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_DESTROY)
    {
        PostQuitMessage(0);
        return 0;
    }
    else if (msg == WM_PAINT)
    {
        // Handle drawing on the window
        HDC hdc = GetDC(hwnd); 

        // Render the scene
        auto& canvas = Canvas::GetInstance();
        canvas.Draw(pixelData);

        // Blit pixel data to the window
        BlitToWindow(hdc);

        ReleaseDC(hwnd, hdc); 
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void WindowsWindow::BlitToWindow(HDC hdc)
{
    BITMAPINFO bmi = {};
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = specification.width;
    bmi.bmiHeader.biHeight = -static_cast<int>(specification.height);
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    SetDIBitsToDevice(hdc, 0, 0, specification.width, specification.height, 0, 0, 0, specification.height, pixelData.data(), &bmi, DIB_RGB_COLORS);
}

#endif


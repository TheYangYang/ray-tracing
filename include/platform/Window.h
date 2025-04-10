#pragma once
#include "pch.h"

namespace platform
{
    enum class Platform : uint8_t
    {
        WINDOWS,
        LINUX,
        MACOS
    };
    
    struct WindowSpecification
    {
        uint32_t width;
        uint32_t height;
        std::wstring title;
    };
    
    class Window
    {
    public:
        Window() = delete;
        Window(uint32_t width, uint32_t height, const std::wstring &title, Platform platform);
        virtual ~Window() = default;
        virtual void Run() = 0;
    protected:
        Platform platform;
        WindowSpecification specification;
        
    };
}

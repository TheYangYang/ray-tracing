#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <execution>
#include <numeric>

#ifdef _WIN32
#ifndef UNICODE
#define UNICODE
#endif 
#include <windows.h>
#elif __linux__
#include <X11/Xlib.h>
#include <cstdint>
#endif

#include "math/Vector3.h"
#include "math/Formula.h"

#define RGBA_NUM 4

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385;

inline float degreesToRadians(float degrees) {
    return degrees * pi / 180.0;
}

template <typename T>
using Ref = std::shared_ptr<T>;

template <typename T>
using Scope = std::unique_ptr<T>;

template <typename T, typename... Args>
Ref<T> CreateRef(Args &&...args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
Scope<T> CreateScope(Args &&...args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

#define REF(type, ...) CreateRef<type>(__VA_ARGS__)
#define SCOPE(type, ...) CreateScope<type>(__VA_ARGS__)

#define REF_AS(Base, Derived, ...) std::static_pointer_cast<Base>(REF(Derived, __VA_ARGS__))
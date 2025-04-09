#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <execution>
#include <numeric>

#include "math/Utils.h"
#include "math/Vector3.h"

#define RGBA_NUM 4

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
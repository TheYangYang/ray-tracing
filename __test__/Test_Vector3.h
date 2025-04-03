#pragma once
#include "math/Vector3.h"
#include "math/Utils.h"
#include <iostream>

template <typename T>
bool Equal(T a, T b, T epsilon = static_cast<T>(1e-5))
{
    return std::abs(a - b) < epsilon;
}

#define ASSERT_TRUE(condition, message)                                                                  \
    if (!(condition))                                                                                    \
    {                                                                                                    \
        std::cerr << "Test failed: " << message << "(Line " << __LINE__ << " File " << __FILE__ << "\n"; \
        exit(EXIT_FAILURE);                                                                              \
    }

#define RUN_TEST(testFunc)                                  \
    std::cout << "Running Tests " << #testFunc << "......"; \
    testFunc();                                             \
    std::cout << "PASSED\n";

template <typename T>
void TestConstructor()
{
    // Test Vector3<T>()
    math::Vector3<T> v;
    ASSERT_TRUE(Equal(v.x, static_cast<T>(0)), "Constructor: x component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v.y, static_cast<T>(0)), "Constructor: y component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v.z, static_cast<T>(0)), "Constructor: z component in vec3 is incorrect.");

    // Test Vector3<T>(value);
    math::Vector3<T> v1(static_cast<T>(1));
    ASSERT_TRUE(Equal(v1.x, static_cast<T>(1)), "Constructor: x component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v1.y, static_cast<T>(1)), "Constructor: y component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v1.z, static_cast<T>(1)), "Constructor: z component in vec3 is incorrect.");

    // Test Vector3<T>(x, y, z);
    math::Vector3<T> v2(static_cast<T>(1), static_cast<T>(2), static_cast<T>(3));
    ASSERT_TRUE(Equal(v2.x, static_cast<T>(1)), "Constructor: x component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v2.y, static_cast<T>(2)), "Constructor: y component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v2.z, static_cast<T>(3)), "Constructor: z component in vec3 is incorrect.");
}

template <typename T>
void TestNegate()
{
    math::Vector3<T> a(static_cast<T>(1), static_cast<T>(2), static_cast<T>(3));
    a = -a;
    ASSERT_TRUE(Equal(a.x, static_cast<T>(-1)), "Negate: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<T>(-2)), "Negate +: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<T>(-3)), "Negate +: z component is incorrect");
}

// Test addition +
template <typename T>
void TestAddition()
{
    math::Vector3<T> a(static_cast<T>(1), static_cast<T>(2), static_cast<T>(3));
    math::Vector3<T> b(static_cast<T>(4), static_cast<T>(5), static_cast<T>(6));
    math::Vector3<T> result = a + b;

    ASSERT_TRUE(Equal(result.x, static_cast<T>(5)), "Addition +: x component is incorrect");
    ASSERT_TRUE(Equal(result.y, static_cast<T>(7)), "Addition +: y component is incorrect");
    ASSERT_TRUE(Equal(result.z, static_cast<T>(9)), "Addition +: z component is incorrect");

    a += b;
    ASSERT_TRUE(Equal(a.x, static_cast<T>(5)), "Addition +=: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<T>(7)), "Addition +=: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<T>(9)), "Addition +=: z component is incorrect");
}

template <typename T>
void TestSubstract()
{
    math::Vector3<T> a(static_cast<T>(1), static_cast<T>(2), static_cast<T>(3));
    math::Vector3<T> b(static_cast<T>(4), static_cast<T>(5), static_cast<T>(6));
    math::Vector3<T> result = a - b;

    ASSERT_TRUE(Equal(result.x, static_cast<T>(-3)), "Substract -: x component is incorrect");
    ASSERT_TRUE(Equal(result.y, static_cast<T>(-3)), "Substract -: y component is incorrect");
    ASSERT_TRUE(Equal(result.z, static_cast<T>(-3)), "Substract -: z component is incorrect");

    a -= b;
    ASSERT_TRUE(Equal(a.x, static_cast<T>(-3)), "Substract -=: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<T>(-3)), "Substract -=: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<T>(-3)), "Substract -=: z component is incorrect");
}

template <typename T>
void TestDivide()
{
    math::Vector3<T> a(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));
    math::Vector3<T> result = a / static_cast<T>(2);

    ASSERT_TRUE(Equal(result.x, static_cast<T>(0.5)), "Divide /: x component is incorrect");
    ASSERT_TRUE(Equal(result.y, static_cast<T>(0.5)), "Divide /: y component is incorrect");
    ASSERT_TRUE(Equal(result.z, static_cast<T>(0.5)), "Divide /: z component is incorrect");

    a /= 2.0f;
    ASSERT_TRUE(Equal(a.x, static_cast<T>(0.5)), "Divide /=: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<T>(0.5)), "Divide /=: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<T>(0.5)), "Divide /=: z component is incorrect");
}

template <typename T>
void TestMultiply()
{
    math::Vector3<T> a(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));
    math::Vector3<T> result = a * static_cast<T>(2);

    ASSERT_TRUE(Equal(result.x, static_cast<T>(2)), "Multiply *: x component is incorrect");
    ASSERT_TRUE(Equal(result.y, static_cast<T>(2)), "Multiply *: y component is incorrect");
    ASSERT_TRUE(Equal(result.z, static_cast<T>(2)), "Multiply *: z component is incorrect");

    a *= 2.0f;
    ASSERT_TRUE(Equal(a.x, static_cast<T>(2)), "Multiply *=: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<T>(2)), "Multiply *=: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<T>(2)), "Multiply *=: z component is incorrect");
}

template <typename T>
void TestDotProduct()
{
    math::Vector3<T> a(static_cast<T>(1), static_cast<T>(2), static_cast<T>(3));
    math::Vector3<T> b(static_cast<T>(4), static_cast<T>(5), static_cast<T>(6));
    T result = math::dot(a, b);

    ASSERT_TRUE(Equal(result, static_cast<T>(32)), "Dot Product is incorrect");
}

template <typename T>
void TestCrossProduct()
{
    math::Vector3<T> a(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
    math::Vector3<T> b(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
    math::Vector3<T> result = math::cross(a, b);

    ASSERT_TRUE(Equal(result.x, static_cast<T>(0)) && Equal(result.y, static_cast<T>(0)) && Equal(result.z, static_cast<T>(1)),
                "Cross product failed: expected (0, 0, 1)");
}

template <typename T>
void TestMagnitude()
{
    math::Vector3<T> a(static_cast<T>(3), static_cast<T>(4), static_cast<T>(0));
    T mag = a.Magnitude();
    ASSERT_TRUE(Equal(mag, static_cast<T>(5)), "Magnitude failed: expected 5");
}

template <typename T>
void TestNormalize()
{
    math::Vector3<T> a(3, 4, 0);
    math::Vector3<T> norm = a.Normalized();

    ASSERT_TRUE(Equal(norm.Magnitude(), static_cast<T>(1)), "Normalize failed: magnitude is not 1");
}

static void RunTests()
{
    RUN_TEST(TestConstructor<float>);
    RUN_TEST(TestNegate<float>);
    RUN_TEST(TestAddition<float>);
    RUN_TEST(TestSubstract<float>);
    RUN_TEST(TestDivide<float>);
    RUN_TEST(TestMultiply<float>);
    RUN_TEST(TestDotProduct<float>);
    RUN_TEST(TestCrossProduct<float>);
    RUN_TEST(TestMagnitude<float>);
    RUN_TEST(TestNormalize<float>);

    std::cout << "All tests passed successfully!\n";
}

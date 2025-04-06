#include "math/Vector3.h"
#include "math/Utils.h"
#include <iostream>

bool Equal(float a, float b, float epsilon = static_cast<float>(1e-5))
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

void TestConstructor()
{
    math::Vector3 v;
    ASSERT_TRUE(Equal(v.x, static_cast<float>(0)), "Constructor: x component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v.y, static_cast<float>(0)), "Constructor: y component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v.z, static_cast<float>(0)), "Constructor: z component in vec3 is incorrect.");

    math::Vector3 v1(static_cast<float>(1));
    ASSERT_TRUE(Equal(v1.x, static_cast<float>(1)), "Constructor: x component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v1.y, static_cast<float>(1)), "Constructor: y component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v1.z, static_cast<float>(1)), "Constructor: z component in vec3 is incorrect.");

    math::Vector3 v2(static_cast<float>(1), static_cast<float>(2), static_cast<float>(3));
    ASSERT_TRUE(Equal(v2.x, static_cast<float>(1)), "Constructor: x component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v2.y, static_cast<float>(2)), "Constructor: y component in vec3 is incorrect.");
    ASSERT_TRUE(Equal(v2.z, static_cast<float>(3)), "Constructor: z component in vec3 is incorrect.");
}

void TestNegate()
{
    math::Vector3 a(static_cast<float>(1), static_cast<float>(2), static_cast<float>(3));
    a = -a;
    ASSERT_TRUE(Equal(a.x, static_cast<float>(-1)), "Negate: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<float>(-2)), "Negate +: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<float>(-3)), "Negate +: z component is incorrect");
}

// Test addition +
void TestAddition()
{
    math::Vector3 a(static_cast<float>(1), static_cast<float>(2), static_cast<float>(3));
    math::Vector3 b(static_cast<float>(4), static_cast<float>(5), static_cast<float>(6));
    math::Vector3 result = a + b;

    ASSERT_TRUE(Equal(result.x, static_cast<float>(5)), "Addition +: x component is incorrect");
    ASSERT_TRUE(Equal(result.y, static_cast<float>(7)), "Addition +: y component is incorrect");
    ASSERT_TRUE(Equal(result.z, static_cast<float>(9)), "Addition +: z component is incorrect");

    a += b;
    ASSERT_TRUE(Equal(a.x, static_cast<float>(5)), "Addition +=: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<float>(7)), "Addition +=: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<float>(9)), "Addition +=: z component is incorrect");
}

void TestSubstract()
{
    math::Vector3 a(static_cast<float>(1), static_cast<float>(2), static_cast<float>(3));
    math::Vector3 b(static_cast<float>(4), static_cast<float>(5), static_cast<float>(6));
    math::Vector3 result = a - b;

    ASSERT_TRUE(Equal(result.x, static_cast<float>(-3)), "Substract -: x component is incorrect");
    ASSERT_TRUE(Equal(result.y, static_cast<float>(-3)), "Substract -: y component is incorrect");
    ASSERT_TRUE(Equal(result.z, static_cast<float>(-3)), "Substract -: z component is incorrect");

    a -= b;
    ASSERT_TRUE(Equal(a.x, static_cast<float>(-3)), "Substract -=: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<float>(-3)), "Substract -=: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<float>(-3)), "Substract -=: z component is incorrect");
}

void TestDivide()
{
    math::Vector3 a(static_cast<float>(1), static_cast<float>(1), static_cast<float>(1));
    math::Vector3 result = a / static_cast<float>(2);

    ASSERT_TRUE(Equal(result.x, static_cast<float>(0.5)), "Divide /: x component is incorrect");
    ASSERT_TRUE(Equal(result.y, static_cast<float>(0.5)), "Divide /: y component is incorrect");
    ASSERT_TRUE(Equal(result.z, static_cast<float>(0.5)), "Divide /: z component is incorrect");

    a /= 2.0f;
    ASSERT_TRUE(Equal(a.x, static_cast<float>(0.5)), "Divide /=: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<float>(0.5)), "Divide /=: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<float>(0.5)), "Divide /=: z component is incorrect");
}

void TestMultiply()
{
    math::Vector3 a(static_cast<float>(1), static_cast<float>(1), static_cast<float>(1));
    math::Vector3 result = a * static_cast<float>(2);

    ASSERT_TRUE(Equal(result.x, static_cast<float>(2)), "Multiply *: x component is incorrect");
    ASSERT_TRUE(Equal(result.y, static_cast<float>(2)), "Multiply *: y component is incorrect");
    ASSERT_TRUE(Equal(result.z, static_cast<float>(2)), "Multiply *: z component is incorrect");

    a *= 2.0f;
    ASSERT_TRUE(Equal(a.x, static_cast<float>(2)), "Multiply *=: x component is incorrect");
    ASSERT_TRUE(Equal(a.y, static_cast<float>(2)), "Multiply *=: y component is incorrect");
    ASSERT_TRUE(Equal(a.z, static_cast<float>(2)), "Multiply *=: z component is incorrect");
}

void TestDotProduct()
{
    math::Vector3 a(static_cast<float>(1), static_cast<float>(2), static_cast<float>(3));
    math::Vector3 b(static_cast<float>(4), static_cast<float>(5), static_cast<float>(6));
    float result = math::dot(a, b);

    ASSERT_TRUE(Equal(result, static_cast<float>(32)), "Dot Product is incorrect");
}

void TestCrossProduct()
{
    math::Vector3 a(static_cast<float>(1), static_cast<float>(0), static_cast<float>(0));
    math::Vector3 b(static_cast<float>(0), static_cast<float>(1), static_cast<float>(0));
    math::Vector3 result = math::cross(a, b);

    ASSERT_TRUE(Equal(result.x, static_cast<float>(0)) && Equal(result.y, static_cast<float>(0)) && Equal(result.z, static_cast<float>(1)),
                "Cross product failed: expected (0, 0, 1)");
}

void TestMagnitude()
{
    math::Vector3 a(static_cast<float>(3), static_cast<float>(4), static_cast<float>(0));
    float mag = a.Magnitude();
    ASSERT_TRUE(Equal(mag, static_cast<float>(5)), "Magnitude failed: expected 5");
}

void TestNormalize()
{
    math::Vector3 a(3, 4, 0);
    math::Vector3 norm = a.Normalized();

    ASSERT_TRUE(Equal(norm.Magnitude(), static_cast<float>(1)), "Normalize failed: magnitude is not 1");
}

void RunTests()
{
    RUN_TEST(TestConstructor);
    RUN_TEST(TestNegate);
    RUN_TEST(TestAddition);
    RUN_TEST(TestSubstract);
    RUN_TEST(TestDivide);
    RUN_TEST(TestMultiply);
    RUN_TEST(TestDotProduct);
    RUN_TEST(TestCrossProduct);
    RUN_TEST(TestMagnitude);
    RUN_TEST(TestNormalize);

    std::cout << "All tests passed successfully!\n";
}

int main()
{
    RunTests();
    return 0;
}

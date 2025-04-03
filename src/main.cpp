#include "Canvas.h"
#include "math/Vector3.h"
#include "Test_Vector3.h"

constexpr uint32_t CANVAS_WIDTH = 256;
constexpr uint32_t CANVAS_HEIGHT = 256;

int main()
{
    RunTests();
    Camera Camera;
    auto &canvas = Canvas::GetInstance(CANVAS_WIDTH, CANVAS_HEIGHT, Camera);
    canvas.Draw();
    return 0;
}
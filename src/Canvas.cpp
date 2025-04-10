#include "Canvas.h"

Canvas &Canvas::GetInstance()
{
    static Canvas canvasInstance;
    return canvasInstance;
}

Canvas::~Canvas()
{
}

void Canvas::Initialize(uint32_t width, uint32_t height, Camera camera)
{
    this->width = width;
    this->height = height;
    this->camera = camera;
    viewportHeight = 2.0f;
    viewportWidth = viewportHeight * GetAspectRatio();
    viewportU = math::Vector3(viewportWidth, 0, 0);
    viewportV = math::Vector3(0, -viewportHeight, 0);
    pixelDeltaU = viewportU / width;
    pixelDeltaV = viewportV / height;

    math::Vector3 viewportUpperLeft = camera.GetCameraCenter() - math::Vector3(0, 0, camera.GetFocalLength()) - viewportU / 2 - viewportV / 2;
    pixelPosition = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

    // Initialize the world
    world.AddRenderer(REF_AS(Renderer, Sphere, math::Vector3(0, 0, -1), 0.5f));
    world.AddRenderer(REF_AS(Renderer, Sphere, math::Vector3(0, -100.5, -1), 100));

    framebufferCache.resize(width * height * RGBA_NUM, 0);
}

void Canvas::Draw(std::vector<uint8_t> &framebuffer)
{
    const math::Vector3 cameraCenter = camera.GetCameraCenter();
    const size_t pixelCount = width * height;

    std::vector<size_t> indices(pixelCount);
    std::iota(indices.begin(), indices.end(), 0);

    std::for_each(std::execution::par, indices.begin(), indices.end(), [&](size_t index)
                  {
        const size_t j = index / width;
        const size_t i = index % width;

        math::Vector3 pixelCenter = pixelPosition + (i * pixelDeltaU) + (j * pixelDeltaV);
        math::Vector3 rayDirection = pixelCenter - cameraCenter;

        Ray ray(cameraCenter, rayDirection);
        math::Vector3 color = RayColor(ray, bounces);

        uint8_t r = static_cast<uint8_t>(std::clamp(color.x, 0.0f, 1.0f) * 255.999f);
        uint8_t g = static_cast<uint8_t>(std::clamp(color.y, 0.0f, 1.0f) * 255.999f);
        uint8_t b = static_cast<uint8_t>(std::clamp(color.z, 0.0f, 1.0f) * 255.999f);
        uint8_t a = 255;

        size_t pixelOffset = index * 4;
        // order is b g r a
        framebufferCache[pixelOffset + 0] += b;
        framebufferCache[pixelOffset + 1] += g;
        framebufferCache[pixelOffset + 2] += r;
        framebufferCache[pixelOffset + 3] += a; 

        framebuffer[pixelOffset + 0] = framebufferCache[pixelOffset + 0] / frameNum;
        framebuffer[pixelOffset + 1] = framebufferCache[pixelOffset + 1] / frameNum;
        framebuffer[pixelOffset + 2] = framebufferCache[pixelOffset + 2] / frameNum;
        framebuffer[pixelOffset + 3] = framebufferCache[pixelOffset + 3] / frameNum;

    });

    frameNum++;
}

math::Vector3 Canvas::RayColor(const Ray &r, int bounces)
{
    if (bounces <= 0)
    {
        return math::Vector3(0);
    }
    HitInfo rec;
    if (world.Hit(r, Interval(0.001, infinity), rec))
    {
        math::Vector3 direction = math::random_on_hemisphere(rec.normal);
        return 0.5 * RayColor(Ray(rec.point, direction), bounces - 1);
    }

    math::Vector3 unitDirection = r.GetDirection().Normalized();
    auto a = 0.5 * (unitDirection.y + 1.0);
    return (1.0 - a) * math::Vector3(1.0, 1.0, 1.0) + a * math::Vector3(0.5, 0.7, 1.0);
}

#include "Canvas.h"
#include <fstream>
#include "Renderer.h"

Canvas &Canvas::GetInstance(uint32_t width, uint32_t height, Camera &camera)
{
    static Canvas canvasInstance(width, height, camera);
    return canvasInstance;
}

Canvas::~Canvas()
{
}

Canvas::Canvas(uint32_t width, uint32_t height, Camera &camera)
    : m_Width(width), m_Height(height), m_ViewportHeight(2.0f), m_Camera(camera)
{
    m_ViewportWidth = m_ViewportHeight * GetAspectRatio();
    m_ViewportU = math::Vector3<float>(m_ViewportWidth, 0, 0);
    m_ViewportV = math::Vector3<float>(0, -m_ViewportHeight, 0);
    m_PixelDeltaU = m_ViewportU / m_Width;
    m_PixelDeltaV = m_ViewportV / m_Height;

    math::Vector3<float> viewportUpperLeft = camera.GetCameraCenter() - math::Vector3<float>(0, 0, camera.GetFocalLength()) - m_ViewportU / 2 - m_ViewportV / 2;
    m_PixelPosition = viewportUpperLeft + 0.5 * (m_PixelDeltaU + m_PixelDeltaV);
}

void Canvas::Draw()
{
    std::ofstream imageFile("output.ppm");

    // PPM header
    imageFile << "P3\n"
              << m_Width << ' ' << m_Height << "\n255\n";

    // Render the gradient
    for (size_t j = 0; j < m_Height; j++)
    {
        for (size_t i = 0; i < m_Width; i++)
        {
            math::Vector3<float> pixelCenter = m_PixelPosition + (i * m_PixelDeltaU) + (j * m_PixelDeltaV);
            math::Vector3<float> rayDirection = pixelCenter - m_Camera.GetCameraCenter();

            Ray r(m_Camera.GetCameraCenter(), rayDirection);

            math::Vector3<float> color = RayColor(r);
            writeColor(imageFile, color);
        }
    }

    // Close the file
    imageFile.close();
}

void Canvas::writeColor(std::ofstream &file, const math::Vector3<float> &color)
{
    auto r = color.x;
    auto g = color.y;
    auto b = color.z;

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel color components.
    file << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

math::Vector3<float> Canvas::RayColor(const Ray &r)
{
    if (Renderer::Sphere(math::Vector3<float>(0, 0, -1), 0.5f, r))
    {
        return math::Vector3<float>(1.0f, 0.0f, 0.0f);
    }

    math::Vector3<float> unitDirection = r.GetDirection().Normalized();
    float a = 0.5f * (unitDirection.y + 1.0f);

    return (1.0f - a) * math::Vector3<float>(1.0f) + a * math::Vector3<float>(0.5f, 0.7f, 1.0f);
}

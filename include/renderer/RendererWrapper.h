#pragma once
#include "pch.h"
#include "Interval.h"
#include "Ray.h"
#include "Renderer.h"

class RendererWrapper
{
public:
    template <typename T>
    RendererWrapper(Ref<T> renderer)
        : self(REF(Model<T>, std::move(renderer)))
    {
    }

    bool Hit(const Ray &ray, Interval rayT, HitInfo &hitinfo) const
    {
        return self->Hit(ray, rayT, hitinfo);
    }

    math::Vector3 GetAlbedo() const  
    {
        return self->GetAlbedo();
    }

private:
    struct Concept
    {
        virtual ~Concept() = default;
        virtual bool Hit(const Ray &, Interval, HitInfo &) const = 0;
        virtual math::Vector3 GetAlbedo() const = 0;
    };

    template <typename T>
    struct Model : public Concept
    {
        Ref<T> object;
        Model(Ref<T> object) : object(std::move(object)) {}
        bool Hit(const Ray &ray, Interval rayT, HitInfo &hitInfo) const override
        {
            return object->Hit(ray, rayT, hitInfo);
        }

        math::Vector3 GetAlbedo() const override
        {
            return object->GetAlbedo();
        }
    };

    Ref<const Concept> self;
};
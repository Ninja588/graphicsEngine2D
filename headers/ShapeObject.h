#ifndef SHAPEOBJECT_H
#define SHAPEOBJECT_H
#include "DrawableObject.h"
#include "TransformableObject.h"


class ShapeObject : public DrawableObject, public TransformableObject{
private:

public:
    //void translate(float tx, float ty) override;
    //void rotate(float angle, float centerX = 0.f, float centerY = 0.f) override;
    //void scale(float kx, float ky, float centerX = 0.f, float centerY = 0.f) override;
};



#endif // SHAPEOBJECT_H
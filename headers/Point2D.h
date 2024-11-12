#ifndef POINT2D_H
#define POINT2D_H
#include "ShapeObject.h" 

class PrimitiveRenderer;

class Point2D : public ShapeObject {
private:
    float x, y;
public:
    Point2D(float x = 0.f, float y = 0.f);

    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    void setXY(float x, float y);
    void draw(PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override;

    void translate(float tx, float ty) override;
    void rotate(float angle, float centerX = 0.f, float centerY = 0.f) override;
    void scale(float kx, float ky, float centerX = 0.f, float centerY = 0.f) override;

    Point2D getPoint();

};

#endif // POINT2D_H
#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include <cmath>

#define M_PI 3.14159265358979323846

Point2D::Point2D(float x, float y) : x(x), y(y) {}

float Point2D::getX() const { return x; }
float Point2D::getY() const { return y; }

void Point2D::setX(float x) { this->x = x; }
void Point2D::setY(float y) { this->y = y; }
void Point2D::setXY(float x, float y) { this->x = x; this->y = y; }

void Point2D::draw(PrimitiveRenderer& renderer, sf::Color color) const { renderer.drawCircle(1.f, x, y, color); }

void Point2D::translate(float tx, float ty) {
    x += tx;
    y += ty;
}

void Point2D::rotate(float angle, float centerX, float centerY) {
    float radians = angle * M_PI / 180.0f;
    float newX = centerX + (x - centerX) * cos(radians) - (y - centerY) * sin(radians);
    //float newX = atanf(centerX-x);
    //float newY = atanf(centerY-y);
    float newY = centerY + (x - centerX) * sin(radians) + (y - centerY) * cos(radians);
    x = newX;
    y = newY;
}

void Point2D::scale(float kx, float ky, float centerX, float centerY) {
    x += kx;
    y += ky;
}

#include "Point2D.h"
#include "PrimitiveRenderer.h"

Point2D::Point2D(float x, float y) : x(x), y(y) {}

float Point2D::getX() const { return x; }
float Point2D::getY() const { return y; }

void Point2D::setX(float x) { this->x = x; }
void Point2D::setY(float y) { this->y = y; }
void Point2D::setXY(float x, float y) { this->x = x; this->y = y; }

void Point2D::draw(PrimitiveRenderer& renderer, sf::Color color) const { renderer.drawCircle(1.f, x, y, color); }
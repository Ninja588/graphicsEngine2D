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

void Point2D::draw(PrimitiveRenderer& renderer, sf::Color color) { 
    renderer.drawCircle(1.f, x, y, color); 
}

void Point2D::translate(float tx, float ty) {
    this->x += tx;
    this->y += ty;
}

void Point2D::rotate(float angle, float centerX, float centerY) {
    float radians = angle * (M_PI / 180.0f);
    float newX = centerX + (x - centerX) * cos(radians) - (y - centerY) * sin(radians);
    float newY = centerY + (x - centerX) * sin(radians) + (y - centerY) * cos(radians);

    this->x = newX;
    this->y = newY;
}

void Point2D::scale(float kx, float ky, float centerX, float centerY) {
    //cout<<kx<<endl<<ky<<endl<<centerX<<endl<<centerY<<endl;
    float newX = x * kx + (1-kx) * centerX;
    float newY =  y * ky + (1-ky) * centerY;

    //cout<<"X: "<<x<<" NewX: "<<newX<<endl;
    //cout<<"Y: "<<y<<" NewY: "<<newY<<endl;

    this->x = newX;
    this->y = newY;
}

Point2D Point2D::getPoint() {
    return Point2D(x,y);
}

#ifndef TRANSFORMABLEOBJECT_H
#define TRANSFORMABLEOBJECT_H

#include<SFML/Graphics.hpp>

class TransformableObject{
private:

public:
    virtual void translate(float tx, float ty) = 0;
    virtual void rotate(float angle, float centerX = 0.f, float centerY = sf::VideoMode::getDesktopMode().height) = 0;
    virtual void scale(float kx, float ky, float centerX = 0.f, float centerY = sf::VideoMode::getDesktopMode().height) = 0;
};



#endif // TRANSFORMABLEOBJECT_H
#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

class PrimitiveRenderer;

class DrawableObject{
private:

public:
    virtual void draw(PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) = 0;

};



#endif // DRAWABLEOBJECT_H
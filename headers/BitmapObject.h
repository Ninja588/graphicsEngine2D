#ifndef BITMAPOBJECT_H
#define BITMAPOBJECT_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "BitmapHandler.h"

class BitmapObject : public DrawableObject, public TransformableObject {
public:
    BitmapObject();
    void addBitmap(const BitmapHandler& bitmap);
    void draw(PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override;
    std::vector<BitmapHandler> bitmaps;

private:
    sf::Sprite sprite;
};

#endif // BITMAPOBJECT_H

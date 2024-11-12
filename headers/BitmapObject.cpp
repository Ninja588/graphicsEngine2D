#include "BitmapObject.h"
#include "PrimitiveRenderer.h"

BitmapObject::BitmapObject() {}

void BitmapObject::addBitmap(const BitmapHandler& bitmap) {
    bitmaps.push_back(bitmap);
}

void BitmapObject::draw(PrimitiveRenderer& renderer, sf::Color color) {
    for(const auto& bitmap : bitmaps) {
        sprite.setTexture(bitmap.getTexture());
        sprite.setColor(color);
        renderer.draw(sprite);
    }
}

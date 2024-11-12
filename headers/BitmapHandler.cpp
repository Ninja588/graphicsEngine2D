#include "BitmapHandler.h"

BitmapHandler::BitmapHandler() {}

bool BitmapHandler::create(int width, int height) {
    image.create(width, height, sf::Color::Transparent);
    return texture.loadFromImage(image);
}

bool BitmapHandler::loadFromFile(const std::string& filename) {
    if(image.loadFromFile(filename)) {
        return texture.loadFromImage(image);
    }
    return false;
}

bool BitmapHandler::saveToFile(const std::string& filename) {
    return image.saveToFile(filename);
}

bool BitmapHandler::copyFrom(const BitmapHandler& other) {
    if(this != &other) {
        image = other.image;
        return texture.loadFromImage(image);
    }
    return false;
}

const sf::Texture& BitmapHandler::getTexture() const {
    return texture;
}

sf::Sprite BitmapHandler::getSprite() const {
    return sf::Sprite(texture);
}

#ifndef BITMAPHANDLER_H
#define BITMAPHANDLER_H

#include <SFML/Graphics.hpp>
#include <string>

class BitmapHandler {
public:
    BitmapHandler();

    bool create(int width, int height);
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename);
    bool copyFrom(const BitmapHandler& other);

    const sf::Texture& getTexture() const;
    sf::Sprite getSprite() const;

private:
    sf::Texture texture;
    sf::Image image;
};

#endif // BITMAPHANDLER_H

#include "Player.h"

Player::Player(int sizeX, int sizeY, const char filename[]) {
    Player::hp = 100;
    Player::playerShape = sf::RectangleShape (sf::Vector2f(sizeX, sizeY));
    if(!texture.loadFromFile(filename)) return;

    playerShape.setTexture(&texture);
    playerShape.setOutlineThickness(3);
    playerShape.setOutlineColor(sf::Color::Black);
}
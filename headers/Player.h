#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    int hp;
    sf::Texture texture;
public:
    sf::RectangleShape playerShape;
    Player(int sizeX, int sizeY, const char filename[]);
};

#endif // PLAYER_H
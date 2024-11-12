#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include<iostream>
#include <cmath>
#include "SpriteObject.h"
#include "PrimitiveRenderer.h"

class Player : public SpriteObject {
public:
    enum Direction { Down, Left, Right, Up, None }; 
    sf::Sprite sprite;
    Player(int sizeX, int sizeY, const char filename[]);
    void animate() override;
    void draw(PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override;
    void move(float offsetX, float offsetY);
    void resize(float width, float height);
    void setDirection(Direction direction);
private:
    int hp;
    Direction currentDirection = None;
    void translate(float tx, float ty) override;
    void rotate(float angle, float centerX = 0.f, float centerY = sf::VideoMode::getDesktopMode().height) override;
    void scale(float kx, float ky, float centerX = 0.f, float centerY = sf::VideoMode::getDesktopMode().height) override;
    sf::Vector2f velocity;
    std::vector<sf::IntRect> animationFrames;
    size_t currentFrame = 0;
    sf::Clock animationClock;
    float animationSpeed = 0.1f;
};
#endif // PLAYER_H
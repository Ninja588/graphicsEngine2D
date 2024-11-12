#include "Player.h"

void Player::translate(float tx, float ty)
{
}

void Player::rotate(float angle, float centerX, float centerY)
{
}

void Player::scale(float kx, float ky, float centerX, float centerY)
{
}

Player::Player(int sizeX, int sizeY, const char filename[]) : hp(100), velocity(0.f, 0.f) {
    BitmapHandler bitmap;
    if(bitmap.loadFromFile(filename)) {
        addBitmap(bitmap);

        sf::Vector2u textureSize = bitmap.getTexture().getSize();
        //float temp = textureSize.x / 138;
        //std::cout<<(float)textureSize.x / 138<<std::endl<<std::ceil((float)textureSize.x / 138);
        // jeden sprite w sheet ma 138x138 pikseli
        int framesPerRow = ceil((float)textureSize.x / 138);
        int framesPerColumn = ceil((float)textureSize.y / 138);

        if(textureSize.x < 138 || textureSize.y < 138) {
            throw std::runtime_error("Zle wymiary");
        }

        for(int row = 0; row < framesPerColumn; ++row) {
            //std::cout<<framesPerColumn<<std::endl;
            for(int col = 0; col < framesPerRow; ++col) {
                //std::cout<<framesPerRow<<std::endl;
                animationFrames.push_back(sf::IntRect(col * 138, row * 138, 138, 138));
            }
        }

        sprite.setTexture(bitmap.getTexture());
        sprite.setTextureRect(animationFrames[0]);
        resize(sizeX,sizeY);
    }   
}

void Player::animate() {
    if(animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        currentFrame = (currentFrame + 1) % 6;
        //std::cout << "currentframe: " << currentFrame <<std::endl;
        animationClock.restart();
    }

    int row = 0;
    switch(currentDirection) {
        case Down: row = 0; break;
        case Left: row = 1; break;
        case Right: row = 2; break;
        case Up: row = 3; break;
        default: row = 0; break;
    }

    int frameIndex = row * 6 + currentFrame;
    //currentFrame = frameIndex;
    //std::cout << "currentframe: " << frameIndex << " (row: " << row << ", frame: " << currentFrame << ")" << std::endl;
    sprite.setTextureRect(animationFrames[frameIndex]);
}

void Player::draw(PrimitiveRenderer& renderer, sf::Color color) {
    animate();
    
    if(bitmaps.empty()) {
        throw std::runtime_error("Brak bitmapy gracza");
    }

    const BitmapHandler& bitmap = bitmaps[0];
    if(bitmap.getTexture().getSize().x == 0) {
        throw std::runtime_error("Nie zaladowano tekstury bitmapy");
    }

    sprite.setTexture(bitmap.getTexture());
    //sprite.setTextureRect(animationFrames[currentFrame]);
    sprite.setColor(color);

    renderer.draw(sprite);
}

void Player::setDirection(Direction direction) {
    if(currentDirection != direction) {
        currentDirection = direction;
        //std::cout<<currentDirection;
        currentFrame = 0;
        //std::cout<<"direction: "<<currentDirection<<std::endl;
    }
}

void Player::move(float offsetX, float offsetY) {
    Direction newDirection = None;
    if(offsetX > 0) {
        newDirection = Right;
    } else if(offsetX < 0) {
        newDirection = Left;
    } else if(offsetY > 0) {
        newDirection = Down;
    } else if(offsetY < 0) {
        newDirection = Up;
    }

    if(newDirection != None) {
        setDirection(newDirection);
    }

    sprite.move(offsetX, offsetY);
}

void Player::resize(float width, float height) {
    if(sprite.getTexture() == nullptr) {
        throw std::runtime_error("Brak tekstury");
    }

    float frameWidth = static_cast<float>(animationFrames[0].width);
    float frameHeight = static_cast<float>(animationFrames[0].height);

    float scaleX = width / frameWidth;
    float scaleY = height / frameHeight;

    sprite.setScale(scaleX, scaleY);
}

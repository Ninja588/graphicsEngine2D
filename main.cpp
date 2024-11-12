#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "headers/PrimitiveRenderer.h"
#include "headers/Point2D.h"
#include "headers/LineSegment.h"
#include "headers/Player.h"
#include "headers/DrawableObject.h"
#include "headers/GameObject.h"
#include "headers/ShapeObject.h"
#include "headers/TransformableObject.h"
#include "headers/BitmapHandler.h"
#include "headers/BitmapObject.h"
#include "headers/AnimatedObject.h"
#include "headers/SpriteObject.h"

#include "headers/linker.h"

using namespace std;

class Engine {
private:
    bool checkFullscreen = false;
    int resWidth, resHeight;

public:
    Engine(int maxFps, int resWidth, int resHeight) : resWidth(resWidth), resHeight(resHeight) {
        sf::RenderWindow window(sf::VideoMode(this->resWidth, this->resHeight), "SFML");
        PrimitiveRenderer renderer(window);
        
        //sf::RectangleShape shape(sf::Vector2f(50,50));

        Point2D point1(150.f, 250.f);
        Point2D *p;
        p=&point1;
        Point2D point2(150.f, 350.f);
        Point2D *p2;
        p2=&point2;
        Point2D point3(200.f, 350.f);
        LineSegment line(p, p2);
        line.setStartPoint(point3);
        // point1.translate(50, 50);
        // point2.translate(50, 50);
        // point3.translate(50, 50);

        LineSegment line1(p, p2);
        line1.setStartPoint(point3);

        line1.translate(50,50);
        line1.rotate(90);
        line1.scale(3.f,3.f);

        vector<Point2D> points = { Point2D(100.f, 100.f), Point2D(200.f, 100.f), Point2D(200.f, 200.f), Point2D(100.f, 200.f) };
        vector<Point2D> points2 = { Point2D(150.f, 150.f), Point2D(250.f, 150.f), Point2D(250.f, 250.f), Point2D(150.f, 250.f) };
        // vector<LineSegment> segments = {
        //     LineSegment(Point2D(300.f, 300.f), Point2D(400.f, 300.f)),
        //     LineSegment(Point2D(400.f, 300.f), Point2D(400.f, 400.f)),
        //     LineSegment(Point2D(400.f, 400.f), Point2D(300.f, 400.f))
        // };

        vector<Point2D> polygon = { Point2D(400.f, 400.f), Point2D(450.f, 450.f),Point2D(450.f, 475.f),Point2D(500.f, 400.f), Point2D(500.f, 500.f), Point2D(400.f, 500.f),Point2D(425.f, 480.f),Point2D(400.f, 400.f) };

        // sf::Texture texture;
        // if(!texture.loadFromFile("whitePawn.png")) return;

        window.setFramerateLimit(maxFps);
        // shape.setTexture(&texture);
        // shape.setOutlineThickness(3);
        // shape.setOutlineColor(sf::Color::Black);
        Player player(50, 50, "sprite.png");
        player.resize(100,100);

        //BitmapHandler bitmap; 
        //bitmap.create(200, 200);

        while(window.isOpen())
        {
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                { 
                    window.close();
                }
                if(event.type == sf::Event::MouseButtonPressed) {
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        player.sprite.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    }
                }
            }

            //player.setDirection(Player::None);
            
            bool isMoving = false;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                player.move(-1, 0); // lewo
                isMoving = true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                player.move(1, 0); // prawo
                isMoving = true;

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                player.move(0, -1); // gora
                isMoving = true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                player.move(0, 1); // dol
                isMoving = true;
            }

            if (!isMoving) { 
                player.setDirection(Player::None); 
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                if(!checkFullscreen)
                {
                    window.create(sf::VideoMode::getFullscreenModes()[0], "SFML", sf::Style::Fullscreen);
                    window.setFramerateLimit(maxFps);
                }
                else {
                    window.create(sf::VideoMode(this->resWidth, this->resHeight), "SFML");
                    window.setFramerateLimit(maxFps);
                }
                checkFullscreen = !checkFullscreen;
            }

            // do renderowania
            window.clear(sf::Color::White);

            renderer.drawCircle(50, 200, 200, sf::Color::Red);
            renderer.drawCircleSym4(50, 600, 200, sf::Color::Blue);
            renderer.drawElipseSym4(50,25, 600, 400, sf::Color::Green);
            renderer.drawLine(80,0,80,200, sf::Color::Black);
            renderer.drawLineIncremental(30,0,30,200, sf::Color::Black);
            renderer.drawLineIncremental(600, 100, 550, 50, sf::Color::Black);

            line.draw(renderer);
            line1.draw(renderer);

            renderer.drawOSline(points, sf::Color::Green, false);
            renderer.drawOSline(points2, sf::Color::Blue, true);
            //renderer.drawOSline(segments, sf::Color::Red, false);
            renderer.drawPolygon(polygon, sf::Color::Cyan, false);

            player.draw(renderer, sf::Color::White);

            window.display();
        }
    }
};

int main()
{
    Engine engineObj(60, 800, 600);

    return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "headers/PrimitiveRenderer.h"
#include "headers/Point2D.h"
#include "headers/LineSegment.h"
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
        
        sf::RectangleShape shape(sf::Vector2f(50,50));

        Point2D point1(150.f, 250.f);
        Point2D point2(150.f, 350.f);
        Point2D point3(200.f, 350.f);
        LineSegment line(point1, point2);
        line.setStartPoint(point3);

        vector<Point2D> points = { Point2D(100.f, 100.f), Point2D(200.f, 100.f), Point2D(200.f, 200.f), Point2D(100.f, 200.f) };
        vector<Point2D> points2 = { Point2D(150.f, 150.f), Point2D(250.f, 150.f), Point2D(250.f, 250.f), Point2D(150.f, 250.f) };
        vector<LineSegment> segments = {
            LineSegment(Point2D(300.f, 300.f), Point2D(400.f, 300.f)),
            LineSegment(Point2D(400.f, 300.f), Point2D(400.f, 400.f)),
            LineSegment(Point2D(400.f, 400.f), Point2D(300.f, 400.f))
        };

        sf::Texture texture;
        if(!texture.loadFromFile("whitePawn.png")) return;
     

        window.setFramerateLimit(maxFps);
        shape.setTexture(&texture);
        shape.setOutlineThickness(3);
        shape.setOutlineColor(sf::Color::Black);

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
                        shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    }
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                shape.move(-1, 0); // lewo
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                shape.move(1, 0); // prawo
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                shape.move(0, -1); // gora
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                shape.move(0, 1); // dol
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                shape.setFillColor(sf::Color::Red);
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
            renderer.drawLine(80,0,80,200, sf::Color::Black);
            renderer.drawLineIncremental(30,0,30,200, sf::Color::Black);
            renderer.drawLineIncremental(600, 100, 550, 50, sf::Color::Black);

            line.draw(renderer);

            renderer.drawOSline(points, sf::Color::Green, false);

            renderer.drawOSline(points2, sf::Color::Blue, true);

            renderer.drawOSline(segments, sf::Color::Red, false);

            window.draw(shape);
            //window.draw(doroShape);
            window.display();
        }
    }
};

int main()
{
    Engine engineObj(60, 800, 600);

    return 0;
}
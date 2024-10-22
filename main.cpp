#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class PrimitiveRenderer {
private:
    sf::RenderWindow& window;
public:
    PrimitiveRenderer(sf::RenderWindow& window) : window(window) {}

    void drawCircle(float radius, float x, float y, sf::Color color) {
        sf::CircleShape circle(radius);
        circle.setPosition(x, y);
        circle.setFillColor(color);
        window.draw(circle);
    }

    void drawRectangle(float width, float height, float x, float y, sf::Color color) {
        sf::RectangleShape rectangle(sf::Vector2f(width, height));
        rectangle.setPosition(x, y);
        rectangle.setFillColor(color);
        window.draw(rectangle);
    }

    void drawLine(float startX, float startY, float endX, float endY, sf::Color color) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(startX, startY), color),
            sf::Vertex(sf::Vector2f(endX, endY), color)
        };
        window.draw(line, 2, sf::Lines);
    }
};

class Engine {
private:
    bool checkFullscreen = false;
    int resWidth, resHeight;
public:
    Engine(int maxFps, int resWidth, int resHeight) {
        this->resHeight = resHeight;
        this->resWidth = resWidth;

        sf::RenderWindow window(sf::VideoMode(this->resWidth, this->resHeight), "SFML");
        PrimitiveRenderer renderer(window);
        sf::RectangleShape shape(sf::Vector2f(50,50));
        
        //sf::RectangleShape doroShape(sf::Vector2f(50,50));
        //sf::Texture doro;
        // if(!doro.loadFromFile("d0ro.png")) return;
        // doroShape.setTexture(&doro);
        // doroShape.setPosition(-50,0);

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
                        point2D(mousePos);
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
                    checkFullscreen = true;
                }
                else {
                    window.create(sf::VideoMode(this->resWidth, this->resHeight), "SFML");
                    window.setFramerateLimit(maxFps);
                    checkFullscreen = false;
                }
            }

            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            //     doroShape.move(100,0);
            // }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
            //     doroShape.move(-100,0);
            // }

            // do renderowania
            window.clear(sf::Color::White);

            renderer.drawCircle(50, 200, 200, sf::Color::Red);
            window.draw(shape);
            //window.draw(doroShape);
            window.display();
        }
    }

    void point2D(sf::Vector2i mousePos) {
        cout<<"x: "<<mousePos.x<<" y: "<<mousePos.y<<endl;
    }
};

int main()
{
    Engine engineObj(60, 400, 400);

    return 0;
}

#include <SFML/Graphics.hpp>

class Engine {
private:

public:
    Engine(int maxFps, int resWdith, int resHeight) {
        sf::RenderWindow window(sf::VideoMode(resWdith, resHeight), "SFML");
        sf::RectangleShape shape(sf::Vector2f(50,50));
        sf::Texture texture;
        if(!texture.loadFromFile("whitePawn.png")) return;

        window.setFramerateLimit(maxFps);
        shape.setTexture(&texture);
        shape.setOutlineThickness(3);
        shape.setOutlineColor(sf::Color::Black);
        
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                { 
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                shape.move(-1, 0); // lewo
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                shape.move(1, 0); // prawo
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                shape.move(0, -1); // gora
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                shape.move(0, 1); // dol
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                shape.setFillColor(sf::Color::Red);
            }
            
            window.clear(sf::Color::White);
            window.draw(shape);
            window.display();
        }
    }
};

int main()
{
    Engine engineObj(60, 400, 400);

    return 0;
}
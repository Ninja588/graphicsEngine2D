#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Point2D.h"
#include "LineSegment.h"

class PrimitiveRenderer {
private:
    sf::RenderWindow& window;
public:
    PrimitiveRenderer(sf::RenderWindow& window);

    void draw(const sf::Sprite& sprite);
    void draw(const sf::Shape& shape);
    void draw(const sf::Text& text);
    void drawCircle(float radius, float x, float y, sf::Color color);
    void drawCircleSym4(double radius, double x, double y, sf::Color color);
    void drawElipseSym4(double radiusX,double radiusY, double x, double y, sf::Color color);
    void drawRectangle(float width, float height, float x, float y, sf::Color color);
    void drawLine(float startX, float startY, float endX, float endY, sf::Color color);
    void drawLineIncremental(float x0, float y0, float x1, float y1, sf::Color color);
    void drawOSline(const std::vector<Point2D>& points, sf::Color color, bool closed = false);
    void drawOSline(const std::vector<LineSegment>& segments, sf::Color color, bool closed = false);
    void drawPolygon(const std::vector<Point2D>& points, sf::Color color, bool closed = false);
};

#endif // PRIMITIVERENDERER_H
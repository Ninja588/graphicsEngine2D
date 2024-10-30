#include "PrimitiveRenderer.h"
#include <cmath>

#define PI 3.14159265358979323846


using namespace std;

PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow& window) : window(window) {}

void PrimitiveRenderer::drawCircle(float radius, float x, float y, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setPosition(x, y);
    circle.setFillColor(color);
    window.draw(circle);
}

void PrimitiveRenderer::drawRectangle(float width, float height, float x, float y, sf::Color color) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

void PrimitiveRenderer::drawLine(float startX, float startY, float endX, float endY, sf::Color color) {
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(startX, startY), color),
        sf::Vertex(sf::Vector2f(endX, endY), color)
    };
    window.draw(line, 2, sf::Lines);
}

void PrimitiveRenderer::drawLineIncremental(float x0, float y0, float x1, float y1, sf::Color color) {
    float dx = x1-x0;
    float dy = y1-y0;
    sf::VertexArray line(sf::Lines, 2);

    if(abs(dy)<=abs(dx)) {
        if(x0>x1) {
            swap(x0, x1);
            swap(y0, y1);
        }
        float m = dy / dx;
        float y = y0;
        for(float x=x0;x<=x1;++x) {
            line[0].position = sf::Vector2f(x, round(y));
            line[0].color = color;
            y += m;
            line[1].position = sf::Vector2f(x + 1, round(y));
            line[1].color = color;
            window.draw(line);
        }
    } else {
        if(y0>y1) {
            swap(x0, x1);
            swap(y0, y1);
        }
        float m = dx/dy;
        float x = x0;
        for(float y=y0;y<=y1;++y) {
            line[0].position = sf::Vector2f(round(x), y);
            line[0].color = color;
            x += m;
            line[1].position = sf::Vector2f(round(x), y + 1);
            line[1].color = color;
            window.draw(line);
        }
    }
}

void PrimitiveRenderer::drawOSline(const vector<Point2D>& points, sf::Color color, bool closed) {
    sf::VertexArray OSline(closed ? sf::LinesStrip : sf::LineStrip, points.size() + (closed ? true : false));

    for(int i=0;i<points.size();++i) {
        OSline[i].position = sf::Vector2f(points[i].getX(), points[i].getY());
        OSline[i].color = color;
    }

    if(closed) {
        OSline[points.size()].position = sf::Vector2f(points[0].getX(), points[0].getY());
        OSline[points.size()].color = color;
    }

    window.draw(OSline);
}

void PrimitiveRenderer::drawOSline(const vector<LineSegment>& segments, sf::Color color, bool closed) {
    for (const auto& segment : segments) {
        drawLineIncremental(segment.getStartPoint().getX(), segment.getStartPoint().getY(),
                            segment.getEndPoint().getX(), segment.getEndPoint().getY(), color);
    }

    if (closed && !segments.empty()) {
        const auto& firstSegment = segments[0];
        const auto& lastSegment = segments.back();

        drawLineIncremental(lastSegment.getEndPoint().getX(), lastSegment.getEndPoint().getY(),
                            firstSegment.getStartPoint().getX(), firstSegment.getStartPoint().getY(), color);
    }
}

void PrimitiveRenderer::drawCircleSym4(double radius, double x0, double y0, sf::Color color) {
for (float i=0;i <=PI/2;i=i+(PI/180))
   {

    double x1 = x0 + radius*cos(0+i);
    double y1 = y0 + radius*sin(0+i);

    double x2 = x0 + radius*cos(PI/2+i);
    double y2 = y0 + radius*sin(PI/2+i);

    double x3 = x0 + radius*cos(PI+i);
    double y3 = y0 + radius*sin(PI+i);

    double x4 = x0 + radius*cos(PI*1.5+i);
    double y4 = y0 + radius*sin(PI*1.5+i);

        sf::Vertex line1[] = {
            sf::Vertex(sf::Vector2f(x1, y1), color),
            sf::Vertex(sf::Vector2f(x0, y0), color)
        };

        sf::Vertex line2[] = {
            sf::Vertex(sf::Vector2f(x2, y2), color),
            sf::Vertex(sf::Vector2f(x0, y0), color)
        };

        sf::Vertex line3[] = {
            sf::Vertex(sf::Vector2f(x3, y3), color),
            sf::Vertex(sf::Vector2f(x0, y0), color)
        };

        sf::Vertex line4[] = {
            sf::Vertex(sf::Vector2f(x4, y4), color),
            sf::Vertex(sf::Vector2f(x0, y0), color)
        };


        window.draw(line1 , 2 , sf::Lines);
        window.draw(line2 , 2 , sf::Lines);
        window.draw(line3 , 2 , sf::Lines);
        window.draw(line4 , 2 , sf::Lines);
    }

    
}

void PrimitiveRenderer::drawElipseSym4(double radiusX,double radiusY, double x0, double y0, sf::Color color) {
for (float i=0;i <=PI/2;i=i+(PI/180))
   {

    double x1 = x0 + radiusX*cos(0+i);
    double y1 = y0 + radiusY*sin(0+i);

    double x2 = x0 + radiusX*cos(PI/2+i);
    double y2 = y0 + radiusY*sin(PI/2+i);

    double x3 = x0 + radiusX*cos(PI+i);
    double y3 = y0 + radiusY*sin(PI+i);

    double x4 = x0 + radiusX*cos(PI*1.5+i);
    double y4 = y0 + radiusY*sin(PI*1.5+i);

        sf::Vertex line1[] = {
            sf::Vertex(sf::Vector2f(x1, y1), color),
            sf::Vertex(sf::Vector2f(x0, y0), color)
        };

        sf::Vertex line2[] = {
            sf::Vertex(sf::Vector2f(x2, y2), color),
            sf::Vertex(sf::Vector2f(x0, y0), color)
        };

        sf::Vertex line3[] = {
            sf::Vertex(sf::Vector2f(x3, y3), color),
            sf::Vertex(sf::Vector2f(x0, y0), color)
        };

        sf::Vertex line4[] = {
            sf::Vertex(sf::Vector2f(x4, y4), color),
            sf::Vertex(sf::Vector2f(x0, y0), color)
        };


        window.draw(line1 , 2 , sf::Lines);
        window.draw(line2 , 2 , sf::Lines);
        window.draw(line3 , 2 , sf::Lines);
        window.draw(line4 , 2 , sf::Lines);
    }

    
}

void PrimitiveRenderer::drawPolygon(const vector<Point2D>& points, sf::Color color, bool closed) {
    sf::VertexArray OSline(closed ? sf::LinesStrip : sf::LineStrip, points.size() + (closed ? true : false));

    for(int i=0;i<points.size();++i) {
        OSline[i].position = sf::Vector2f(points[i].getX(), points[i].getY());
        OSline[i].color = color;
    }

    if(closed) {
        OSline[points.size()].position = sf::Vector2f(points[0].getX(), points[0].getY());
        OSline[points.size()].color = color;
    }

    window.draw(OSline);
}
#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "Point2D.h"

class PrimitiveRenderer;

class LineSegment {
private:
    Point2D startPoint;
    Point2D endPoint;
public:
    LineSegment(const Point2D& start, const Point2D& end);

    Point2D getStartPoint() const;
    Point2D getEndPoint() const;
    void setStartPoint(const Point2D& point);
    void setEndPoint(const Point2D& point);
    void draw(PrimitiveRenderer& renderer, sf::Color color = sf::Color::Black) const;
};

#endif // LINESEGMENT_H
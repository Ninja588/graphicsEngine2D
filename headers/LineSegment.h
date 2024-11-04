#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "Point2D.h"

class PrimitiveRenderer;

class LineSegment : public ShapeObject{
private:
    Point2D startPoint;
    Point2D endPoint;
    Point2D *p1;
    Point2D *p2;
public:
    LineSegment(Point2D *point1, Point2D *point2);

    Point2D getStartPoint() const;
    Point2D getEndPoint() const;
    void setStartPoint(const Point2D& point);
    void setEndPoint(const Point2D& point);
    void draw(PrimitiveRenderer& renderer, sf::Color color = sf::Color::Black) const;

    void translate(float tx, float ty) override;
    void rotate(float angle, float centerX = 0.f, float centerY = 0.f) override;
    void scale(float kx, float ky, float centerX = 0.f, float centerY = 0.f) override;
};

#endif // LINESEGMENT_H

//const Point2D& start, const Point2D& end
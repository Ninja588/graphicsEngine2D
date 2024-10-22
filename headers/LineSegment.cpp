#include "LineSegment.h"
#include "PrimitiveRenderer.h"

LineSegment::LineSegment(const Point2D& start, const Point2D& end)
    : startPoint(start), endPoint(end) {}

Point2D LineSegment::getStartPoint() const { return startPoint; }
Point2D LineSegment::getEndPoint() const { return endPoint; }

void LineSegment::setStartPoint(const Point2D& point) { startPoint = point; }
void LineSegment::setEndPoint(const Point2D& point) { endPoint = point; }

void LineSegment::draw(PrimitiveRenderer& renderer, sf::Color color) const { renderer.drawLineIncremental(startPoint.getX(), startPoint.getY(), endPoint.getX(), endPoint.getY(), color); }
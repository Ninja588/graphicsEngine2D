#include "LineSegment.h"
#include "PrimitiveRenderer.h"

LineSegment::LineSegment(Point2D *point1, Point2D *point2) {
    p1=point1;
    p2=point2;
    startPoint=p1->getPoint();
    endPoint=p2->getPoint();
}

Point2D LineSegment::getStartPoint() const { return startPoint; }
Point2D LineSegment::getEndPoint() const { return endPoint; }

void LineSegment::setStartPoint(const Point2D& point) { startPoint = point; }
void LineSegment::setEndPoint(const Point2D& point) { endPoint = point; }

void LineSegment::draw(PrimitiveRenderer& renderer, sf::Color color) const { renderer.drawLineIncremental(startPoint.getX(), startPoint.getY(), endPoint.getX(), endPoint.getY(), color); }

void LineSegment::translate(float tx, float ty) {
    startPoint.translate(tx, ty);
    endPoint.translate(tx, ty);
}

void LineSegment::rotate(float angle, float centerX, float centerY) {
    //startPoint.rotate(angle, centerX1, centerY1);
    //cout<<"S1X: "<<startPoint.getY()<<" E1X: "<<endPoint.getY()<<endl;
    endPoint.rotate(angle, startPoint.getX(), startPoint.getY());
    //cout<<"S2X: "<<startPoint.getY()<<" E2X: "<<endPoint.getY()<<endl;
}

void LineSegment::scale(float kx, float ky, float centerX, float centerY) {
    //cout<<"S3X: "<<startPoint.getY()<<" E3X: "<<endPoint.getY()<<endl;
    float newCenterX = (startPoint.getX() + endPoint.getX())/2;
    float newCenterY = (startPoint.getY() + endPoint.getY())/2;

    startPoint.scale(kx, ky, newCenterX, newCenterY);
    endPoint.scale(kx, ky, newCenterX, newCenterY);
}

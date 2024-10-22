#ifndef POINT2D_H
#define POINT2D_H

class PrimitiveRenderer;

class Point2D {
private:
    float x, y;
public:
    Point2D(float x = 0.f, float y = 0.f);

    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    void setXY(float x, float y);
    void draw(PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) const;
};

#endif // POINT2D_H
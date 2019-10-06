#ifndef POINT_H
#define POINT_H
#include <SFML/Graphics.hpp>

class Point
{
public:
    Point();
    Point(float x, float y, int _r, int _g, int _b);
    void draw(sf::RenderWindow& window);
private:
    sf::Color color;
    float _x;
    float _y;
};

#endif // POINT_H

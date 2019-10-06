#include "point.h"

Point::Point()
{
    _x = 0;
    _y = 0;
}

Point::Point(float x, float y, int _r, int _g, int _b):_x(x), _y(y), color(sf::Color(_r, _g, _b))
{
    //nothing needs be here.
}
void Point::draw(sf::RenderWindow &window)
{
    sf::CircleShape c(1);
    c.setPosition(sf::Vector2f(_x, _y));
    c.setFillColor(color);
    window.draw(c);
}

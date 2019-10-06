#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "sidebar.h"

class calculator
{
public:
    calculator();
    void run();
    void render();
    void processEvents();
    void Draw();
private:
    sf::RenderWindow window;
    sf::RectangleShape sidebar;
    sf::RectangleShape _xLine;
    sf::RectangleShape _yLine;
    Grid system;
    int command;
    sf::Font font;
    sf::Text myText;
    Sidebar _sidebar;
};

#endif // CALCULATOR_H

#include "calculator.h"
#include "constants.h"

using namespace std;

calculator::calculator():_sidebar(WORK_PANEL, SIDE_BAR)
{
    window.create(sf::VideoMode(SCREEN_WITH, SCREEN_HEIGHT), "GRAPHING CALCULATOR!!");

    window.setFramerateLimit(60);

    if (!font.loadFromFile("times.ttf"))
    {
        cout << "Game() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }

    //grid lines for the x and y plane.
    _xLine.setFillColor(sf::Color(150,150,150));
    _xLine.setSize(sf::Vector2f(SCREEN_WITH - SIDE_BAR, 1));
    _xLine.setPosition(sf::Vector2f(0, SCREEN_HEIGHT/2));
    _yLine.setFillColor(sf::Color(150,150,150));
    _yLine.setSize(sf::Vector2f(1, SCREEN_HEIGHT));
    _yLine.setPosition(sf::Vector2f((SCREEN_WITH - SIDE_BAR)/2, 0));

    myText = sf::Text("Initial String for myText", font);
    myText.setCharacterSize(12);
    myText.setStyle(sf::Text::Bold);
    myText.setColor(sf::Color::Red);
    myText.setPosition(sf::Vector2f(10,SCREEN_HEIGHT - myText.getLocalBounds().height - 5));

}

void calculator::render()
{
    window.clear();
    Draw();
    window.display();
}


//////////////////////////////////////////////////////
/// \brief processEvents - this function will handle
/// events
///
/// //////////////////////////////////////////////////
void calculator::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if((event.mouseButton.x >= 660 && event.mouseButton.x <= 745) &&
                        (event.mouseButton.y >= 165 && event.mouseButton.y <= 185))
                {

                    system.Clear();
                    system.setUp();
                }
                else if((event.mouseButton.x >= 660 && event.mouseButton.y <= 745) &&
                        (event.mouseButton.y >= 190 && event.mouseButton.y <= 210))
                {
                    system.Clear();
                    system.zoom();
                }
                else if((event.mouseButton.x >= 660 && event.mouseButton.y <= 745) &&
                        (event.mouseButton.y >= 215 && event.mouseButton.y <= 235))
                {
                    system.Clear();
                    system.zoomOut();
                }
                else if((event.mouseButton.x >= 660 && event.mouseButton.y <= 745) &&
                        (event.mouseButton.y >= 240 && event.mouseButton.y <= 260))
                {
                    system.Clear();
                }
                else if((event.mouseButton.x >= 660 && event.mouseButton.y <= 745) &&
                        (event.mouseButton.y >= 265 && event.mouseButton.y <= 285))
                {
                    system.Clear();
                    system.preSets(0);
                    system.plotting();
                }
                else if((event.mouseButton.x >= 660 && event.mouseButton.y <= 745) &&
                        (event.mouseButton.y >= 290 && event.mouseButton.y <= 310))
                {
                    system.Clear();
                    system.preSets(1);
                    system.plotting();
                }
                else if((event.mouseButton.x >= 660 && event.mouseButton.y <= 745) &&
                        (event.mouseButton.y >= 315 && event.mouseButton.y <= 335))
                {
                    system.Clear();
                    system.preSets(2);
                    system.plotting();
                }
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
                std::cout << "Mouse button Right pressed!" << std::endl;
            else if(event.mouseButton.button == sf::Mouse::Middle)
                std::cout << "Mouse button Middle has been pressed!" << std::endl;
        }



        // "close requested" event: we close the window
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Return)
                window.close();
        }
        if(event.type == sf::Event::Closed)
            window.close();
    }
}

void calculator::run()
{
    while(window.isOpen())
    {
        processEvents();
        render(); //clear/draw/display
    }
}

void calculator::Draw()
{
    system.draw(window);
    window.draw(_xLine);
    window.draw(_yLine);
    _sidebar.draw(window);
}

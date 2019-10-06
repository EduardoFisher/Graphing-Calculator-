#include "grid.h"
#include <iostream>
#include "constants.h"

Grid::Grid()
{
    End = 50;
    Start = -50;

    preSet.push_back("sin(x)*cos(200x)");
    preSet.push_back("sin(cos(tan(x)))");
    preSet.push_back("sin(200x)");
}

void Grid::polar2Pixel(double &x, double &y, double i)
{
    y = origin_y + y * y_scale * sin(y);
    x = origin_x + x * x_scale * cos(x);
}

void Grid::real2Pixel(double &x, double &y)
{
    y = origin_y + y * y_scale;
    x = origin_x + x * x_scale;

}

void Grid::Clear()
{
    for(int i = 0; i < size(); i++)
    {
        delete _grid.at(i);
    }
    _grid.clear();
}

int Grid::size()
{
    return _grid.size();
}

void Grid::zoom()
{
    Start /= 2;
    End /= 2;
    _scale = _scale * 2;
    plotting();

}

void Grid::preSets(int i)
{
    eq = getPreSet(i);
}

void Grid::zoomOut()
{
    Start *= 2;
    End *= 2;
    _scale = _scale / 2;
    plotting();
}

void Grid::setUp()
{
    cout << "y = ";
    getline(cin, eq);
    plotting();
}

//work in progress
void Grid::plottingPolar()
{
    _scale = (WORK_PANEL - 0) / (End - Start);
    //this is the range we are plotting: eg: -50..+50
    double add_value = (End - Start) / NUMBER_OF_POINTS;

    x_scale = _scale;
    y_scale = -1*(_scale);
    origin_x = (WORK_PANEL - 0) / 2 ;
    origin_y = (SCREEN_HEIGHT - 0) / 2;

    for(double i = 0; i <= 2*M_PI; i += add_value)
    {
        double x = i;

        theShunting = input(eq, x);
        theShunting = Shunting_Yard(theShunting);
        double y = RPN(theShunting);

        polar2Pixel(x, y, i);
        p = new Point(x, y , 170, 66, 244);
        _grid.push_back(p);
    }
}

void Grid::plotting()
{
    _scale = (WORK_PANEL - 0) / (End - Start);
    //this is the range we are plotting: eg: -50..+50
    double add_value = (End - Start) / NUMBER_OF_POINTS;

    x_scale = _scale;
    y_scale = -1*(_scale);
    origin_x = (WORK_PANEL - 0) / 2 ;
    origin_y = (SCREEN_HEIGHT - 0) / 2;

    for(double i = Start; i <= End; i += add_value)
    {
        double x = i;

        theShunting = input(eq, x);
        theShunting = Shunting_Yard(theShunting);
        double y = RPN(theShunting);

        real2Pixel(x, y);
        p = new Point(x, y , 170, 66, 244);
        _grid.push_back(p);
    }
}

void Grid::draw(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    for(int i = 0; i < size(); i++)
    {
        _grid.at(i)->draw(window);
    }

}

string Grid::getPreSet(int i)
{
    return preSet.at(i);
}

#ifndef SYSTEM_H
#define SYSTEM_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "point.h"
#include "../../../CS2/CS3A/Shunting_Yard/s_yard.h"


using namespace std;

class Grid
{
public:
    Grid();
    void Clear();
    void real2Pixel(double &x, double &y);
    void zoom();
    void zoomOut();
    void setUp();
    void plotting();
    void plottingPolar();
    void polar2Pixel(double &x, double &y, double i);
    void preSets(int i);
    void reset();
    int size();
    void draw(sf::RenderWindow &window);
    string getEq(int i);
    string getPreSet(int i);

private:
    vector<Point*> _grid;
    vector<Point*> _grid2;
    vector<Point*> _grid3;
    string eq;
//    vector<string> eq;
    vector<string> preSet;
    float Start, End;
    double _scale;
    double x_scale, y_scale;
    double origin_x;
    double origin_y;
    bool isPolar;

    Queue<Token*> theShunting;
    Point *p;


};

#endif // SYSTEM_H


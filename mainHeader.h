#ifndef MAINHEADER_H_INCLUDED
#define MAINHEADER_H_INCLUDED
#include <iostream>
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct Position{
    int x;
    int y;
    int manhDist(const Position& other) const {
        return abs(x-other.x)+abs(y-other.y);
    }//apostash Manhattan
};

struct Parameters{
    long seed=-1;
    //an to seed arnhtiko, tha parw thn wra tou systhmatos
    int dimX=40;
    int dimY=40;
    int numMovingCars=3;
    int numMovingBikes=4;
    int numParkedCars=5;
    int numStopSigns=2;
    int numTrafficLights=2;
    int simulationTicks=100;
    float minConfidenceThreshold=40;//einai pososto, 40%
    vector<Position> target;
};
class Grid;

class WorldObject{
protected:
    string id;
    int counter=0;
    Position pos;
    char glyph;
    int ticks;
public:
    WorldObject(const string& i,int c, const Position& p, const char& g, int t): id(i), counter(c), pos(p),glyph(g),ticks(t){}
    virtual ~WorldObject()=default;

    virtual string getType() const=0;
    virtual void update(int tick, Grid& gr) const=0;

    void setId(const string& i){id=i;}
    string getId()const {return id;}

    void setCounter(int c){counter=c;}
    int getCounter() {return counter;}

    void setPosition(const Position& p){pos=p;}
    Position getPosition()const {return pos;}

    void setGlyph(const char& g){glyph=g;}
    char getGlyph()const {return glyph;}

    void setTicks(int t){ticks=t;}
    int getGlyph() {return glyph;}
};

class MovingObject: public WorldObject{
};

class StaticObject: public WorldObject{
};

class StationaryVehicle: public StaticObject{
};

class TrafficSign: public StaticObject{
};

class TrafficLights: public StaticObject{
private:
    string color;
};

#endif // MAINHEADER_H_INCLUDED
/*
void printHelp()
{
cout << " Self−Driving Car Simulation " << endl ;
cout << " Usage : " << endl ;
cout << " −− seed <n> Random seed (default: current time)" << endl ;
cout << " −−dimX <n> World width (default: 40)" << endl ;
cout << " −−dimY <n> World height (default: 40)" << endl ;
cout << " −−numMovingCars <n> Number of moving cars (default: 3)" << endl ;
cout << " −−numMovingBikes <n> Number of moving bikes (default: 4)" << endl ;
cout << " −−numParkedCars <n> Number of parked cars (default: 5)" << endl ;
cout << " −− numStopSigns <n> Number of stop signs (default: 2)" << endl ;
cout << " −− numTrafficLights <n> Number of traffic lights (default: 2)" << endl ;
cout << " −− simulationTicks <n> Maximum simulation ticks (default: 100)" << endl ;
cout << " −− minConfidenceThreshold <n> Minimum confidence cutoff (default: 40)" << endl ;
cout << " −− gps <x1 > <y1 > [ x2 y2 . . . ] GPS target coordinates (required)" << endl ;
cout << " −− help     Show this help message" << endl << endl ;
cout << " Example usage: " << endl ;
cout << " ./oopproj_2025 −− seed 12 −−dimY 50 −− gps 10 20 32 15 " << endl ;
}
*/

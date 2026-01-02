#ifndef MAINHEADER_H_INCLUDED
#define MAINHEADER_H_INCLUDED
#include <iostream>
#include <cmath>
#include <iostream>
#include <vector>

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
    int id=0;
    Position pos;
    char glyph;
public:
    WorldObject(const Position& p, const char& g): pos(p),glyph(g){}
    virtual ~WorldObject()=default;

    virtual string getType() const=0;
//    virtual void update(int tick, Grid& gr) const=

    void setPosition(const Position& p){pos=p;}
    Position getPosition()const {return pos;}

    void setGlyph(const char& g){glyph=g;}
    char getGlyph()const {return glyph;}

};

class MovingObjects: public WorldObject{
private:
    Position direction;
    double speed;
public:
     MovingObjects(const Position& p, const char& g, const Position& d, const double& s): pos(p), glyph(g), direction(d), speed(s) {cout<<"[+OBJECT:"+(id++)+"]"<<endl;}
    ~MovingObjects(){cout<<"[-OBJECT:"+(id--)+"]"<<endl;}

    void setDirection(const Position& d){direction=d;}
    Position getDirection()const {return direction;}

    void setSpeed(const double& s){speed=s;}
    double getSpeed(){return speed;}

};

class StaticObjects: public WorldObject{

public:
    StaticObjects(const Position& p, const char& g): pos(p),glyph(g){}
    virtual ~StaticObjects()=default;
};

class StationaryVehicles: public StaticObject{

public:
    StationaryVehicles(const Position& p, const char& g): pos(p),glyph(g){cout<<"[+VEHICLE:"+(id++)+"]"<<endl;}
    ~StationaryVehicles(){cout<<"[-VEHICLE:"+(id--)+"]"<<endl;}
};

class TrafficSigns: public StaticObject{
private:
    string info;//info είναι το κείμενο, η πληροφορία που μεταδίδουν οι πινακίδες
public:

    TrafficSigns(const Position& p, const char& g, const string& info): pos(p),glyph(g), info (i){cout<<"[+SIGN:"+(id++)+"]"<<endl;}
    ~TrafficSigns(){cout<<"[-SIGN:"+(id--)+"]"<<endl;}

    void setInfo(const string& i){info=i;}
    string getInfo(){return info;}
};

class TrafficLights: public StaticObject{
private:
    string color;
public:
     TrafficLights(const Position& p, const char& g, const string& c): pos(p),glyph(g), color (c){cout<<"[+LIGHT:"+(id++)+"]"<<endl;}
    ~TrafficLights(){cout<<"[-LIGHT:"+(id--)+"]"<<endl;}

    void setColor(string c){
        while (color!="RED" && color !="YELLOW" && color !="GREEN"){
            cout<<"Incorrect color, it can be RED, YELLOW or GREEN. Try again!"<<endl;
            cin>>c;
        }
        color=c;
    }
    string getColor(){return color;}
};

#endif // MAINHEADER_H_INCLUDED

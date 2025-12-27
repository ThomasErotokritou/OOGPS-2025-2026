#include <iostream>
#include "mainHeader.h"

using namespace std;

void printHelp();

int main(int argc, char* argv[])
{
    Parameters param;

    if (argc<2) {
        cout << " Example usage: " << endl ;
        cout << " ./oopproj_2025 −− seed 12 −−dimY 50 −− gps 10 20 32 15 " << endl ;
        exit (0);
    }
    for (int i=1;i<argc;i++){
        string s=argv[i];
        if (s=="--help"){
            printHelp();
            exit (0);
        }
        else if (s=="--seed" && i+1<argc){
            param.seed=stoi(argv[++i]);
        }
        else if(s=="--dimX" && i+1<argc){
            param.dimX=stoi(argv[++i]);
        }
        else if(s=="--dimY" && i+1<argc){
            param.dimY=stoi(argv[++i]);
        }
        else if(s=="--numMovingCars" && i+1<argc){
            param.numMovingCars=stoi(argv[++i]);
        }
        else if(s=="--numMovingBikes" && i+1<argc){
            param.numMovingBikes=stoi(argv[++i]);
        }
        else if(s=="--numStopSigns" && i+1<argc){
            param.numStopSigns=stoi(argv[++i]);
        }
        else if(s=="--numTrafficLights" && i+1<argc){
            param.numTrafficLights=stoi(argv[++i]);
        }
        else if(s=="--simulationTicks" && i+1<argc){
            param.simulationTicks=stoi(argv[++i]);
        }
        else if(s=="--minConfidenceThreshold" && i+1<argc){
            param.minConfidenceThreshold=stoi(argv[++i]);
        }

        else if(s=="--gps"){
            while (i+2<argc){
                int x=stoi(argv[i+1]);
                int y=stoi(argv[i+2]);
                param.target.push_back({x,y});
                i+=2;
            }
        }
    }
    if (param.target.empty()){
        cerr<<"Error: no GPS coordinates were given"<<endl;
        printHelp();
        exit(1);
    }
    return 0;
}

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

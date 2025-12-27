#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;




void SetMap(char world[width][height]){

    for (int i =0; i< height; i++){
        for (int j=0; j< height; j++){
            if ( i==0 || j==0 || i==width-1 || j==height-1)
            world[i][j]='X';
            
            else
            world[i][j]='.';
        }
    }
}


int main(int argc, char* argv[]) {

bool bseed=0, dimX=0, dimY=0,MovingCars=0, MovingBikes=0, ParkedCars=0, stopSigns=0,TrafficLights=0, SimulationTicks=0, Confidence=0, HELP=0;

int  seed, width, height, Mcars,Mbikes, Pcars, SSigns, TLights, Ticks, conf;
cout<<"Please Give the parameters of the simulation:\n";

for ( int i=0; i <argc; i++) {
    if( argv[i]== "--seed"){
        bseed=1;
        i++;
        seed=stoi(argv[i]);
    } 

    else if (argv[i]== "--dimX"){
        dimX=1;
        i++;
        width=stoi(argv[i]);
    }
    else if(argv[i]== "--dimY"){
        dimY=1;
        i++;
        height=stoi(argv[i]);

    }
    else if( argv[i]== "--numMovingCars")
    {
        MovingCars=1;
        i++;
        Mcars=stoi(argv[i]);
    }
    else if (argv[i]== "--numMovingBikes"){
        MovingBikes=1;
        i++;
        Mbikes=stoi(argv[i]);
    }
    else if (argv[i]== "--numParkedCars"){
        ParkedCars=1;
        i++;
        Pcars=stoi (argv[i]);
            }
    

    else if(argv[i]== "--numStopSigns"){
        stopSigns=1;
        i++;
        SSigns=stoi(argv[i]);
    }
    else if (argv[i]=="--numTraficLights"){
        TrafficLights=1;
        i++;
        TLights=stoi(argv[i]);

    }
    else if ( argv[i]=="--SimulationTicks"){
        i++;
        Ticks=stoi(argv[i]);
        SimulationTicks=1;
    }

    else if     








}





char world[width][height];

SetMap(world);
























    return 0;
}
#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

 bool ISNUM (string x, int len){ //είναι μια συνάρτηση για να ελεγχουμε αν ένα string είναι δημιουργημενο απο αριθμούς
    if(x[0]== '\0' || x[0]==' ')
        return false;

    int start=0;
    while (x[start]=='-')
    start++;

    bool apo=1;

    for (int i=start; i<len; i++){
    if (!(x[i]>=48 && x[i]<=57))
        apo=0;
    
    }
    return apo;
 }






int main(int argc, char* argv[]) {

bool bseed=0, dimX=0, dimY=0,MovingCars=0, MovingBikes=0, ParkedCars=0, stopSigns=0,TrafficLights=0, SimulationTicks=0, Confidence=0, gpss;
// χρησιμοποιούμαι boolean μεταβλήτες για να δούμε αν αλλαξαν τις παραμέτρους τους. Αν ο χρήστης δεν άλλαξε τις παραμέτρους τοτε θα χρησιμοποιησουμε τις default
//τιμες που μας δίνει η οδηγία


vector<int> x[1],y[1];
//χρησιμοποιούμε vectors για την αποθήκευση των συντέταγμενων που θα δώσει ο χρήστης διοτι δεν γνωρίζουμε πόσες συντενταγμένες θα μας δώσει



int  seed, width, height, Mcars,Mbikes, Pcars, SSigns, TLights, Ticks, conf; // αποθήκευση των παραμέτρων από τον χρήστη.
string argu;
for ( int i=1; i <argc; i++) {
    
    argu=argv[i];

    if( argu== "--seed"){
        bseed=1; //ορίζουμε την boolean μεταβλητή σαν 1 ή true έτσι ώστε μέτα να ξέρουμε πως ο χρήστης χρησιμοποίησε δικια του παραμετρο.
        if(i+1==argc)
            cout<<"You did something wrong:1"<<endl;
        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
        
            seed=stoi(argv[i+1]);
        } 

    else if (argu== "--dimX"){
        dimX=1;
        if(i+1==argc)
            cout<<"You did something wrong:2"<<endl;
        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
            width=stoi(argv[i+1]);
    }
    else if(argu== "--dimY"){
        dimY=1;
        if(i+1==argc)
            cout<<"You did something wrong:3"<<endl;
        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
             height=stoi(argv[i+1]);

    }
    else if( argu== "--numMovingCars")
    {
        MovingCars=1;
       if(i+1==argc)
            cout<<"You did something wrong:4"<<endl;
        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
            Mcars=stoi(argv[i+1]);
    }
    else if (argu== "--numMovingBikes"){
        MovingBikes=1;
        if(i+1==argc)
            cout<<"You did something wrong:5"<<endl;
        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
        Mbikes=stoi(argv[i+1]);
    }
    else if (argu== "--numParkedCars"){
        ParkedCars=1;
        if(i+1==argc)
            cout<<"You did something wrong:6"<<endl;
        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
            Pcars=stoi (argv[i+1]);
            }
    

    else if(argu== "--numStopSigns"){
        stopSigns=1;

        if(i+1==argc)

            cout<<"You did something wrong:7"<<endl;

        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
            SSigns=stoi(argv[i+1]);
    }
    else if (argu=="--numTraficLights"){
        TrafficLights=1;
        if(i+1==argc)

            cout<<"You did something wrong:8"<<endl;

        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
        TLights=stoi(argv[i+1]);

    }
    else if ( argu=="--SimulationTicks"){
        if(i+1==argc)
            cout<<"You did something wrong:9"<<endl;
        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
            Ticks=stoi(argv[i+1]);
        SimulationTicks=1;
    }

    else if (argu=="--minConfidenceThreshold")    
    {
        if(i+1==argc)
            cout<<"You did something wrong:10"<<endl;
        else if(ISNUM(argv[i+1], strlen(argv[i+1])))
            conf=stoi(argv[i+1]);
        Confidence=1;
        

    }
    else if (argu=="--Help"){
        cout<<"Example usage"<<endl<<"./oopproj_2025  --seed 12 --dimY 50  --gps 10 20 32 15 " << endl;


    }
    
    else  if(i+1==argc)
            cout<<"You did something wrong:11"<<endl;
        else if(ISNUM(argv[i+1], strlen(argv[i+1]))){

    }

    else
    cout<<"You did something wrong in the command to operate the program please use the --help"<<endl;
    return 0;
}
// bool bseed=0, dimX=0, dimY=0,MovingCars=0, MovingBikes=0, ParkedCars=0, stopSigns=0,TrafficLights=0, SimulationTicks=0, Confidence=0, HELP=0;
// int  seed, width, height, Mcars,Mbikes, Pcars, SSigns, TLights, Ticks, conf;

if (bseed==0)

if (!dimX)
    width = 40;
if (!dimY)
    height = 40;
if (!MovingCars)
    Mcars = 3;
if (!MovingBikes)
    Mbikes = 4;
if (!ParkedCars)
    Pcars = 5;
if(!stopSigns)
    SSigns =2;
if (!TrafficLights)
    TLights =2;
if (!SimulationTicks)
    Ticks = 100;
if (!Confidence)
    conf = 40;
if (!gpss){
    cout<<"GPS COORDINATIONS ARE MANDATORY FOR THE PROGRAM TO OPERATE";
    return 0;
}





    return 0;
}
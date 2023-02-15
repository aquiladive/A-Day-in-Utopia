#pragma once
#include <iostream>
#include "Classes.cpp"
#include "Battle.cpp"
#include "ADayinUtopia.cpp"
using namespace std;

//--

int eventCounter[7];

//--

int valid(string save);
int load(string save);
string generateSave(int pos);

int arrayDegradation(string save);

//--

int valid(string save) {
    if(save=="7745")
        return 1;
    else if((save[0]=='y' || save[0]=='t' || save[0]=='d') && arrayDegradation(save)==1) {
        return 1;
    }
    else
        return 0;
}

int load(string save) {
    if(save=="7745")
        return 1;
    else if(save[0]=='y') {
        if(eventCounter[0]==2) {
            inventoryCount++;
            inventory[0]=bottle;
        }
        return 2;
    }
    else if(save[0]=='t') {
        if(eventCounter[0]==2) {
            inventory[inventoryCount]=bottle;
            inventoryCount++;
        }
        if(eventCounter[0]>2) {
            inventory[inventoryCount]=emblem;
            inventoryCount++;
        }
        beliefBenefits(eventCounter[2]);
        return 3;
    }
    else if(save[0]=='d') {
        if(eventCounter[0]==2) {
            inventory[inventoryCount]=bottle;
            inventoryCount++;
        }
        if(eventCounter[0]>2) {
            inventory[inventoryCount]=emblem;
            inventoryCount++;
        }
        return 4;
    }
}

int arrayDegradation(string save) {
    //the opposite of generateSave
    //to be changed as more event counters are added
    int length, i;
    if(save[0]=='y' && save.length()==7) {
        length=2;
        for(i=0;i<length;i++) {
            if(save[i+2]=='L')
                eventCounter[i]=0;
            else if(save[i+2]=='5')
                eventCounter[i]=1;
            else if(save[i+2]=='3')
                eventCounter[i]=2;
            else if(save[i+2]=='m')
                eventCounter[i]=3;
            else
                return 0; //immediately marking code as invalid
        }
        return 1;
    }
    
    else if(save[0]=='t' && save.length()==7) {
        length=5;
        for(i=0;i<length;i++) {
            if(save[i+2]=='L')
                eventCounter[i]=0;
            else if(save[i+2]=='5')
                eventCounter[i]=1;
            else if(save[i+2]=='3')
                eventCounter[i]=2;
            else if(save[i+2]=='m')
                eventCounter[i]=3;
            else if(save[i+2]=='z')
                eventCounter[i]=4;
            else if(save[i+2]=='D')
                eventCounter[i]=5;
            else if(save[i+2]=='2')
                eventCounter[i]=6;
            else
                return 0;
        }
        if((eventCounter[2]<6 || eventCounter[0]==3) && eventCounter[4]==1)
            return 1;
        else if(eventCounter[4]==0)
            return 1;
        else
        //this means that if the player is atheist *and* has not saved Lana, it is impossible for them to perfect the fifth event (ie [4]=1)
            return 0;
    }
    
    else if(save[0]=='d' && save.length()==8) {
        length=6;
        for(i=0;i<length;i++) {
            if(save[i+2]=='L')
                eventCounter[i]=0;
            else if(save[i+2]=='5')
                eventCounter[i]=1;
            else if(save[i+2]=='3')
                eventCounter[i]=2;
            else if(save[i+2]=='m')
                eventCounter[i]=3;
            else if(save[i+2]=='z')
                eventCounter[i]=4;
            else if(save[i+2]=='D')
                eventCounter[i]=5;
            else if(save[i+2]=='2')
                eventCounter[i]=6;
            else
                return 0;
        }
        if(eventCounter[0]<3 && eventCounter[2]==6 && eventCounter[4]==1)
            return 0;
        else
            return 1;
    }
    
    else
        return 0;
}

string generateSave(int pos) {
    //to be changed as more event counters are added
    int length, i;
    string save;
    switch(pos) {
        case 1:
        length=2;
        save="yhArNam";
        break;
        
        case 2:
        length=4;
        save="tiAnzUn";
        break;
        
        case 3:
        length=6;
        save="dooMsdaY";
        break;
    }
    for(i=0;i<length;i++) {
        if(eventCounter[i]==0)
            save[i+2]='L';
        else if(eventCounter[i]==1)
            save[i+2]='5';
        else if(eventCounter[i]==2)
            save[i+2]='3';
        else if(eventCounter[i]==3)
            save[i+2]='m';
        else if(eventCounter[i]==4)
            save[i+2]='z';
        else if(eventCounter[i]==5)
            save[i+2]='D';
        else if(eventCounter[i]==6)
            save[i+2]='2';
    }
    return save;
}


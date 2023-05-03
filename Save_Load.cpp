#pragma once
#include <iostream>
#include "Classes.cpp"
#include "Battle.cpp"
#include "ADayinUtopia.cpp"
using namespace std;

//--

int eventCounter[7];
int saveLoc;
char first;

//--

int valid(fstream& file);
int load(char first);
void generateSave(int pos);

int arrayDegradation(fstream& file);

//--

int valid(fstream& file) {
    file>>first;
    if(first=='7')
        return 1;
    else if((first=='y' || first=='t' || first=='d') && arrayDegradation(file)==1) {
        return 1;
    }
    else
        return 0;
}

int load() {
    if(first=='7')
        return 1;
    else if(first=='y')
        return 2;
    else if(first=='t') {
        beliefBenefits(eventCounter[2]);
        return 3;
    }
    else if(first=='d') {
        beliefBenefits(eventCounter[2]);
        return 4;
    }
    else
        return 0;
}

int arrayDegradation(fstream& file) {
    //the opposite of generateSave
    //to be changed as more event counters are added
    int i=0, stop=1;
    char letter;
    //loading eventCounter
    while(!file.eof()) {
        file>>letter;
        if(letter=='L')
            eventCounter[i]=0;
        else if(letter=='5')
            eventCounter[i]=1;
        else if(letter=='3')
            eventCounter[i]=2;
        else if(letter=='m')
            eventCounter[i]=3;
        else if(letter=='n')
            eventCounter[i]=4;
        else if(letter=='G')
            eventCounter[i]=5;
        else if(letter=='2')
            eventCounter[i]=6;
        else if(letter=='R')
            eventCounter[i]=7;
        else if(letter=='w')
            eventCounter[i]=8;
        else if(letter=='b')
            eventCounter[i]=9;
        else if(letter=='|')
            break;
        else
            stop=0;
        i++;
    }
    //loading inventory
    i=0;
    file>>letter;
    while(!file.eof()) {
        if(letter=='b')
            inventory[i]=bottle;
        else if(letter=='e')
            inventory[i]=emblem;
        else if(letter=='m')
            inventory[i]=map;
        else if(letter=='s')
            inventory[i]=slime;
        else if(letter=='|')
            break;
        else
            stop=0;
        i++;
        inventoryCount=i;
        file>>letter;
    }
    return stop;
    //find a way to load character level + stats
}

void generateSave(int pos) {
    //to be changed as more event counters are added
    char first, code;
    int i, length;
    fstream file;
    switch(saveLoc) {
        case 1: file.open("save_1.txt",ios::trunc | ios::out);
        break;
        case 2: file.open("save_2.txt",ios::trunc | ios::out);
        break;
        case 3: file.open("save_3.txt",ios::trunc | ios::out);
        break;
    }

    switch(pos) {
        case 0:
        length=0;
        first='7';
        break;

        case 1:
        length=2;
        first='y';
        break;
        
        case 2:
        length=5;
        first='t';
        break;
        
        case 3:
        length=5;
        first='d';
        break;
    }
    file<<first;
    for(i=0;i<length;i++) {
        if(eventCounter[i]==0)
            code='L';
        else if(eventCounter[i]==1)
            code='5';
        else if(eventCounter[i]==2)
            code='3';
        else if(eventCounter[i]==3)
            code='m';
        else if(eventCounter[i]==4)
            code='n';
        else if(eventCounter[i]==5)
            code='G';
        else if(eventCounter[i]==6)
            code='2';
        else if(eventCounter[i]==7)
            code='R';
        else if(eventCounter[i]==8)
            code='w';
        else if(eventCounter[i]==9)
            code='b';
        file<<code;
    }
    file<<'|';
    if(inventoryCount>0) {
        for(i=0;i<inventoryCount;i++) {
            if(inventory[i].itemName=="bottle of essential scent")
                code='b';
            else if(inventory[i].itemName=="Lana's emblem")
                code='e';
            else if(inventory[i].itemName=="map")
                code='m';
            else if(inventory[i].itemName=="slime remnant")
                code='s';
            file<<code;
        }
        file<<'|';
    }
    file.close();
}
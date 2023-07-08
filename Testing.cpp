#pragma once
#include<iostream>
#include "Classes.cpp"
#include "Battle.cpp"
using namespace std;

//--

void battleMechanic(int opponents[]);
int yn();

//--


int battleTest() {
    int testchoice, n;
    cout<<"Battle testing mode."<<endl;
    mainchar.Name="Arcelia";
    cout<<"Insert character level."<<endl;
    cin>>mainchar.Level;
    mainchar.HP=25;
    mainchar.ATK=mainchar.DEF=mainchar.MDEF=mainchar.MATK=mainchar.LUCK=5;
    statAllocation(mainchar.Level*5);
    cout<<"Do you wish to: 1) create battle, 2) randomise battle?"<<endl;
    cin>>testchoice;
    if(testchoice==1) {
        cout<<"Enter number of enemies."<<endl;
        cin>>n;
        int opp[n+1];
        opp[0]=n;
        cout<<"Enter enemy designation."<<endl;
        for(int i=1;i<n+1;i++)
            cin>>opp[i];
        battleMechanic(opp);
    }
    else if(testchoice==2) {
        srand(time(0));
        int number=rand()%4+1;
        int opponents[number+1];
        opponents[0]=number;
        for(int i=1;i<number+1;i++)
            opponents[i]=rand()%3+1;
        battleMechanic(opponents);
    }
    else
        cout<<"Invalid choice."<<endl;
    
    cout<<"Would you like to continue testing?"<<endl;
    return yn();
}
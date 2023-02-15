#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib> //ctime and cstdlib used for the srand(time(0)) and rand(), which are used in Monster's attack()
using namespace std;

class Character {
    public:
    int HP, DEF, ATK, MATK, MDEF, LUCK;
    string Name,Status;
    Character() {
        //only Monster array initialisation
    }
    Character (string n, int x, int y, int z, int i, int j, int k) {
        Name=n;
        HP=x;
        ATK=y;
        DEF=z;
        MATK=i;
        MDEF=j;
        LUCK=k;
    }
    virtual int attack()=0;
};

class NPC: private Character {
    using Character::Character; //copies the constructor from Character
    int attack() {
        return ATK;
    }
    //using NPC instead of directly using Character because as it has a virtual function, direct objects are not allowed
    //the virtual function is important because it's defined differently for Protag and for Monster
    //private because NPC details don't need to be changed by anything in the program
};

class Protag: public Character {
    using Character::Character;
    public:
    int Level=1;
    int battleExp=0;
    int attack() {
        return ATK;
    }
};

//--

int monsterChoice; //for the monster attack function and allowing it to be accessed by the battleMechanic() function

class Monster: public Character {
    using Character::Character;
    public:
    string mattack1="\0", mattack1effect="\0";
    string mattack2="\0", mattack2effect="\0";
    int exppoint=0;
    //all new public members are initialised to null as they are properly initialised in battleMechanic()
    
    int attack() {
        int choice, damage=0;
        srand(time(0));
        choice=rand()%3+1;
        monsterChoice=choice;
        switch(choice) {
            case 1:
            cout<<Name<<" attacks."<<endl;
            damage=ATK;
            break;
                
            case 2:
            cout<<Name<<" uses "<<mattack1<<endl;       
            damage=MATK;
            break;
                
            case 3:
            cout<<Name<<" uses "<<mattack2<<endl;
            damage=MATK;
            break;
        }
        return damage;
    }
};

class Item {
    public:
    string itemName, Description;
    int useCount;
    Item() {
        //only for inventory initialisation
    }
    Item(string i, string d, int u) {
        itemName=i;
        Description=d;
        useCount=u;
    }
    void obtain() {
        cout<<"You have obtained "<<itemName<<"."<<endl;
    }
    void clear() {
        itemName="\0";
        Description="\0";
    }
};

//--

Protag mainchar("\0",25,5,5,5,5,5);
NPC Azik("Mr. Azik", 100,50,50,50,50,50);
NPC Lana("Lana",40,7,7,9,9,5);

//--

Monster Bounceshroom("Bounceshroom",6,9,1,10,5,0);
Monster DarkWolf("Dark Wolf",12,15,4,10,3,2);

//--

Item inventory[5];
int inventoryCount;

Item bottle("bottle of essential scent","A gift from the second mate. It contains a mixture that can soothe seasickness on inhaling.",1);
Item emblem("Lana's emblem","Given to you by Lana. It can be used by squeezing it and shouting \"Light\".",5);
int emblemUse; //tracks the breaking point of the emblem

//--
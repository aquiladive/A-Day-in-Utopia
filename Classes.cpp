#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib> //ctime and cstdlib used for the srand(time(0)) and rand())
using namespace std;

class Character {
    public:
    int HP, MP, DEF, ATK, MATK, MDEF, LUCK;
    string Name,Status[4];
    Character() {
        //only Monster array initialisation
    }
    Character (string n, int a, int b, int x, int y, int z, int i, int j) {
        Name=n;
        HP=a;
        MP=b;
        ATK=x;
        DEF=y;
        MATK=z;
        MDEF=i;
        LUCK=j;
    }
    virtual int attack()=0;
};

class NPC: public Character {
    using Character::Character; //copies the constructor from Character
    public:
    int attack() {
        int choice=rand()%4+1;
        return choice;
    }
};

class Protag: public Character {
    using Character::Character;
    public:
    int Level=1;
    int battleExp=0;
    int Beyonder[2];
    string Path;
    
    int attack() {
        return ATK;
    }

    int beyonder(int belief) {
        if(belief==1) {
            //evernight
            int pathway=rand()%3+1;
            switch(pathway) {
                case 1: Beyonder[0]=1;
                Path="Sleepless";
                break;
                case 2: Beyonder[0]=2;
                Path="Corpse Collector";
                break;
                case 3: Beyonder[0]=3;
                Path="Warrior";
                break;
            }
        }
        else if(belief==2) {
            Beyonder[0]=4;
            Path="Sailor";
        }
        else if(belief==3) {
            //lilith
            int pathway=rand()%2+1;
            switch(pathway) {
                case 1: Beyonder[0]=5;
                Path="Apothecary";
                break;
                case 2: Beyonder[0]=6;
                Path="Planter";
                break;
            }
        }
        else if(belief==4) {
            //steam
            int pathway=rand()%2+1;
            switch(pathway) {
                case 1: Beyonder[0]=7;
                Path="Savant";
                break;
                case 2: Beyonder[0]=8;
                Path="Mystery Pryer";
                break;
            }
        }
        else if(belief==5) {
            //fool
            int pathway=rand()%3+1;
            switch(pathway) {
                case 1: Beyonder[0]=9;
                Path="Seer";
                break;
                case 2: Beyonder[0]=10;
                Path="Marauder";
                break;
                case 3: Beyonder[0]=11;
                Path="Apprentice";
                break;
            }
        }
        else {
            //atheist
            int pathway=rand()%3+1;
            switch(pathway) {
                case 1: Beyonder[0]=12;
                Path="Bard"; //sun sequence 9
                break;
                case 2: Beyonder[0]=13;
                Path="Psychologist";
                break;
                case 3: Beyonder[0]=14;
                Path="Secrets Supplicant"; //hanged man sequence 9
                break;
            }
        }
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

Protag mainchar("\0",25,5,5,5,5,5,5);
NPC Azik("Mr. Azik", 100,50,50,50,50,50,50);
NPC Lana("Lana",40,10,7,7,9,9,5);

//--

Monster Bounceshroom("Bounceshroom",6,0,9,1,10,5,0);
Monster Slime("Slime",10,0,7,4,8,6,0);
Monster DarkWolf("Dark Wolf",12,0,15,4,10,3,2);
Monster MetalCube("Metal Cube",10,0,8,10,6,10,0);

//--

Item inventory[9];
int inventoryCount;

Item bottle("bottle of essential scent","A gift from the second mate. It contains a mixture that can soothe seasickness on inhaling.",1);
Item emblem("Lana's emblem","Given to you by Lana. It can be used by squeezing it and shouting \"Light\".",5);
int emblemUse; //tracks the breaking point of the emblem
Item slime("slime remnant","It's a greyish spherical object that has a solid feel, surprising compared to the slimes themselves.",1);
Item map("map", "A sketch made by yourself of Utopia and the path you've taken through it.",0);

//--

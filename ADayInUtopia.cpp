/************************************************************************
 * A Day In Utopia, v.0.0.4

 * Latest changes: Chapter 1 pt 2b continued
 * Current bugs: 1) rudimentary save system
 .               2) string input to integer option
 * (please refer to documentation log for further details)

**************************************************************************/

#pragma once
#include<iostream>
#include "Classes.cpp"
#include "Save_Load.cpp"
#include "Battle.cpp"
#include "Prologue.cpp"
#include "Chapter1_pt1_pt2.cpp"
#include "Chapter1_pt2a.cpp"
#include "Chapter1_pt2b.cpp"
using namespace std;

//--

void Intro(), Entrance();
void openingMenu();
void about();

int yn();
int inventoryCheck();
int inventoryCheckName(string item);

void Tutorial1(), Tutorial2(), Tutorial3(); //1 explains exploration, 2 explains battle, 3 explains stats
void ending1(), ending2();

//--

//--
//misc functions
//--

int yn() {
    char yven;
    cout<<"(insert 'y' for yes or 'n' for no)"<<endl;
    cin>>yven;
    if(yven=='y')
        return 1;
    if(yven=='n')
        return 0;
    else {
        cout<<"Invalid choice."<<endl;
        yn();
    }
}

int inventoryCheck() {
    //for the battle ending protip
    for(int i=0;i<inventoryCount;i++) {
        if(itemUse(inventory[i].itemName)!=0)
            return 1;
    }
    return 0;
}

int inventoryCheckName(string Name) {
    //for knowing if user has a specific item
    for(int i=0;i<inventoryCount;i++) {
        if(inventory[i].itemName==Name)
            return 1;
    }
    return 0;
}

//--

int main()
{
    Intro();
    openingMenu();
    return 0;
}

void Intro() {
    cout<<"For nearly a decade, there have been tales of a mysterious city named Utopia. Its residents are ordinary people, who live ordinary lives, no different from anywhere else."<<endl;
    cout<<"But what sets this city apart is that it does not exist. On no map will you find it, no entrance though the town itself boasts of a port and a railway station. Those who come upon it do so by chance, and leave it the same."<<endl;
    cout<<"One day, all its visitors left, herded out by the local police. After that, no one has heard of the city again."<<endl;
    cout<<"You are an archaelogist from the Loen Kingdom who spent the past few years studying Utopia. Believing at last that you know where it is, you gather a team and set out to find it."<<endl;
    cout<<endl;
    cout<<"But such tales don't spring from the aether, and perhaps it would have been better to leave it alone."<<endl;
    cout<<endl;
    cout<<"Welcome to-"<<endl;
    cout<<"A DAY IN UTOPIA"<<endl;
    cout<<endl;
}

void openingMenu() {
    cout<<"1) Start\t 2) Load"<<endl;
    cout<<"3) About\t 4) Quit"<<endl;
    cout<<"(insert choice)"<<endl;
    int opchoice;
    cin>>opchoice;
    switch (opchoice) {
        case 1:
        Prologue_pt1();
        break;
        
        case 2: {
            cout<<"Insert save code: ";
            string savecode;
            cin>>savecode;

            //the savecode for when I need to test something real quick and can't be bothered to play through the game
            if(savecode=="prototest") {
                eventCounter[4]=0;
                eventCounter[0]=4;
                mainchar.Name="Arcelia";
                mainchar.Level++;
                inventory[0]=emblem;
                inventoryCount++;
                mainchar.ATK+=5;
                Chapter1_pt2b();
            }

            if(valid(savecode)) {
                cout<<"Please enter your name."<<endl;
                cin>>mainchar.Name;
                cout<<endl;
                int position=load(savecode);
                if(position==1)
                    Prologue_pt2();
                else if(position==2)
                    Chapter1_pt1();
                else if(position==3)
                    Chapter1_pt2();
                else {
                    cout<<"\nYou have currently completed the demo."<<endl;
                    cout<<"Please wait until further updates have been added."<<endl;
                }
            }
            else {
                cout<<"Invalid code.\n"<<endl;
                openingMenu();
            }
        }
        break;
        
        case 3:
        about();
        break;
        
        case 4:
        exit(0);
        default:
        cout<<"Invalid choice.\n";
    }
}

void about() {
    cout<<"\n\"A Day in Utopia\" is a transformative non-profit work based on the Chinese webnovel 'Lord of Mysteries' by Cuttlefish That Loves Diving."<<endl;
    cout<<"No copyright infringement is intended, and this work adheres to the principles of fair use."<<endl;
    cout<<"Having gotten that out of the way, A Day in Utopia is a multiple-ending text-adventure RPG. Controls are simple."<<endl;
    cout<<"During the story flow, you may be prompted to input text and make choices."<<endl;
    cout<<"Battles run according to standard JRPG. If you have no experience with it, the in-game tutorial will guide you through your first battle."<<endl;
    cout<<"This is currently only a demo version upto Chapter 1. Hope you enjoy!\n"<<endl;
    openingMenu();
}



//--
// tutorials
//--
void Tutorial1() {
    int tutorial, questtip;
    cout<<"Would you like a short tutorial on this game's exploration aspect?"<<endl;
    tutorial=yn();
    if(tutorial==1) {
        cout<<"Other than the story, this game consists mainly of two playable parts: exploration and battle. In the exploration aspect, you will be able to interact with some items and people."<<endl;
        cout<<"Some interactions do not affect the story. Some do. It may not always be in obvious ways either."<<endl;
        cout<<"Particularly, after certain interactions, options that were previously not available may appear, so go through things twice."<<endl;
        cout<<"For demonstration, would you like to hear of such a situation in this part of the game?"<<endl;
        cout<<"(this is a slight spoiler, but not of much importance)"<<endl;
        questtip=yn();
        if(questtip==1) {
            cout<<"Speak to Mr. Azik and note the available options. Later, after asking the captain about himself, speak to Mr. Azik again and see what happens."<<endl;
            cout<<"[tutorial end]\n"<<endl;
        }
        else
            cout<<"Alright then!\n[tutorial end]\n"<<endl;
    }
    else {
        cout<<endl;
    }
}

void Tutorial2() {
    string blankSpace;
    int tutorial;
    cout<<"You are about to enter a battle. Would you like a short tutorial on this game's battle aspect?"<<endl;
    tutorial=yn();
    if(tutorial==1) {
        cout<<"In battle, the poor archaelogist you are will have to face off against some number of opponents."<<endl;
        cout<<"This is turn-based, starting with your turn."<<endl;
        cout<<"On your turn, you can choose to do one of three things: attack, defend or use an item."<<endl;
        cout<<"Attacking damages the opponent and lowers their health."<<endl;
        cout<<"Defending puts you in a stance where you take less damage from the opponent than you would otherwise."<<endl;
        cout<<"Items can have varied effects, some useful in battle and some not."<<endl;
        if(eventCounter[0]==3)
            cout<<"The emblem from Lana, for example, is a damage-dealing item."<<endl;
        cout<<"However, items have usage limits. Once they reach that limit, they can no longer be used."<<endl;
        cout<<"You will not know the breaking point until it has been reached. So it's good to be careful with item usage, but at the same time, don't stockpile them."<<endl;
        cout<<"They're there to be used."<<endl;
        cout<<"Now go on and protect yourself!"<<endl;
        cout<<"[tutorial end]"<<endl;
        cin>>blankSpace;
        cout<<endl;
    }
    else {
        cout<<endl;
    }
}

void Tutorial3() {
    string blankSpace;
    int tutorial;
    cout<<"By levelling up, you can allocate stat points. Would you like a short tutorial on this?"<<endl;
    tutorial=yn();
    if(tutorial==1) {
        cout<<"After battling opponents, you may feel that you have gotten stronger."<<endl;
        cout<<"This rise in strength is in-game reflected by your level."<<endl;
        cout<<"After every rise in level, you will be given 5 stat points to allocate as you wish."<<endl;
        cout<<"Your character has six main stats:"<<endl;
        cout<<"Health Points (HP) which show the amount of damage you can take and remain standing."<<endl;
        cout<<"Attack (ATK) which show the amount of normal damage you can deal to enemies."<<endl;
        cout<<"Defense (DEF) which helps reduce damage taken from normal attacks."<<endl;
        cout<<"Magic Attack (MATK) which shows the amount of magical damage you can deal to enemies."<<endl;
        cout<<"Magic Defense (MDEF) which helps reduce damage taken from magical attacks."<<endl;
        cout<<"And finally, Luck (LUCK) which has no battle relevance but affects the course of events around you."<<endl;
        cout<<"Each stat has its own importance, so distribute your points wisely."<<endl;
        cout<<"[tutorial end]"<<endl;
        cin>>blankSpace;
        cout<<endl;
    }
    else {
        cout<<endl;
    }
}


//--
//the possible endings
//--
void ending1() {
    string blankSpace;
    cout<<"\n..."<<endl;
    cout<<"The team embarks on the trip to Utopia on schedule the next day. Your radio communication with the Society halts half an hour after you land on the island. None of you return alive."<<endl;
    cout<<"And so Utopia has yet another tale added to its mysteries."<<endl;
    cout<<"THE END"<<endl;
    cout<<"..."<<endl;
    cin>>blankSpace;
    cout<<"Protip: Azik Eggers was not introduced in detail to be ignored."<<endl;
    cout<<"1. Return to Menu\t\t 2. Quit"<<endl;
    int ch;
    cin>>ch;
    if(ch==1)
        openingMenu();
    else
        exit(0);
}

void ending2() {
    string blankSpace;
    cout<<"You attempt to run, but your battered body betrays you."<<endl;
    cout<<"Within a few steps, you stumble and collapse, easy prey for the approaching monsters."<<endl;
    cout<<"Fallen on the ground, you can't see, but you feel the base of their stems press against your bare skin, sandpaper-like rough and drawing blood as they bounce in place. Tears spring to your eyes at each contact."<<endl;
    cout<<"With every bounce, greenish-yellow dust dots the air, some sort of pollen (you've never been a biologist)."<<endl;
    cout<<"You hold your breath instinctively, but with the scorching pain in your body, you can't help your gasps."<<endl;
    cout<<"Your mind slows every second, consciousness hard to hold on to."<<endl;
    cout<<"Then it's your limbs, becoming impossible to feel any longer, numbing your pain."<<endl;
    cout<<"You should be worried, but strangely calm instead, your eyes flutter shut."<<endl;
    cout<<"And so the pollen that falls on you feeds on you, melting through your skin and not leaving even bones behind."<<endl;
    cout<<"A new tale finds its way into the myths of Utopia."<<endl;
    cout<<"THE END"<<endl;
    cout<<"..."<<endl;
    cin>>blankSpace;
    cout<<"Protip: It's good to know when to watch out for others and when to watch out for yourself."<<endl;
    cout<<"1. Return to Menu\t\t 2. Quit"<<endl;
    int ch;
    cin>>ch;
    if(ch==1)
        openingMenu();
    else
        exit(0);
}

void battleEnding() {
    string blankSpace;
    cout<<"\nYou can no longer hold yourself upright."<<endl;
    cout<<"Every breath hurts, and your vision blurs at the edges as darkness takes over."<<endl;
    cout<<"You collapse, consciousness fleeing you to never return, and your body remains forever in the ruins of Utopia."<<endl;
    cout<<"THE END"<<endl;
    cout<<"..."<<endl;
    cin>>blankSpace;
    if(eventCounter[2]==6)
        cout<<"Protip: Believing in a god has benefits when encountering supernatural events."<<endl;
    else if(eventCounter[0]<3)
        cout<<"Protip: Lana's death can be avoided."<<endl;
    else if(inventoryCount>0 && inventoryCheck()!=0)
        cout<<"Protip: There's no use in stockpiling items."<<endl;
    else {
        srand(time(0));
        int tipchoice=rand()%2+1;
        if(tipchoice==1)
            cout<<"Protip: Keep close track of your HP while fighting."<<endl;
        else
            cout<<"Protip: Every battle in this game is winnable with certain play. Try a different track next time."<<endl;
    }
    cout<<"1. Return to Menu\t\t 2. Quit"<<endl;
    int ch;
    cin>>ch;
    if(ch==1)
        openingMenu();
    else
        exit(0);
}

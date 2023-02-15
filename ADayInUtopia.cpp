/************************************************************************
 * A Day In Utopia, v.0.0.3

 * Latest changes: Chapter 1 split into part 1 and 2
 * Current bugs: 1) rudimentary save system
 .               2) string input to integer option
 * (please refer to documentation log for further details)

**************************************************************************/

#pragma once
#include<iostream>
#include "Classes.cpp"
#include "Save_Load.cpp"
#include "Battle.cpp"
using namespace std;

//--

void Intro(), Entrance();
void openingMenu();
void about();

void Prologue_pt1(), Prologue_pt2(), Chapter1_pt1(), Chapter1_pt2(), Chapter1_pt2a(), Chapter1_pt2b();
void Tutorial1(), Tutorial2(), Tutorial3(); //1 explains exploration, 2 explains battle, 3 explains stats
void shipExplore(), captainConverse(), lanaConverse(), azikConverse();
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
    cout<<"You can no longer hold yourself upright."<<endl;
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
    else
        cout<<"Protip: Keep close track of your HP while fighting."<<endl;
    cout<<"1. Return to Menu\t\t 2. Quit"<<endl;
    int ch;
    cin>>ch;
    if(ch==1)
        openingMenu();
    else
        exit(0);
}


//--
//story part functions
//--
void Prologue_pt1() {
    string blankSpace;
    cout<<"Disclaimer: This story involves depictions of violence and aspects of eldritch horror."<<endl;
    cout<<"Due to the amount of text barrage, it is recommended to play on a full-screen."<<endl;
    cout<<"For the same reason - ie, to space out said barrage - you will sometimes be prompted to input text for no reason. The input in these cases do not matter."<<endl;
    cout<<"...\n"<<endl;
    cout<<"Backlund, Loen Kingdom"<<endl;
    cout<<"1358, Fifth Epoch\n"<<endl;
    cout<<"In a small living room, a group of six sit around a polished mahogany table with sheafs of paper spread on it."<<endl;
    cout<<"After a good amount of time examining them in silence, the first to speak is a stout blond man with dark-brown eyes.\n"<<endl;
    cout<<"DAMON: If you're right, this is the find of a lifetime."<<endl;
    cout<<"DAMON: Your name's going to be splashed over all those papers. 'The Incomparable, One and Only..."<<endl;
    cout<<"(please enter your first name)"<<endl;
    string mcname;
    cin>>mcname;
    cout<<mcname<<", is it?"<<endl;
    int ynreturns=yn();
    switch(ynreturns) {
        case 0:
        do {
            cout<<"What is it then?"<<endl;
            cin>>mcname;
            cout<<mcname<<"- is that so?"<<endl;
        } while(yn()==0);
        case 1:
        mainchar.Name=mcname;
        cout<<"DAMON: ..."<<mainchar.Name<<"'."<<endl;
        cout<<"YOU: There's really no need to mock me."<<endl;
        cout<<"Your tone makes it obvious you don't take any offense."<<endl;
        cout<<"Another man, slenderly-built with dark hair, speaks next."<<endl;
        cout<<"ERIC: I'm looking this over for what must be the tenth time and I still can't see anything off."<<endl;
        cout<<"RIA: Have you considered maybe there isn't?"<<endl;
        cout<<"Ria is a short brunette dressed in an off-white sweater, wearing earmuffs even inside the house. While initially shocked, her reaction wears off faster than the others."<<endl;
        cin>>blankSpace;
        cout<<"YOU: I expected all of you to call me crazy."<<endl;
        cout<<"The response to that comes from your childhood friend, Stephen."<<endl;
        cout<<"STEPHEN: You are crazy. Enough about Utopia that you'd never call us all here if you didn't believe you hit the mark."<<endl;
        cout<<"He isn't wrong. You were in your last year at Khoy University when Utopia became known, and the mystery has itched at you since then. You pondered over your own research for a good while, trying to catch every error, before you called together your friends."<<endl;
        cout<<"Anne sighs, taking into her hand the sheets containing one of the interviews you had done. She is the only senior here - she was in her final year when you joined as a student, and a chance meeting saw you two hit off well, continuing to keep in touch even after she had passed out."<<endl;
        cout<<"ANNE: I can't believe you pieced together the weather information for a place that hasn't been properly traversed in over a millenia. It's brilliant."<<endl;
        cout<<"ERIC: I personally enjoyed the insider tip from the MI9."<<endl;
        cout<<"ERIC: You really infiltrated the *MI9* for this.\n"<<endl;
        cout<<"The MI9 is Loen's special military department. You alone know the amount of networking it took to find that one of their officials had a run-in with Utopia, and to get the details of it."<<endl;
        cout<<"This current moment is the culmination of years of hardwork, and you're pleased to end up here.\n"<<endl;
        cin>>blankSpace;
        cout<<"DAMON: Lesson never to underestimate what a nerd can do."<<endl;
        cout<<"YOU: So to make sure... there's no disagreement with any of my speculations?"<<endl;
        cout<<"STEPHEN: None here."<<endl;
        cout<<"ANNE: Same."<<endl;
        cout<<"DAMON: I wish I had something, but nope."<<endl;
        cout<<"RIA: I believe you."<<endl;
        cout<<"ERIC: I've already said so."<<endl;
        cout<<"You can't surpress the sigh of relief that escapes you. One hurdle crossed, only a thousand more to go.\n"<<endl;
        cout<<"Your friends gathered here are all in the same or adjacent specialisation as you, but getting their approval isn't the same as convincing your field at large to take you seriously."<<endl;
        cout<<"But if this works out and you *do* find Utopia... that alone would speak for itself."<<endl;
        cout<<"And so you all fall into a new discussion - preparing an expedition team."<<endl;
        cout<<"..."<<endl;
        cin>>blankSpace;
        cout<<"It's been three days since then. With a flurry of activity, you're all getting different things done."<<endl;
        cout<<"Anne with her seniority is the one to put out the notices inviting applications for the team."<<endl;
        cout<<"Eric and Ria calculated the length of the trip, the path and the equipment the team would need."<<endl;
        cout<<"Stephen, being from a well-off family, was providing as much funding as he could and ordering items."<<endl;
        cout<<"Damon and you wrote up a proper paper explaining your research and its conclusions."<<endl;
        cout<<"Such a thing could only be published if Utopia was really found, but for now its purpose was to convince those who wanted to know what the expedition was about."<<endl;
        cout<<"You both are careful not to make it too revealing - Damon wasn't wrong that this discovery would be an incredibly popular one, and losing it to somebody else would be the worst."<<endl;
        cout<<"When you all meet up to discuss the progress, Anne is brimming with excitement."<<endl;
        cin>>blankSpace;
        cout<<"ANNE: A Society official applied!"<<endl;
        cout<<"ERIC: No way."<<endl;
        cout<<"RIA: By themself or...?"<<endl;
        cout<<"ANNE: She's a representative for the Society. They'd rather their own team accompany us--"<<endl;
        cout<<"DAMON: Of course they would."<<endl;
        cout<<"ANNE: --*but* they hope at least one of their own can be a part.\n"<<endl;
        cout<<"The Society refers to the Loen Relic Search and Preservation Society, one of the most well-known non-profit organisations in your field, and being supported by them is a dream come true."<<endl;
        cout<<"All the same, in this case, as independent archaelogists...\n"<<endl;
        cout<<"RIA: No outside team."<<endl;
        cout<<"STEPHEN: Agreed."<<endl;
        cout<<"YOU: Does the official have qualifications of their own?"<<endl;
        cout<<"ANNE: Excellent ones. She graduated from Backlund University a decade ago, and has published a fair few papers in peer-reviewed journals. The Fourth Epoch is her area of specialisation, but that's not a minus point in her case."<<endl;
        cout<<"The Fourth Epoch was more than a millenia ago, with very little of its history known to date. Utopia is a modern-day mystery, stemming from the past decade. But if Anne trusts in the person's qualifications, you have no reason to doubt."<<endl;
        cout<<"YOU: Well, I leave the vetting to you."<<endl;
        cout<<"..."<<endl;
        cin>>blankSpace;
        cout<<"In two days, the team is more or less settled as well as the logistics."<<endl;
        cout<<"You find yourself at the Society headquarters to speak with their official, Lana Wright. Waiting in the corridor outside her office, you're surprised to see a familiar figure appear from around the corner."<<endl;
        cout<<"He is a tall bronze-skinned man with dark hair tied at the nape of his neck, eyes filled with the vicissitudes of life.\n"<<endl;
        cout<<"Azik Eggers. He was one of your university's lecturers and taught you for your first two years, then he resigned for unknown reasons. It had fueled much rumour and speculation back then (not helped by the fact that he was relatively young and, according to some classmates, dreamy) but those had died away. Then resurrected with even more unbelievable rumours before dying again. You hadn't expected to see him ever, but all the same, you have fond memories of the man and his classes.\n"<<endl;
        cout<<"Do you greet him?"<<endl;
        int meetAzik=yn();
        if(meetAzik==0) {
            cout<<"You wait where you are, and he leaves without noticing you."<<endl;
            ending1();
        }
        if(meetAzik==1) {
            cout<<"YOU: Good evening, Mr. Azik."<<endl;
            cout<<"He turns to face you, clearly taken by surprise."<<endl;
            cout<<"MR. AZIK: Good evening..."<<endl;
            cout<<"After a second, he sighs, seeming exasperated with himself."<<endl;
            cout<<"MR. AZIK: You'll have to excuse me; my memory isn't quite up to the mark.\n"<<endl;
            cout<<"You don't take it personally. You didn't particularly stand out in his classes, and he did teach years and years of students.\n"<<endl;
            cout<<"YOU: I'm "<<mainchar.Name<<". From Khoy's history batch of '47."<<endl;
            cout<<"MR. AZIK: Oh yes, "<<mainchar.Name<<". Do forgive me, it's good to see you again."<<endl;
            cout<<"He frowns as something clicks."<<endl;
            cout<<"MR. AZIK: You're heading an expedition to Utopia, aren't you?"<<endl;
            cout<<"You nod."<<endl;
            cout<<"YOU: Utopia is a special interest of mine since university. I'm lucky to have this opportunity."<<endl;
            cout<<"Mr. Azik listens to you thoughtfully."<<endl;
            cout<<"MR. AZIK: Would there be any spots left to fill?"<<endl;
            cout<<"Are there...?"<<endl;
            int agreeAzik=yn();
            if(agreeAzik==0) {
                cout<<"You shake your head."<<endl;
                cout<<"YOU: I'm afraid not, sir. We're almost done setting up."<<endl;
                cout<<"He frowns almost ruefully, but doesn't press the matter. After some small talk, you two part ways."<<endl;
                ending1();
            }
            else {
                cout<<"YOU: You're in luck, sir. We should have a spot or two left."<<endl;
                cout<<"His lips quirk in a fleeting smile."<<endl;
                cout<<"MR. AZIK: I hadn't heard of Utopia until a few years after it vanished. I do regret never having gotten the chance to visit it."<<endl;
                cout<<"YOU: Don't we all. The tales of it always treaded the lines between normality and oddity."<<endl;
                cout<<"After some small talk, the two of you part ways."<<endl;
                cout<<"\n(savecode for this point is 7745)"<<endl;
                Prologue_pt2();
            }
        }
    }
};


//---


void Prologue_pt2() {
    cout<<"...\n"<<endl;
    cout<<"Sonia Sea"<<endl;
    cout<<"1358, Fifth Epoch\n"<<endl;
    cout<<"Your meticulous calculations triangulated Utopia in a region of islands to the south-west of Loen, following which your ship sets sail."<<endl;
    cout<<"Well, not precisely *your* ship, but as the leader of the expedition, it's rather heartening to think of it in that way."<<endl;
    cout<<"The total trip is estimated to take four weeks, which leaves a lot of time for you to walk around, familiarising yourself with the ship and your new companions.\n"<<endl;
    Tutorial1();
    shipExplore();
}


void shipExplore() {
    string blankSpace, savecode1;
    int shipchoice;
    do {
        cout<<"Do you--"<<endl;
        if(eventCounter[0]==0)
        cout<<"1) Explore the deck\n2) Speak to the captain\n3) Speak to Lana\n4) Speak to Mr. Azik\n5) Rest"<<endl;
        else if(eventCounter[0]>0)
        cout<<"1) Explore the deck\n2) Speak to the captain\n3) Speak to Lana\n4) Speak to Mr. Azik\n5) Speak to the second mate\n6) Rest"<<endl;
        cin>>shipchoice;
        switch(shipchoice) {
            case 1: cout<<"This is your first time on a ship, and while you've read about it in books, even seen some from afar, actually being on one is an odd experience. There's not a lot to look at on deck and you try to avoid getting in the way of the workers bustling around."<<endl;
            cin>>blankSpace;
            break;
            
            case 2:
            cout<<"The captain is a stocky man with weathered features, a grit to his face undoubtedly accummulated from long experience battling with the whims of the sea."<<endl;
            captainConverse();
            break;
            
            case 3:
            cout<<"Lana Wright is a woman in her thirties, formally dressed with her dark hair in a ponytail. ";
            if(eventCounter[0]<3)
                cout<<"She currently has an unnatural pallour to her thin face hinting at nausea. Seeing you, she attempts a wan smile."<<endl;
            else
                cout<<"She still seems unsettled, but looks markedly better now."<<endl;
            lanaConverse();
            break;
            
            case 4:
            cout<<"Mr. Azik is at the bow of the ship, watching the sea. Hearing you approach, he turns to look at you."<<endl;
            azikConverse();
            break;
            
            case 5:
            if(eventCounter[0]==0) {
                cout<<"Are you sure you want to rest? This will end the ship exploration period."<<endl;
                if(yn()==1)
                    shipchoice=0;
            }
            else {
                cout<<"The second mate is a young man with tanned features."<<endl;
                if(inventory[0].itemName=="bottle of essential scent" || inventory[0].itemName==" ")
                    cout<<"SECOND MATE: How's the stuf? It's my own creation."<<endl;
                else {
                    cout<<"You tell him what the captain said, and he nods."<<endl;
                    cout<<"SECOND MATE: Give me a second, I'll go get a bottle for you."<<endl;
                    cout<<"He returns soon enough with a small glass bottle containing a pale liquid."<<endl;
                    bottle.obtain();
                    cout<<"SECOND MATE: Remember, just inhale from the rim, don't drink it. That'll be a worse experience than any seasickness."<<endl;
                    inventory[0]=bottle;
                    inventoryCount++;
                    eventCounter[0]=2;
                    cin>>blankSpace;
                }
            }
            break;
            
            case 6:
            if(eventCounter[0]>0) {
                cout<<"Are you sure you want to rest? This will end the ship exploration period."<<endl;
                if(yn()==1)
                    shipchoice=0;
            }
            else
                cout<<"Invalid choice."<<endl;
            break;
            
            default: cout<<"Invalid choice."<<endl;
        }
    } while(shipchoice!=0);
    //the first place savecode is generated hence pos=1;
    savecode1=generateSave(1);
    cout<<"\n(savecode for this point is "<<savecode1<<")"<<endl;
    Chapter1_pt1();
}

void captainConverse() {
    string blankSpace;
    int captainchoice, gehrman, sickness;
    do {
        cout<<"CAPTAIN: And what would you be wanting?"<<endl;
        cout<<"1) about the trip\n2) about seasickness\n3) about the captain\n4) end"<<endl;
        cin>>captainchoice;
        switch(captainchoice) {
            case 1:
            cout<<"CAPTAIN: Until recently, we'd have been fools to take this path all the way to your little island."<<endl;
            cout<<"CAPTAIN: After all, it leads straight into the Berserk Sea. Not much berserk nowadays, praise the Storm."<<endl;
            cout<<"Loen's shores are lapped up by the waters of the Sonia Sea, south of which lies the Berserk Sea. For thousands of years, since the end of the previous Epoch, that sea was a death wish to traverse. Tales say that the God of Death was killed by the other gods there, and his rage was forever etched into the ocean."<<endl;
            cout<<"If it wasn't for the recent inexplicable calming of the Berserk Sea, there was no way you could have found Utopia."<<endl;
            cin>>blankSpace;
            break;
            
            case 2:
            cout<<"CAPTAIN: You holdin' out well?"<<endl;
            sickness=yn();
            if(sickness==1) {
                cout<<"CAPTAIN: Good to hear. Some people ain't made for the sea, but you look tip-top."<<endl;
                cout<<"CAPTAIN: If you need it though, my second mate's got some essential scents to settle your guts."<<endl;
                eventCounter[0]=1;
                cin>>blankSpace;
            }
            else {
                cout<<"CAPTAIN: That's a shame. Some people ain't made for the sea."<<endl;
                cout<<"CAPTAIN: You should find my second mate. He's got some essential scents that'll settle your guts."<<endl;
                eventCounter[0]=1;
                cin>>blankSpace;
            }
            break;
            case 3:
            cout<<"CAPTAIN: 'bout me?"<<endl;
            cout<<"He chuckles."<<endl;
            cout<<"CAPTAIN: Ain't much to say. Grew up 'round Desi Bay, and decided I'd be a great adventurer. Never got the chance, not when the waters are as dangerous they are. Though it's gotten better... you've heard of Gehrman Sparrow, haven't you?"<<endl;
            gehrman=yn();
            if(gehrman==0) {
                cout<<"The captain lets out a startled guffaw."<<endl;
                cout<<"CAPTAIN: You livin' under a rock? Sparrow's only the most feared adventurer to touch the seas. Man went around huntin' pirates as he pleased. Just a year or two, and he became the star monster in those night-time scary tales. He's half the reason pirate attacks have gone down."<<endl;
                cout<<"CAPTAIN: It ain't surprisin' he ended up the \"Angel of Retribution\" of that Fool Church."<<endl;
                cout<<"That description does strike some familiarity for you. The Church of the Fool is a religious institution started in the past decade, dedicated to an apparently ancient god known as the Fool, and Gehrman Sparrow was indeed canonised as an angel of The Fool."<<endl;
                cout<<"In fact... if you remember right, one of the rumours in your university about Mr. Azik was that he had worked with Sparrow to take down a notorious pirate."<<endl;
                cin>>blankSpace;
            }
            else {
                cout<<"You nod."<<endl;
                cout<<"Gehrman Sparrow was a mysterious man who made large waves when he appeared on the seas and started taking down pirates whenever he encountered them. Soon enough he became wanted by the authorities, with a frighteningly large bounty. However, a year or two after that, the Church of the Fool had been started in the Rorsted Archipelago, dedicated to an apparently ancient god known as the Fool and acknowledged as legitimate by the other Churches. And that church had canonised Sparrow as an angel of the Fool. So, his warrant was removed."<<endl;
                cout<<"Sparrow hasn't been seen in a decade, as far as you know, but he's still popular in the social consciousness. Just recently, an acclaimed author had released a book that she called Sparrow's authentic biography and it quickly became a bestseller."<<endl;
                cout<<"Speaking of which, there was a rumour in university that Sparrow and Mr. Azik (or someone matching his description, at the least) had taken down a notorious pirate together."<<endl;
                cin>>blankSpace;
            }
            eventCounter[1]=1;
            break;
            case 4:
            cout<<mainchar.Name<<": Nothing, sorry to disturb you."<<endl;
            break;
            default: cout<<"Invalid choice."<<endl;
        }
    } while(captainchoice!=4);
}

void lanaConverse() {
    string blankSpace;
    int lanachoice;
    cout<<"LANA: Hello, "<<mainchar.Name<<"."<<endl;
    if(eventCounter[0]<3) {
        cout<<"LANA: Do excuse me, I'm in no state to converse. I'm afraid this trip isn't agreeing with me."<<endl;
        if(inventory[0].itemName=="bottle of essential scent") {
            cout<<"Do you give the bottle of essential scent to her?"<<endl;
            int give=yn();
            if(give==1) {
                inventory[0].clear();
                inventoryCount--;
                cout<<mainchar.Name<<": Maybe this might help?"<<endl;
                cout<<"Lana takes the bottle from you, uncapping it and inhaling deeply as the second mate had advised. After a minute, she sighs in relief."<<endl;
                cout<<"LANA: I feel a great deal better now. Thank you so much."<<endl;
                eventCounter[0]=3;
                cin>>blankSpace;
            }
            else {
                cout<<"You choose not to."<<endl;
                cin>>blankSpace;
            }
        }
    }
    if(eventCounter[0]==3) {
        do {
            cout<<"What do you talk about?"<<endl;
            cout<<"1) about the trip\n2) about Utopia\n3) about the Society\n4) end"<<endl;
            cin>>lanachoice;
            switch(lanachoice) {
                case 1:
                cout<<"LANA: I don't think I care to travel by ship again..."<<endl;
                cout<<"LANA: The sea is beautiful but not easy to appreciate when you're trying not to throw up."<<endl;
                cout<<"LANA: I must thank you again for that bottle."<<endl;
                cin>>blankSpace;
                break;
                
                case 2:
                cout<<"LANA: Utopia is an interesting thing."<<endl;
                cout<<"LANA: I can't think of much in history that matches this situation."<<endl;
                cout<<"LANA: There's the City of Silver, which was recently discovered and brought to the outside world."<<endl;
                cout<<"LANA: But even then, that was a city from ancient history that was hidden away. Utopia on the other hand had interactions with outsiders - it was just impossible to find."<<endl;
                cout<<"LANA: Then it vanished completely, just as suddenly as it had appeared."<<endl;
                cin>>blankSpace;
                break;
                
                case 3:
                cout<<"LANA: The Society has only existed for a decade, but we're devoted to preserving history."<<endl;
                cout<<"LANA: Human memory spans so little, in comparison to the epochs that the world has witnessed."<<endl;
                cout<<"LANA: Only by written and marked preservation can we ensure that the future generations know of their past."<<endl;
                cout<<"LANA: I studied in Backlund University, and interned at the Society in my third year."<<endl;
                cout<<"LANA: That experience was enough for me to know where I wanted to work once I graduated."<<endl;
                cout<<"You can't help but feel a bit envious. Backlund University is of a much higher standard than Khoy and situated in the capital of Loen to boot. As a student of Khoy, your opportunities were comparitively limited, though you're still grateful for everything your professors did for your batch."<<endl;
                cin>>blankSpace;
                break;
                
                case 4:
                break;
                
                default:
                cout<<"Invalid choice."<<endl;
            }
        } while(lanachoice!=4);
    }
}

void azikConverse() {
    string blankSpace;
    int azikchoice, end=0;
    do {
        cout<<"What do you talk about?"<<endl;
        if(eventCounter[1]==0)
            cout<<"1) about the trip\n2) about Utopia\n3) about his resignation\n4) end"<<endl;
        else
            cout<<"1) about the trip\n2) about Utopia\n3) about his resignation\n4) about Sparrow\n5) end"<<endl;
        cin>>azikchoice;
        switch(azikchoice) {
            case 1:
            cout<<"MR. AZIK: This isn't my first time out on the sea, although I've never really travelled by ship."<<endl;
            cout<<"You're not sure how else he must have travelled, but you don't ask. He has the faraway look of someone remembering the past."<<endl;
            cin>>blankSpace;
            break;
        
            case 2:
            cout<<"MR. AZIK: I wonder how it must be now. From what I've heard, it was a rather nice town before it vanished entirely."<<endl;
            cout<<"YOU: Do you have any thoughts on the mystery of its appearance and disappearance?\n"<<endl;
            cout<<"General opinion, as far as you know, is split between Utopia being a hitherto unknown town like the City of Silver or a dark illusion of sorts. Only a fraction of people had ever visited it, and while their testimonials about it were ordinary, it could be that they had been affected by it in some way."<<endl;
            cout<<"Even for you who focused your research on this one place, you aren't sure what to believe. In a world with good and evil gods, it was entirely possible that some inhuman magic had been worked, but then it seemed not to have any purpose in the end.\n"<<endl;
            cout<<"Mr. Azik takes a few seconds before answering.\n"<<endl;
            cout<<"MR. AZIK: There's no doubt something strange happened. It wouldn't be the first time that such a phenomena occured."<<endl;
            cout<<"MR. AZIK: But I don't think Utopia by itself was anything insidious. Though currently..."<<endl;
            cout<<"He doesn't finish the sentence. You don't ask him to; there's no need to jinx this exploration."<<endl;
            cin>>blankSpace;
            break;
        
            case 3:
            cout<<"MR. AZIK: It was a bit sudden, but I had personal matters to attend to."<<endl;
            cout<<"YOU: Do you plan to return any time, sir? Everyone was rather sorry to see you go."<<endl;
            cout<<"Mr. Azik smiles."<<endl;
            cout<<"MR. AZIK: That's kind of you to say. I'm not sure yet. For now, I plan to travel."<<endl;
            cout<<"There's a touch of fondness in his voice as he adds-"<<endl;
            cout<<"MR. AZIK: A dear friend wrote to me often of the places he visited, and with how elaborate his descriptions were, I want to see them for my own."<<endl;
            cout<<"You suddenly remember how he volunteered himself on this trip."<<endl;
            cout<<"YOU: Did that friend ever visit Utopia?"<<endl;
            cout<<"MR. AZIK: He did. He had wonderful things to say of it."<<endl;
            cin>>blankSpace;
            break;
        
            case 4:
            if(eventCounter[1]>0) {
                cout<<"YOU: If you've been at sea before, sir, have you ever brushed with Gehrman Sparrow?"<<endl;
                cout<<"It's a bit roundabout, but you don't think you're close enough to your former lecturer to ask outright about the rumours."<<endl;
                cout<<"He gives you a searching look. You have a feeling he knows of the rumours too."<<endl;
                cout<<"MR. AZIK: Gehrman is a former student of mine."<<endl;
                cout<<"You nearly bite off your tongue trying not to gape like an idiot. A student? ...from Khoy? There's a possibility the feared hunter-criminal is your senior?"<<endl;
                cout<<"No way. Mr. Azik might have taught elsewhere. You don't know anything about his past, after all. He was one of the most friendly lecturers, but incredibly private about his own matters."<<endl;
                eventCounter[1]=2;
                cin>>blankSpace;
            }
            else {
                cout<<"You excuse yourself."<<endl;
                end=1;
            }
            break;
            
            case 5:
            if(eventCounter[1]>0) {
                cout<<"You excuse yourself."<<endl;
                end=1;
            }
            else
                cout<<"Invalid choice."<<endl;
            break;
            
            default:
                cout<<"Invalid choice."<<endl;
            break;
        }
    } while(end!=1);
}

//--

void Chapter1_pt1() {
    string blankSpace, savecode2;
    int belief;
    cout<<"..."<<endl;
    cout<<"\nIt is one early dawn when you and the team catch sight of an island at the horizon.\nUtopia."<<endl;
    cout<<"As you approach however, a feeling of disquietude fills the air. You all exchange glances, but there's nothing that can be said."<<endl;
    cout<<"Utopia was known to have a port, and moving along the shores of the island, you find it, unmanned and somewhat dilapidated with time."<<endl;
    cout<<"All the same, it is serviceable, and the captain anchors the ship there."<<endl;
    cout<<"You and the team - a total of eleven people - assemble at the exit point, after Lana radio-communicates to the Society of your arrival. ";
    if(eventCounter[0]<3)
        cout<<"She, looking quite miserable from her sea experience, musters a quiet prayer to the Evernight Goddess."<<endl;
    else
        cout<<"She says a quiet prayer to the Evernight Goddess."<<endl;
    cin>>blankSpace;
    cout<<"Do you pray to any gods?\n"<<endl;
    cout<<"There are six main gods in the world, seven with the new addition of \"The Fool\"."<<endl;
    cout<<"In Loen, only the first three have their churches, but five of them have followers."<<endl;
    cout<<"1) The Evernight Goddess- goddess of the night, empress of disaster and misfortune, lady of tranquility."<<endl;
    cout<<"2) The Lord of Storms- ruler of the sea and the sky, god of calamities."<<endl;
    cout<<"3) The Earth Mother- goddess of life and nature, lady of the moon."<<endl;
    cout<<"4) The God of Steam and Machinery- guardian of craftsmen, god of progress and technology."<<endl;
    cout<<"5) The Fool- ruler of the Spirit World, god of secrecy and change"<<endl;
    cout<<"6) Atheism- in a world where the miracles of gods are aplenty, you can't deny Their existence, but with the grief that abounds, you can believe that They care little for the matters of humans."<<endl;
    do {
        cin>>belief;
        if(belief>0 && belief<7)
            eventCounter[2]=belief;
        else
            cout<<"Invalid choice."<<endl;
    } while(eventCounter[2]==0);
    beliefBenefits(belief);
    if(belief==6)
        cout<<"You have no prayers to say, only the steely hope that the team can handle whatever is out there."<<endl;
    else
        cout<<"You make a small prayer as well. It can't hurt if divine grace happens to glance your way."<<endl;
    cout<<"All of you step out, sticking together as you look around the port."<<endl;
    cout<<"It's not a large place, understandable for the size of the town. A lighthouse towers above, but no one seems to be working it."<<endl;
    cout<<"There are a few warehouses around for what you presume must be ship cargo."<<endl;
    cout<<"A hotel and a restaurant can be seen close in the distance, to take advantage of tired visitors stepping out onto the port."<<endl;
    cout<<"The entire area matches the descriptions you've heard from visitors, and you can easily imagine the better times it must have had."<<endl;
    cout<<"But... what had happened to the people of Utopia?"<<endl;
    cout<<"Mr. Azik seems the only one more curious than tense as you advance.\n"<<endl;
    cout<<"ERIC: Should we check out each of the buildings here?"<<endl;
    cout<<"Ms. Lana shakes her head."<<endl;
    cout<<"LANA: I'd suggest against it."<<endl;
    cout<<"She turns to you, and you remember that as the leader you *are* supposed to head everyone.\n"<<endl;
    cout<<"Do you want to explore the buildings?"<<endl;
    int buildings=yn();
    eventCounter[3]=buildings;
    if(buildings==1) {
        cout<<"\nYOU: We should check at least one or two of them. They might have some clues about what happened."<<endl;
        cout<<"Ms. Lana frowns, but doesn't speak up."<<endl;
        cout<<"You all head to the nearest warehouse, Ria pulling open the rusty metal door."<<endl;
        cout<<"Within is a mess of wooden crates, possibly once stacked neatly but now tossed all around the place."<<endl;
        cout<<"Most of the crates have started to rot, leaving a strong odour in the air."<<endl;
        cout<<"You pinch your nose close with one hand and look around."<<endl;
        cout<<"There is unsurprisingly no signs of any people."<<endl;
        cin>>blankSpace;
        cout<<endl;
        cout<<"ANNE: What could have happened here?"<<endl;
        cout<<"YOU: Utopia was known to have terrible weather. If that shook up the warehouse..."<<endl;
        cout<<"You don't quite believe that yourself, but you can't think of a better explanation."<<endl;
        cout<<"ERIC: The people clearly left this place, or were forced to leave, a good while ago."<<endl;
        cout<<"DAMON: Maybe the same time the visitors were?"<<endl;
        cout<<"Ms. Lana seems to be on the watch for something to come bursting from the shadows."<<endl;
        cout<<"You understand her caution - the disarray leaves more than enough places for anyone or anything to be hiding."<<endl;
        cout<<"Thankfully, you all leave the warehouse with nothing happening."<<endl;
        cout<<"The other two warehouses you peep into are much the same, holding no more answers than the first."<<endl;
        cout<<endl;
        cout<<"Which leaves the lighthouse to be looked into."<<endl;
        cout<<"The lighthouse being the narrow structure it is, half the team wait outside while the other half enter. You, of course, are among the latter."<<endl;
        cout<<"Along with you are Mr. Azik, Damon, Ria and two others."<<endl;
        cout<<"The staircase spirals from the base to the top, and you all climb in single file."<<endl;
        cout<<"The rooms on the way aren't disordered like the warehouse, but also contain no sign of life."<<endl;
        cin>>blankSpace;
        cout<<"\nUntil the room at the top is reached. From there is a clear view of the sea, for miles and miles, but what catches your attention is the lantern rolling on the floor."<<endl;
        cout<<"You kneel down and take it into your hand, checking its state. The wick has burnt itself out and there's little oil left."<<endl;
        cout<<"Clearly someone had abandoned the lantern here before leaving, and in a hurry.\n"<<endl;
        cout<<"RIA: Hey, "<<mainchar.Name<<"."<<endl;
        cout<<"You turn to find her and Mr. Azik standing near a wall, where on an afixed hook lies a thick raincoat."<<endl;
        cout<<"Leaving the lantern where it was, you go over to them."<<endl;
        cout<<"YOU: The material of the raincoat..."<<endl;
        cout<<"RIA: It's coated in that sap of Utopia.\n"<<endl;
        cout<<"Utopia was a place with ferocious weather conditions and quite constant rain. To withstand it, its citizens made their clothes of sturdy material and coated them in a special sap that had waterproofing qualities."<<endl;
        cout<<"Such clothing was found nowhere else. It was solely Utopian.\n"<<endl;
        cout<<"As Damon comes over, Mr. Azik walks away, kneeling down and running a finger against the ground."<<endl;
        cout<<"You don't think you've heard him say a word since he arrived, although possibly Utopia is outside his area of study."<<endl;
        cout<<"While there's still that student feeling of wanting to hear your lecturer's thoughts, you're aware - and you suppose Mr. Azik is too - that you're more knowledgeable on Utopia than anyone else here.\n"<<endl;
        cout<<"DAMON: We're keeping that with us, right?"<<endl;
        cout<<"RIA: What, you want to wear it if it rains?"<<endl;
        cout<<"DAMON: A coat that hasn't been cleaned in god knows how long? Please, I have more dignity than that."<<endl;
        cout<<"YOU: I agree with Damon--not about his dignity."<<endl;
        cout<<"He rolls his eyes at you as you grin and continue-"<<endl;
        cout<<"YOU: But the coat. It's a clear proof to take back to Backlund."<<endl;
        cout<<"RIA: When you put it like that..."<<endl;
        cout<<"She hands the raincoat to you."<<endl;
        cout<<"RIA: I'm not lugging that weight around."<<endl;
        cout<<"YOU: Yeah, yeah, give me all the work."<<endl;
        cout<<"You fold it and put it into an empty compartment of your shoulder bag."<<endl;
        cout<<"You all search around the room and find nothing else."<<endl;
        cout<<"Returning back to the entrance, you describe what was there to the other half of the team."<<endl;
        cout<<"You notice from the corner of your eye that Mr. Azik and Ms. Lana are speaking to each other privately."<<endl;
        cout<<"You're curious, but their conversation barely lasts a minute and you're not nosy enough to ask."<<endl;
        cout<<"With the buildings checked, your team moves forward and out of the port, coming close to the restaurant you saw earlier."<<endl;
    }
    else {
        cout<<"\nYOU: I agree with Ms. Lana. We should do a cursory look into Utopia as a whole before we go through everything finely."<<endl;
        cout<<"With that decided, you all continue onwards, slowing down as you pass the restaurant.\n"<<endl;
    }
    cout<<"Through the glass windows, you can see into the place."<<endl;
    cout<<"It looks in slight disarray, with some tables knocked down and fragments of glass on the floor."<<endl;
    cout<<"The tables still standing are laid out neatly with cloth and flowers... and also with plates of what is now black and moldy, but was once clearly food."<<endl;
    cout<<"The silence in which your team was moving all of a sudden grows heavy and suffocating."<<endl;
    cin>>blankSpace;
    cout<<"\nYOU: Were they attacked?"<<endl;
    cout<<"You start the discussion, wanting to ease the atmosphere."<<endl;
    cout<<"LANA: There aren't bodies nor blood."<<endl;
    cout<<"YOU: ...a bloodless scuffle?"<<endl;
    cout<<"You already know you're wrong before Damon cuts in-"<<endl;
    cout<<"DAMON: A bloodless scuffle with no casualties, but which left the restaurant staff unable to clean up?"<<endl;
    cout<<"STEPHEN: It's like a moment's scene was frozen in time.\n"<<endl;
    if(buildings==1)
        cout<<"His words remind you awfully of the warehouses and the lighthouse. Moments frozen in time indeed...\n"<<endl;
    cout<<"Those of the team willing to speak up come to no conclusions, but the increasing feeling that something not quite ordinary happened in Utopia all at once."<<endl;
    cout<<"While that was the most likely thing from the start, being at the heart of that disaster brings a whole different significance to that knowledge."<<endl;
    cout<<"You hope that if anything is out there, it can be kept at bay by your group and the light weaponry you all carry.\n"<<endl;
    cout<<"It's still morning, but above, the sky darkens bit by bit."<<endl;
    cout<<"..."<<endl;
    cin>>blankSpace;
    cout<<"Entering the city proper, the first thing noticed is the extreme floral growth."<<endl;
    cout<<"Moss spans the walls of many a building, but the more concerning part is the outgrowth of mushrooms everywhere."<<endl;
    cout<<"As far as you're aware, mushrooms have never been a common thing in Utopia."<<endl;
    cout<<"You're not the only person to know that. After all, one more person worked on your paper with you."<<endl;
    cout<<"And now Damon stands beside you with a drawn face. You both exchange unsure glances."<<endl;
    cout<<"MR. AZIK: Take utmost care not to get separated."<<endl;
    cout<<"It is the first thing he has said all this while, and it's as solemn as can be expected."<<endl;
    cout<<"You make your way to the town square before all the growing dread takes form."<<endl;
    cin>>blankSpace;
    cout<<"The mushrooms on the buildings puff up, and there's not a moment of warning before they come off all together, landing upright on the ground."<<endl;
    cout<<"ANNE: What the...?"<<endl;
    cin>>blankSpace;
    cout<<"Shrill screams sound. You don't know if you're one of them or not."<<endl;
    cout<<"LANA: Everyone, stay still-"<<endl;
    cout<<"A mushroom bounces from the top of a building and lands on the shoulder of one of the team, swaying back and forth."<<endl;
    cin>>blankSpace;
    cout<<"You all scramble away from each other in instinctual fear. Any sense of cohesion is broken."<<endl;
    cout<<"In the rush, you find yourself next to Ms. Lana, with nobody else in sight."<<endl;
    cout<<"LANA: "<<mainchar.Name<<"."<<endl;
    if(eventCounter[0]<3)
        cout<<"Her exhaustion is clear now than ever before, but her expression has a reassuring calm. It's an anchor in the midst of this madness."<<endl;
    else
        cout<<"Her expression holds a reassuring calm. It's an anchor in the midst of this madness."<<endl;
    cin>>blankSpace;
    cout<<"Mushrooms half your size bounce forward which would be amusing in any context other than if they weren't doing so while radiating a menacing aura."<<endl;
    cout<<"Ms. Lana hands you her radio communicator."<<endl;
    cout<<"LANA: Run. Let the Society know. I'll hold them off."<<endl;
    cout<<"You're not in any state of mind to ask how. Accepting the communicator, realising it's currently out of signal, you try to remember the way you entered the town and dash off."<<endl;
    cout<<"Except your path is almost immediately blocked by two mushrooms. You draw out the dagger in your belt sheathe, wishing this wasn't how your first use of it went."<<endl;
    if(eventCounter[0]<3) {
        cout<<"From behind you are terrifying sounds, starting with blasts that are overtaken by squishing, sliding noises. Followed by a human gasp. You try to ignore them, afraid to turn your back to these... creatures.\n"<<endl;
    }
    else {
        cout<<"From behind you are the sounds of blast after blast. You don't dare look and turn your back, but then a shout catches your attention-"<<endl;
        cin>>blankSpace;
        cout<<"LANA: "<<mainchar.Name<<"! Catch!"<<endl;
        cout<<"You spin around, fumbling, but get it into your hands all the same, faintly surprised she could throw it as far as she did."<<endl;
        emblem.obtain();
        inventory[inventoryCount]=emblem;
        inventoryCount++;
        cout<<"It's a golden-brown metal object, shaped like a sunflower with the ancient symbol for the Sun inscribed at the centre. You feel something warm and soothing just on holding it."<<endl;
        cout<<"LANA: Squeeze it and call out \"Light\" to use it!"<<endl;
        cout<<"She explains nothing more, not that either of you have the time to sit around and chat."<<endl;
        cout<<"Wishing for her safety, ready to ensure yours, you quickly turn back to the two mushrooms in front of you.\n"<<endl;
    }
    Tutorial2();
    cout<<"You face two Bounceshrooms."<<endl;
    int opponents[3]={2,1,1};
    battleMechanic(opponents);
    if(hp>=10)
        eventCounter[4]=1;
    else
        eventCounter[4]=0;
        
    savecode2=generateSave(2);
    cout<<"\n(Savecode for this point is "<<savecode2<<")"<<endl;
    
    Chapter1_pt2();
}


void Chapter1_pt2() {
    string blankSpace;
    string savecode3;

    if(eventCounter[4]==1)
        cout<<"Breathing heavily, injured, but not too badly, you stand over the corpses of your fungal enemies."<<endl;
    else
        cout<<"Breathing heavily, seriously weakened by the battle, you try to keep yourself upright over the corpses of your fungal enemies."<<endl;
    cout<<"As you watch, their bodies disintegrate, turning into pale dust and leaving a dark-brown core in its midst."<<endl;
    cout<<"From behind, there are no sounds of battle any longer. Either Ms. Lana won or..."<<endl;
    cout<<"You could turn to check on her, but you're also aware of the need to leave this place as quickly as you can and contact either the ship or the Society."<<endl;
    if(eventCounter[4]==0)
        cout<<"Especially in your injured state, every second matters."<<endl;
    cout<<"\nDo you look back at Ms. Lana?"<<endl;
    eventCounter[5]=yn();
    
    if(eventCounter[5]==1) {

        if(eventCounter[0]<3) {
            cout<<"You turn. There is no sign of Ms. Lana..."<<endl;
            cout<<"...or to be more precise, her body. Her clothes, you see, are spread on the ground, amidst a mass of bouncing mushrooms creating puffs of spore in the air."<<endl;
            cout<<"You feel sick to your stomach, and only feel worse as the mushrooms stop bouncing and face you as one."<<endl;
            if(eventCounter[4]==0)
                ending2();
            else
                cout<<"Paying no mind to anything else, you run. Adrenaline fuels you and you feel the rush in your veins more than you have at any other point of your life."<<endl;
        }
        
        else {
            cout<<"You turn, and are relieved to find her alive and surrounded by even more corpses than you are."<<endl;
            cout<<"YOU: Ms. Lana...?"<<endl;
            cout<<"She startles and faces you. She doesn't bother to hide that she seems on the verge of collapsing, and you wonder if that emblem she gave you might have been better off with her after all."<<endl;
            cout<<"LANA: "<<mainchar.Name<<"... you're still here...?"<<endl;
            cout<<"YOU: Can you walk? We can go together."<<endl;
            cout<<"LANA: I'll only slow you down. With what I gave you, as long as you avoid running into a large crowd of monsters, you should be fine."<<endl;
            cin>>blankSpace;
            
            if(eventCounter[4]==0) {
                cout<<"YOU: I'm not really better off. Considering what you did right now, whatever it was, I'd be safer by your side."<<endl;
                cout<<"YOU: And whatever is going on, you're clearly more knowledgeable and experienced here than I am."<<endl;
                cout<<"Your voice trembles a bit, suppressing the fear that's been rising at you at the hellish nightmare you've witnessed, and Ms. Lana's eyes take a sudden shade of guilt."<<endl;
                cout<<"YOU: I think it's best we go together; it doesn't matter how slow."<<endl;
                cout<<"\nShe watches you with surprise, and then a growing... you're not sure how to put it? Pleasant resignation?"<<endl;
                cout<<"Despite her firm words, there could be no way she faced the situation with that much inner calm. She must have feared dying at some point, just like you did."<<endl;
                cout<<"There are answers you desperately want to seek from her, but travelling together, you can leave it for when both of you are safe."<<endl;
                savecode3=generateSave(3);
                cout<<"\n(Savecode for this point is "<<savecode3<<")"<<endl;
                Chapter1_pt2b();
            }
            
            else {
                cout<<"You consider her argument. You are in better shape than her, and alone you probably have a better chance of leaving Utopia and contacting the Society."<<endl;
                cout<<"Do you leave Ms. Lana and go?"<<endl;
                int going=yn();
                if(going==1) {
                    cout<<"She seems to see the decision you've made before you even say aloud.\n"<<endl;
                    cout<<"LANA: I'm sorry that you came here with such hopes only to leave like this..."<<endl;
                    cout<<"There's an undercurrent of guilt in her voice that runs deeper than those words."<<endl;
                    cout<<"LANA: I'll rest a while and try to find the others."<<endl;
                    cout<<"LANA: Whether we arrive or not, when you reach the ship, you should leave immediately."<<endl;
                    cout<<"\nYou nod."<<endl;
                    cout<<"YOU: Stay alive."<<endl;
                    cout<<"Ms. Lana smiles fleetingly."<<endl;
                    cout<<"LANA: You too."<<endl;
                    cout<<"\nThere's no better parting words to be said in such a situation."<<endl;
                    cout<<"Turning back to the path you had been heading to, you continue running, ";
                    if(eventCounter[2]<6)
                        cout<<"making a small prayer for her and your friends."<<endl;
                    else
                        cout<<"hoping the best for her and your friends."<<endl;
                    savecode3=generateSave(3);
                    cout<<"\n(Savecode for this point is "<<savecode3<<")"<<endl;
                    Chapter1_pt2a();
                }
                else {
                    eventCounter[0]=4;
                    cout<<"You shake your head."<<endl;
                    cout<<"YOU: I don't know what's going on, but you're clearly more knowledgeable and experienced here than I am."<<endl;
                    cout<<"Your voice trembles a bit, suppressing the fear that's been rising at you at the hellish nightmare you've witnessed, and Ms. Lana's eyes take a sudden shade of guilt."<<endl;
                    cout<<"YOU: I'm not leaving you. We'll go together; it doesn't matter how slow."<<endl;
                    cout<<"\nShe watches you with surprise, and then a growing... you're not sure how to put it? Pleasant resignation?"<<endl;
                    cout<<"Despite her firm words, there could be no way she faced the situation with that much inner calm. She must have feared dying at some point, just like you did."<<endl;
                    cout<<"There are answers you desperately want to seek from her, but travelling together, you can leave it for when both of you are safe."<<endl;
                    savecode3=generateSave(3);
                    cout<<"\n(Savecode for this point is "<<savecode3<<")"<<endl;
                    Chapter1_pt2b();
                }
            }
        }
    }

    else {
        cout<<"Ms. Lana was clear about getting help as soon as possible. You can't waste a second."<<endl;
        cout<<"With that thought, you continue running, hoping desparately that you're faster than anything behind you."<<endl;
        cout<<"Almost childishly, you can't help but think that if you don't see them, they might just not exist."<<endl;
        cout<<"How could such an expedition have turned into a nightmare so quickly?"<<endl;
        cout<<"Your team who followed you... Damon, Ria, Stephen, Anne, Eric... are they still alive?"<<endl;
        cout<<"The thought that your friends who supported you might be cornered by these same monsters makes your throat clog, and you push away that thought before it can affect you too much."<<endl;
        cout<<"You should leave that for when you're safe. Right now, every drop of energy you have can be dedicated only to escaping alive."<<endl;
    }
    savecode3=generateSave(3);
    cout<<"\n(Savecode for this point is "<<savecode3<<")"<<endl;
    Chapter1_pt2a();
}

void Chapter1_pt2a() {
    //the part where Lana does not join you, ie, eventCounter[0]<4
    cout<<"\nFor now, the demo ends here."<<endl;
    cout<<"Thank you for playing."<<endl;
    exit(0);
}

void Chapter1_pt2b() {
    //the part where Lana joins you, ie, eventCounter[0]==4
    cout<<"\nFor now, the demo ends here."<<endl;
    cout<<"Thank you for playing."<<endl;
    exit(0);
}
#include<iostream>
#include "ADayinUtopia.cpp"

//--

int yn(), chartoint();

void Chapter1_pt1(), Chapter1_pt2();
void Chapter1_pt2a(), Chapter1_pt2b();

void ending2();

//--

void Chapter1_pt1() {
    string blankSpace;
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
        belief=chartoint();
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
        
    generateSave(2);
    cout<<"\n(The game has been saved.)"<<endl;
    
    Chapter1_pt2();
}


void Chapter1_pt2() {
    string blankSpace;

    if(eventCounter[4]==1)
        cout<<"Breathing heavily, injured, but not too badly, you stand over the corpses of your fungal enemies."<<endl;
    else
        cout<<"Breathing heavily, seriously weakened by the battle, you try to keep yourself upright over the corpses of your fungal enemies."<<endl;
    cout<<"As you watch, their bodies disintegrate, turning into pale dust and leaving soft-looking brown sticks in their midst."<<endl;
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
                cout<<"YOU: And whatever is going on, you're clearly more knowledgeable and experienced here than I am.\n"<<endl;
                cout<<"Your voice trembles a bit, suppressing the fear that's been rising at you at the hellish nightmare you've witnessed, and Ms. Lana's eyes take a sudden shade of guilt.\n"<<endl;
                cout<<"YOU: I think it's best we go together; it doesn't matter how slow."<<endl;
                cout<<"\nShe watches you with surprise, and then a growing... you're not sure how to put it? Pleasant resignation?"<<endl;
                cout<<"Despite her firm words, there could be no way she faced the situation with that much inner calm. She must have feared dying at some point, just like you did."<<endl;
                cout<<"There are answers you desperately want to seek from her, but travelling together, you can leave it for when both of you are safe."<<endl;
                generateSave(3);
                cout<<"\n(The game has been saved.)"<<endl;
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
                    generateSave(3);
                    cout<<"\n(The game has been saved.)"<<endl;
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
                    cout<<"There are answers you desperately want to seek from her, but travelling together, you can leave it for another time."<<endl;
                    generateSave(3);
                    cout<<"\n(The game has been saved.)"<<endl;
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
    cout<<"\n(The game has been saved.)"<<endl;
    Chapter1_pt2a();
}
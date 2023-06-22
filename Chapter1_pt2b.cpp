#include<iostream>
#include<cstdlib>
#include "ADayinUtopia.cpp"

//--

void Chapter1_pt2b(), explore1_Ch1_2b(), lanaConverse2b();
void ending3();

int yn();
int inventoryCheck();
int inventoryCheckName(string item);

//--

void Chapter1_pt2b() {
    string blankSpace;
    int slimech, slimech2;
    //the part where Lana joins you, ie, eventCounter[0]==4
    battleCounter[0]=1;
    cout<<"You travel for quite some time together without coming across anything strange -- or at least stranger -- when three dark shapes appear from behind a building. They are masses of what looks like sticky liquid, shaking and changing shape as they slide. It reminds you of jelly, if jelly was large and moved by itself. Ms. Lana freezes and stretches a hand for you to do the same. You both watch as they slide their way through, apparently unnoticing..."<<endl;
    cin>>blankSpace;
    
    if(eventCounter[4]==0 || mainchar.LUCK<6) {
        cout<<"In the sudden silence, your injuries weigh on you more than before, and you stumble."<<endl;
        cout<<"There is a heartbeat's worth of pause, and then all three slimes change course for you."<<endl;
        cout<<"Ms. Lana whispers only one word into the air."<<endl;
        cout<<"LANA: Dammit."<<endl;
        cin>>blankSpace;
        cout<<endl;
        
        cout<<"You face three Slimes."<<endl;
        battleCounter[1]=1;
        int opponents[4]={3,3,3,3};
        battleMechanic(opponents);
        battleCounter[1]=0; //resetting the battleCounter after it has affected the battle it is supposed to; this only holds for when there are no random encounter

        cout<<"\nEach slime squishes in on itself once defeated, making a sound like stretched rubber before plopping, their vicosity brought to a sudden end. They leave behind only a greyish sphere. You're reminded of what happened when the mushrooms were killed too. Is there any reason all these things disappear leaving just a single item?\n"<<endl;

        cout<<"The situation isn't any better than before, but without any enemies in open sight, you decide to risk the chance and look around a bit. With both of you as tired as you are, it'll be an opportunity to take a breather too."<<endl;
        cin>>blankSpace;
        explore1_Ch1_2b();

        if(eventCounter[5]==1) {
            cout<<"You need a place to rest, and one of the buildings nearby look perfect. You gesture to Lana, who follows you in."<<endl;
        }
        else {
            cout<<"You need a place to rest, but you're not sure where you can go. Luckily half the members of the expedition are carrying a canvas tent with them and Lana is one. The two of you spend hours setting up the tent, at which point the sky should have darkened, but it still retains golden-orange waves amidst the growing purple. You look down at your pocket watch, which says that the time is half past four. You're not sure what's right anymore."<<endl;
            if(inventoryCheckName("slime remnant")==1 && (eventCounter[0]==6 || eventCounter[0]==8)) {
                cout<<"LANA: I wouldn't suggest this if the situation wasn't so serious..."<<endl;
                cout<<"You are put on guard by her solemn tone. The two of you did have some casual conversations prior, but after she revealed the truth, you haven't quite been interested in speaking."<<endl;
                cout<<"YOU: What is it?"<<endl;
                cout<<"LANA: Do you still have what you took from the monster?"<<endl;
                cout<<"You nod, pulling out the sphere."<<endl;
                cout<<"LANA: It's a Beyonder characteristic."<<endl;
                cout<<"Your eyes widen."<<endl;
                cin>>blankSpace;
                cout<<"LANA: But I can't say for which pathway nor can I guarantee that consuming it is safe, with how we found it."<<endl;
                cout<<"LANA: My purification would remove any corruption, but Beyonder characteristics inherently contain madness."<<endl;
                cout<<"YOU: You think we should make use of this?"<<endl;
                cout<<"LANA: That's right. There are two ways. One is to have it influence an item and get a Sealed Artifact--a magical item--out of it. The other... is to consume it."<<endl;
                cout<<"LANA: I would not recommend the second option at all. There is a very high chance you might die or, if you do not, be turned into a monster much like the ones we've encountered. There are too many doubts surrounding this item. But I wanted to let you know what I do; that there are two options."<<endl;
                cout<<"Lana is a lot more skilled in this than you. She could be lying, but there's really no reason. So do you..."<<endl;
                cout<<"1) ask how to make a Sealed Artefact"<<endl;
                cout<<"2) ask how to consume the slime remnant"<<endl;
                slimech=chartoint();
                while(slimech<1 || slimech>2) {
                    cout<<"Invalid choice."<<endl;
                    slimech=chartoint();
                }
                switch(slimech) {
                    case 1:
                    break;
                    case 2: cout<<"YOU: With the situation the way it is, death isn't so bad."<<endl;
                    cout<<"Lana gapes at you."<<endl;
                    cout<<"YOU: Not that I plan on dying, but the chance of becoming a magic user--Beyonder--as low as it is, is worth the risk."<<endl;
                    cout<<"LANA: If you become a monster..."<<endl;
                    cout<<"YOU: Kill me, I guess. As I am, it's not like I'm much help here."<<endl;
                    cout<<"LANA: "<<mainchar.Name<<", please reconsider. You have been of great help as you are, and the chance of your survival if you go through with this is something like 1%."<<endl;
                    cout<<"Do you change your mind?"<<endl;
                    slimech2=yn();
                    if(slimech2==1)
                        slimech=0;
                    else {
                        cout<<"Maybe it's that your friends are out there going through things just as horrific as you, with nobody like Lana to help. Maybe it was the moment you saw all those mushrooms and your heart dropped to your stomach."<<endl;
                        cout<<"Life doesn't matter all that much."<<endl;
                        cout<<"YOU: Well, that's kind of you. But I'm ready to take the risk."<<endl;
                        cout<<"Lana frowns, clenching her fists."<<endl;
                        cout<<"YOU: Tell me how to do this."<<endl;
                        cout<<"LANA: ..."<<endl;
                        cout<<"YOU: Ms. Lana. This is my choice."<<endl;
                        cout<<"After another minute of silence, she finally speaks reluctantly."<<endl;
                        cout<<"LANA: Swallow it."<<endl;
                        cout<<"YOU: What?"<<endl;
                        cout<<"LANA: Generally a potion can be made using Beyonder characteristics to make the process safer, but that's only possible if you know what pathway and sequence the characteristic is for, as well as the formula connected to it."<<endl;
                        cout<<"LANA: In this case, we have neither of that."<<endl;
                        cout<<"You look down at the grayish core, feeling a bit disgusted. Are you really ready for this?"<<endl;
                        slimech2=yn();
                        if(slimech2==0)
                            slimech=0;
                        else {
                            cout<<"With a leap of faith, you down what you're holding."<<endl;
                            cout<<"It slides down your throat, both slimy and rough in a way you can't quite describe. Your stomach turns and you force yourself to keep it down."<<endl;
                            cout<<"In that moment, you feel a change starting from the innermost part of you."<<endl;
                            cout<<"It's like the very particles of your existence are being overwritten, flashes of darkness in your vision, interspersed with red lightning and endless cloudy skies, screams and whispers and distinctly inhuman sounds residing in your ears and refusing to leave."<<endl;
                            cout<<"You can't move. You can't make a sound. You're no longer sure who 'you' are, if there is some life in you or if you are simply a part of your visions without thought and feeling."<<endl;
                            cout<<"No, there is feeling. There's pain, a place that must be your head pounding on the verge of splintering, a place that must be your chest expanding and expanding and then contracting, taking away your breath like a sledgehammer."<<endl;
                            cout<<"There's another voice, screaming and screaming, but it's not louder than everything you're already hearing, so easily drowned."<<endl;
                            srand(time(0));
                            int chance=rand()%100+1;
                            if(chance<90)
                                ending3();
                            else {
                                mainchar.beyonder(eventCounter[2]);
                                cout<<"The voice becomes clearer, cutting through the rest. It's saying a word you quite can't grasp..."<<endl;
                                cout<<"..."<<mainchar.Name<<"!..."<<endl;
                                cout<<"No, you do know it."<<endl;
                                cout<<"That..."<<endl;
                                cout<<"You remember family. Friends. People. The cities of Tingen and Backlund."<<endl;
                                cout<<"That word is a name. Your name."<<endl;
                                cout<<"It's who you are."<<endl;
                                cout<<"Slowly, clarity returns to you, pushing aside the nonsensical and maddening things from before. You feel like you've gotten a grasp of yourself."<<endl;
                                cout<<"Surviving the experience, you gain new knowledge."<<endl;
                                cout<<"You're not sure how, but you know now that you have become a "<<mainchar.Path<<"."<<endl;
                                }
                            }
                        }
                    break;
                    default: cout<<"Invalid choice."<<endl;
                }
            }
        }
    }

    else {
        cout<<"Though you are rather tired, you manage to stay still as a statue until the three creatures move past. You inwardly sigh in relief as they disappear into the distance."<<endl;
        cout<<"Ms. Lana moves forward with careful steps and you follow behind her, scanning the surroundings. So far there isn't any sign of trouble, though you're well aware you're an amateur in such situations and definitely not in your best state."<<endl;
        cout<<"The two of you press your backs to the wall of another building, hiding yourselves in the shadow it casts, as you inch past the area."<<endl;
        cout<<"In the distance you can see figures that are very much not human moving about, and you hope that they are as incapable of seeing through the dark as you are. Not that hopes alone will change reality, but it's all you have right now."<<endl;
        cin>>blankSpace;
        cout<<"LANA: No better time to have a seer with us..."<<endl;
        cout<<"She says it under her breath, clearly to herself rather than you, but with the silence and proximity, you hear her well enough. Seer? What does Ms. Lana expect a fortune-teller to do? Accurately plan out your future for you?"<<endl;
        cout<<"...could there be fortune-tellers like that? Could you have met them in Loen? Ms. Lana did give you an item capable of blasting creatures with light; you don't think you can put anything down as impossible."<<endl;
        cout<<"You wonder if there'll be a time when you can ask these questions to her and get answers. You're willing to wait, but the unknown wraps around you like a dense fog and being able to dispel it would bring some relief if nothing else."<<endl;
        cout<<"You cover a good distance with the good luck of not encountering any danger, when dark shadows flash ahead of you."<<endl;
        cin>>blankSpace;
        cout<<"Ms. Lana doesn't have to say a word. You immediately draw out your blade, jaw set, for whatever is coming. The shadows move around the two of you, but your reflexes aren't good enough to track them."<<endl;
        cout<<"With a wave of Ms. Lana's hand, bursts of light erupt, causing the shadows to slow down."<<endl;
        cout<<"You can now see them clearly. Two wolf-shaped beasts with fur as black as the night sky, their teeth dripping with saliva. They have a somewhat tattered look to them, like travelling cloaks that underwent a journey, but travelling cloaks don't make sounds or attack."<<endl;
        cout<<"...at least the ones you know."<<endl;
        cout<<"Before you can further think of your metaphor, the wolves prowl towards you.\n"<<endl;
        cin>>blankSpace;
        cout<<"You face two Dark Wolves."<<endl;
        
        int opponents[3]={2,2,2};
        battleMechanic(opponents);
    }
    generateSave(4);
    cout<<"(The game has been saved.)"<<endl;
    cout<<"\nFor now, the demo ends here."<<endl;
    cout<<"Thank you for playing."<<endl;
    exit(0);
}

//currently being worked on
void explore1_Ch1_2b() {
    int exploreChoice, surety=0;
    string blankSpace;
    do {
        cout<<"\nDo you-"<<endl;
        cout<<"1) take note of your surroundings"<<endl;
        cout<<"2) start making a rudimentary map"<<endl;
        cout<<"3) look closer at the slime remnants"<<endl;
        cout<<"4) talk to Lana"<<endl;
        cout<<"5) end"<<endl;
        exploreChoice=chartoint();
        switch(exploreChoice) {
            
            case 1:
            cout<<"\nThis looks like the outskirts of Utopia."<<endl;
            cout<<"The number of buildings are less, but the way they are arranged speaks of a well-planned town."<<endl;
            cout<<"...Perhaps too well-planned. Most towns start off as settlements that later due to population growth expand and gain order, but Utopia seems as if it was envisioned from the start."<<endl;
            cout<<"Which doesn't mean it's a cookie-cutter place. There are roads and buildings less-maintained than others, variations in style between certain regions, and the entirety befits an island population with limited interaction to the outside. But at the same time, from what you've seen wandering about and the academic knowledge you have about history and civilisation, it doesn't quite seem right."<<endl;
            cout<<"You notice the building around which the slimes appeared is small and moss-covered, but thankfully free of mushrooms."<<endl;
            eventCounter[5]=1;
            if(eventCounter[0]==5)
                eventCounter[0]=6;
            else if(eventCounter[0]==7)
                eventCounter[0]=8;
            break;
            
            case 2:
            if(inventoryCheckName("map")==0) {
                cout<<"Previously as you travelled with the team, one of them had been marking down the route you were all taking and the places found. Now that you've split up though, you feel it vital to make one of your own."<<endl;
                cout<<"Your memory is rather good. In a few minutes, you end up with something that -- while one would have to be extraordinarily generous to call it a \"map\" -- is somewhat of a helpful sketch taken both from your study of Utopia as well as what you've gone through now."<<endl;
                map.obtain();
                inventory[inventoryCount]=map;
                inventoryCount++;
            }
            else
                cout<<"You look over what you've already drawn, trying to recall more and perfect it. Unfortunately what's there is all you know for now."<<endl;
            if(eventCounter[0]==5)
                eventCounter[0]=6;
            else if(eventCounter[0]==7)
                eventCounter[0]=8;
            break;
            
            case 3:
            if(inventoryCheckName("slime remnant")==0) {
                cout<<"Curious about what the mushrooms and now the slimes have been leaving behind, you kneel and reach out a hand to the greyish thing."<<endl;
                cout<<"LANA: Wait!"<<endl;
                cout<<"You freeze. Her voice is low, but there's an element of suddenness to it."<<endl;
                cin>>blankSpace;
                cout<<"LANA: What they've left behind... it might be dangerous."<<endl;
                cout<<"LANA: Give me a second."<<endl;
                cout<<"She kneels down beside you, murmuring indistinctly under her voice. You watch with wide eyes as a soft light wraps around one of the things, then vanishes without a trace."<<endl;
                cout<<"YOU: That... you..."<<endl;
                cout<<"LANA: I purified it. It can still be dangerous, no doubt, and requires care but it should be possible to handle."<<endl;
                cout<<"She looks drained by what she has done, but still alert."<<endl;
                cout<<"Quickly grabbing and putting on gloves from your backpack, although you're not sure if they would hold against... whatever this is... that you're picking up."<<endl;
                slime.obtain();
                inventory[inventoryCount]=slime;
                inventoryCount++;
            }
            else {
                cout<<"You've already looked at them."<<endl;
                cout<<"There are two more 'remnants' left on the ground, but you're content having just the one."<<endl;
            }
            if(eventCounter[0]==5)
                eventCounter[0]=6;
            break;

            case 4:
            if(eventCounter[0]==5)
                cout<<"You don't think you can speak to Ms. Lana yet. It'd be better to do something else, even if you've taken care of it before."<<endl;
            else if(eventCounter[0]==6) {
                cout<<"You feel your emotions have settled enough to talk civilly with Ms. Lana again."<<endl;
                lanaConverse2b();
            }
            else
                lanaConverse2b();       
            break;
            
            case 5:
            cout<<"Are you sure? This will end the current exploration period."<<endl;
            surety=yn();
            if(surety==1) {
                generateSave(4);
                /*cout<<"(The game has been saved.)"<<endl;
                cout<<"\nFor now, the demo ends here."<<endl;
                cout<<"Thank you for playing."<<endl;
                exit(0);*/
            }
        }
    } while(surety!=1);
}

void lanaConverse2b() {
    int converse=0, end=0;
    string blankSpace;
    do {
        cout<<"\nWhat do you speak to her about?"<<endl;
        cout<<"1) the slimes"<<endl;
        cout<<"2) Utopia"<<endl;
        cout<<"3) the supernatural"<<endl;
        if(eventCounter[6]==1) {
            cout<<"4) Calderon City"<<endl;
            cout<<"5) end"<<endl;
        }
        else
            cout<<"4) end"<<endl;
        converse=chartoint();
        if(eventCounter[0]==4 && converse!=4) {
            switch(converse) {
            case 1:
            cout<<"LANA: It isn't just the mushrooms..."<<endl;
            cout<<"YOU: Do you know something about these creatures?"<<endl;
            break;
            
            case 2:
            cout<<"LANA: Utopia is far more of a terror than I could have imagined..."<<endl;
            cout<<"YOU: ...what did you imagine, precisely?"<<endl;
            break;
            
            case 3:
            cout<<"YOU: The power in what you gave me, and what you've been doing to these... things. What is it about?"<<endl;
            cout<<"LANA: That..."<<endl;
            break;

            default: cout<<"Invalid choice."<<endl;
            lanaConverse2b();
            }
        }
        if(eventCounter[0]==4) {
            eventCounter[0]=5;
            cout<<"\nYou were planning to leave these questions for when the two of you had some space to speak without the hanging tension of death, but it hits you that such a perfect time isn't going to fall into your laps soon.\n"<<endl;
            cin>>blankSpace;
            cout<<"Ms. Lana licks her lips, her expression troubled, and you barely resist from pressing her more."<<endl;
            cout<<"At last, she says with a sigh-\n"<<endl;
            cout<<"LANA: The Society believed the remnants of Utopia could be dangerous."<<endl;
            cout<<"LANA: The events surrounding Utopia's existence were rather supernatural, after all, and remains of that might linger. We wanted our own team to handle it... they have certain experience in this field."<<endl;
            cout<<"LANA: But you and your friends were heading it, and speaking of the supernatural to ordinary people is prohibited. So I was sent along to deal with any issues that might arise."<<endl;
            cout<<"LANA: We could not have known it could be this bad. This... is beyond the scope of imagination."<<endl;
            cout<<"She finishes, her expression no less troubled and her gaze still on the slimes."<<endl;
            cin>>blankSpace;
            cout<<"It take you a bit to register the explanation. *That's* why the Society offered to do the expedition instead? Rather than just letting you know? Letting you all walk into something dangerous..."<<endl;
            cout<<"\nDo you get openly angry?"<<endl;
            int anger=yn();
            if(anger==1) {
                cout<<"YOU: Was the secrecy worth it?"<<endl;
                cout<<"Your tone is colder than it has ever been."<<endl;
                cout<<"YOU: There's exactly two of us standing here. The other nine could be dead or worse. People I requested sign up, my own friends..."<<endl;
                cout<<"\nThinking of those five makes you stutter, and you quickly blink back tears. You're aware how lucky you are to be standing here... could they have been that lucky too?"<<endl;
                cin>>blankSpace;
                cout<<"\nYOU: We could still die here."<<endl;
                cout<<"YOU: And rather than being honest... the Society was ready to just leave it be!"<<endl;
                cout<<"YOU: If they already know, if you already knew, how could you let this happen!"<<endl;
                cout<<"YOU: I guess it was fine, right, as long as any \"prohibited\" information didn't get leaked."<<endl;
                cout<<"Heart beating rapidly in your chest out of your rage rather than any fear, you step away from Ms. Lana and turn away. Your vision blurs and you face the ground trying to hide your face.\n"<<endl;
                cin>>blankSpace;
                cout<<"There is a pause before you hear her voice, strained."<<endl;
                cout<<"LANA: I know no amount of apologies will make up for what has unfolded."<<endl;
                cout<<"LANA: I..."<<endl;
                cout<<"She seems to think better of whatever she wanted to say, falling into silence."<<endl;
                cout<<"You feel like you need some time before you can try talking to her again."<<endl;
                cin>>blankSpace;
                end=1;
            }
            else {
                cout<<"You have to grit your teeth to not burst out the way you want to."<<endl;
                cout<<"All the same, Ms. Lana seems to know she's not in your good graces."<<endl;
                cout<<"She frowns, looking as if she's about to speak, then stops, thinking better of it."<<endl;
                cout<<"You're glad. While the situation isn't one in which you can rage like you wish, you're not in any mood to talk to her."<<endl;
                cout<<"You'd like to have some time by yourself before it comes to that."<<endl;
                end=1;
            }
        }
        else {
            switch(converse) {
                case 1:
                cout<<"LANA: I've never seen such creatures before. Then again, Beyonder monsters take all sorts of shapes and forms, so it isn't surprising."<<endl;
                cout<<"LANA: Though their high concentration in one area alone... it's like the Spirit World's Calderon City brought into physical reality."<<endl;
                eventCounter[6]=1;
                break;

                case 2:
                cout<<"LANA: My knowledge of Utopia as a whole is less than yours, but when it comes to the supernatural side..."<<endl;
                cout<<"LANA: The Society gave me additional info. Part of that is that Utopia has a link to Gehrman Sparrow, and perhaps by extension the Fool Himself."<<endl;
                cout<<"LANA: Through hidden sources, they have been able to confirm a level of pollution in Utopia caused by most likely Their enemies."<<endl;
                cout<<"LANA: Which means that Utopia was attacked in retaliation against Sparrow or another Blessed of the Fool, and what we see is the aftermath of that."<<endl;
                cout<<"LANA: Even to me, the Society heads were careful in how they spoke."<<endl;
                cout<<"LANA: I imagine due to the affiliation with the Fool, the matter becomes more complex with a need to handle carefully."<<endl;
                break;
                
                case 3:
                cout<<"LANA: The supernatural..."<<endl;
                cout<<"LANA: Those of us involved in it call it \"extraordinary\" instead."<<endl;
                cout<<"LANA: Those who can use such powers are Beyonders, and the powers they can use depend on the pathway they choose."<<endl;
                cout<<"LANA: There are 22 pathways known to the world, and each pathway has a level of specialisation that runs from Sequence 9, which is the lowest, to Sequence 1."<<endl;
                cout<<"LANA: I'm sorry if that's a lot to absorb."<<endl;
                cout<<"LANA: Extraordinary matters are a vast field, and I've boiled it down to the bare basics I can."<<endl;
                break;

                case 4:
                if(eventCounter[6]==1) {
                    cout<<"LANA: What's Calderon City...?"<<endl;
                    cout<<"LANA: Ah, well, you see, there are different dimensions that exist."<<endl;
                    cout<<"LANA: Our physical reality is the one we live in, but there are also places like the Spirit World, inhabited by -- as the name suggests -- various spirits, and the Astral Plane, which I'm not much informed of except that it is where the domain of the deities can be found. Their divine kingdoms."<<endl;
                    cin>>blankSpace;
                    cout<<"LANA: Back to Calderon City-- until the Fourth Epoch, the God of Death was a huge force that dominated the Spirit World. Many creatures found there still are loyal to Him and His kin."<<endl;
                    cout<<"LANA: Then as you know, He went mad and the other deities allied to take Him down, causing a war unlike any other."<<endl;
                    cout<<"LANA: The Calderon City is His domain. With His downfall, the city is highly difficult to traverse for Beyonders, as it contains powerful spirit creatures."<<endl;
                    cout<<"LANA: I can't say if it was any better in His time, since that was back in the Fourth Epoch, but for anyone who travels the Spirit World, bypassing Calderon City is for the best."<<endl;
                    cout<<"LANA: ...all of this to say that Utopia struck me on the surface as such a place."<<endl;
                }
                else {
                    end=1;
                    break;
                }

                case 5:
                if(eventCounter[6]!=1)
                    cout<<"Invalid choice."<<endl;
                else {
                    end=1;
                    break;

                default: cout<<"Invalid choice."<<endl;
                break;
                }
            }
        }
    } while(end!=1);
}

/* Tutorial 5: In certain exploration sessions, you must be quick as the longer you stay, the more chance there is that monsters will find and attack you. Every few times you explore, such an attack may occur. It will also increase your fatigue, making you weaker in subsequent attacks. Hence, keep an eye on your fatigue and attempt to explore properly but also quickly.*/
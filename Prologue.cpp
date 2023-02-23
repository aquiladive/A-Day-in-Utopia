#include<iostream>
#include "ADayinUtopia.cpp"

//--

int yn();

void Prologue_pt1(), Prologue_pt2(), Chapter1_pt1();
void shipExplore(), captainConverse(), lanaConverse(), azikConverse();

void Tutorial1(), Tutorial2();
void ending1();

//--

void Prologue_pt1() {
    string blankSpace;
    cout<<"Disclaimer: This story involves depictions of violence and aspects of eldritch horror."<<endl;
    cout<<"Due to the amount of text barrage, it is recommended to play on a full-screen."<<endl;
    cout<<"For the same reason - ie, to space out said barrage - you will sometimes be prompted to input text for no reason. The input in these cases do not matter."<<endl;
    cout<<"\n...\n"<<endl;
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
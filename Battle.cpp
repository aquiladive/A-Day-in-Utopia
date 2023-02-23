#pragma once
#include<iostream>
#include "Classes.cpp"
#include "ADayinUtopia.cpp"
using namespace std;

//--

int hp; //for the same thing as in "ADiU"
int battleCounter[3]; //for factors that affect certain battles

//--

int itemUse(string Item);
void levelUp(int battleExp);
void statAllocation();
void beliefBenefits(int belief);

void battleMechanic(int opponents[]);

void battleEnding(), Tutorial3();

//--

void beyonderEffects(string effect) {
    if(effect=="DEF Down 1") {
        cout<<"The spell weakens you."<<endl;
    }
    else if(effect=="Dizzy") {
        cout<<"The spell makes it hard for you to concentrate."<<endl;
    }
    else if(effect=="Trapped 1") {
        cout<<"The spell tightens around you painfully."<<endl;
    }
}

int itemUse(string Item) {
    if(Item=="Lana's emblem")
        return 1;
    else
        return 0;
}

void beliefBenefits(int belief) {
    switch(belief) {
        case 1:
        mainchar.LUCK+=2;
        mainchar.MDEF+=2;
        mainchar.ATK+=2;
        break;
        case 2:
        mainchar.ATK+=2;
        mainchar.MATK+=2;
        break;
        case 3:
        mainchar.HP+=5;
        break;
        case 4:
        mainchar.MATK+=2;
        mainchar.DEF+=2;
        break;
        case 5:
        mainchar.LUCK+=3;
        mainchar.DEF+=2;
        mainchar.MDEF+=2;
        break;
        case 6:
        break;
    }
}

void levelUp(int battleExp) {
    //this only holds good for if the MC can level up only once by battle EXP
    //ie battles should not provide EXP that will boost level multiple times
    int initialExp=0, expReq=20;
    for(int i=1;i<mainchar.Level;i++) {
        expReq+=i*5;
    }
    if(battleExp>=expReq) {
        mainchar.Level+=1;
        mainchar.battleExp-=expReq;
        cout<<"You have levelled up to Lv."<<mainchar.Level<<"."<<endl;
        if(mainchar.Level==2)
            Tutorial3();
        statAllocation();
    }
}

void statAllocation() {
    //this also only holds for levelling up once
    int statpt=5, stat, pt;
    while (statpt>0) {
        cout<<"Your current stats are:\n(1) HP = "<<mainchar.HP<<endl;
        cout<<"(2) ATK = "<<mainchar.ATK<<endl;
        cout<<"(3) DEF = "<<mainchar.DEF<<endl;
        cout<<"(4) MATK = "<<mainchar.MATK<<endl;
        cout<<"(5) MDEF = "<<mainchar.MDEF<<endl;
        cout<<"(6) LUCK = "<<mainchar.LUCK<<endl;
        cout<<"You have "<<statpt<<" stat points left to allocate."<<endl;
        cout<<"Choose stat you wish to assign points to, using the numbered index."<<endl;
        cin>>stat;
        if(stat<1 || stat>6)
            cout<<"Invalid stat.\n"<<endl;
        else {
            cout<<"How many points do you want to assign?"<<endl;
            cin>>pt;
            if (pt<=statpt && pt>0) {
                switch(stat) {
                    case 1: cout<<"Your HP has been boosted by "<<pt;
                    mainchar.HP+=pt;
                    break;
                
                    case 2: cout<<"Your ATK has been boosted by "<<pt;
                    mainchar.ATK+=pt;
                    break;
                
                    case 3: cout<<"Your DEF has been boosted by "<<pt;
                    mainchar.DEF+=pt;
                    break;
                
                    case 4: cout<<"Your MATK has been boosted by "<<pt;
                    mainchar.MATK+=pt;
                    break;
                
                    case 5: cout<<"Your MDEF has been boosted by "<<pt;
                    mainchar.MDEF+=pt;
                    break;

                    case 6: cout<<"Your LUCK has been boosted by "<<pt;
                    mainchar.LUCK+=pt;
                    break;
                }
                if(pt>1)
                    cout<<" points."<<endl;
                else
                    cout<<" point."<<endl;
                statpt-=pt;
            }
            else {
                cout<<"Invalid stat points.\n"<<endl;
            }
        }
    }
}

void battleMechanic(int opponents[]) {
    //array opponents should have [0] be number of enemies, followed by each position integer indicating which enemy it is
    int turn=0;
    int choice, choice2, attackChoice, itemChoice, damage=0;
    int enemyCount=opponents[0];
    int enemyAttack[2]; //2 to hold choice + damage
    int battleExp=0;
    Monster Enemy[opponents[0]];
    Protag Reader=mainchar; //so that stat/status changes in battle don't affect overworld mainchar
    if(battleCounter[0]==1)
        Reader.HP=3*Reader.HP/4;
    
    for(int i=0;i<opponents[0];i++) {
        switch(opponents[i+1]) {
            case 1:
            Bounceshroom.mattack1="Spore";
            Bounceshroom.mattack1effect="DEF Down 1";
            Bounceshroom.mattack2="Bounce";
            Bounceshroom.mattack2effect="None";
            Bounceshroom.exppoint=10;
            battleExp+=10;
            Enemy[i]=Bounceshroom;
            break;
            
            case 2:
            DarkWolf.mattack1="Shadow Claw";
            DarkWolf.mattack1effect="None";
            DarkWolf.mattack2="Restrain";
            DarkWolf.mattack2effect="Trapped 1";
            DarkWolf.exppoint=15;
            battleExp+=15;
            Enemy[i]=DarkWolf;
            break;

            case 3:
            Slime.mattack1="Acid";
            Slime.mattack1effect="DEF Down 1";
            Slime.mattack2="Ooze Trap";
            Slime.mattack2effect="Trapped 1";
            battleExp+=10;
            Enemy[i]=Slime;
            break;
        }
    }
    
    do {
        if(turn%2==0) {
            //player's turn
            int invalid=0;
            if(Reader.Status=="DEF Down 1") {
                Reader.Status="None";
                Reader.DEF=mainchar.DEF;
            }
            if(Reader.Status=="Trapped 1") {
                cout<<"You feel as if you're being squeezed painfully."<<endl;
                cout<<"You take 2 points of damage."<<endl;
                Reader.HP-=2;
                Reader.Status="None";
            }
            if(Reader.HP<=0)
                battleEnding();
            cout<<"\nYour turn:"<<endl;
            cout<<"Do you:\n1) Attack\n2) Defend\n3) Use Item"<<endl;
            cin>>choice;
            switch(choice) {
                case 1:
                cout<<"Which enemy do you attack?"<<endl;
                for(int i=1;i<=enemyCount;i++) {
                    cout<<i<<") "<<Enemy[i-1].Name<<endl;
                }
                cin>>attackChoice;
                if(attackChoice>0 && attackChoice<=enemyCount) {
                    attackChoice--;
                    damage=Reader.attack()-Enemy[attackChoice].DEF;
                    if(damage<=0)
                        damage=1;
                    cout<<Reader.Name<<" deals "<<damage<<" damage."<<endl;
                    Enemy[attackChoice].HP=Enemy[attackChoice].HP-damage;
                    if(Enemy[attackChoice].HP<=0) {
                        cout<<Enemy[attackChoice].Name<<" has been defeated."<<endl;
                        enemyCount--;
                        for(int i=attackChoice;i<enemyCount;i++) {
                            Enemy[i]=Enemy[i+1];
                        }
                    }
                    else
                        cout<<Enemy[attackChoice].Name<<" has "<<Enemy[attackChoice].HP<<" health remaining."<<endl;
                }
                else {
                    cout<<"Invalid choice."<<endl;
                    invalid=1;
                    turn++;
                }
                break;
                
                
                case 2:
                break;
                
                
                case 3:
                if(inventoryCount==0) {
                    cout<<"You have no items to use."<<endl;
                    invalid=1;
                    turn++;
                }
                else {
                    cout<<"Which item do you use?"<<endl;
                    for(int i=1;i<=inventoryCount;i++) {
                        cout<<i<<") "<<inventory[i-1].itemName<<endl;
                        cout<<"   -"<<inventory[i-1].Description<<endl;
                    }
                    cin>>choice2;
                    if(choice2>0 && choice2<=inventoryCount) {
                        itemChoice=itemUse(inventory[choice2-1].itemName);
                        switch(itemChoice) {
                            case 0:
                            cout<<"That item cannot be used."<<endl;
                            invalid=1;
                            turn++;
                            break;
                            
                            case 1:
                            emblemUse++;
                            attackChoice=0;
                            cout<<"Blinding light falls from the sky, and you find yourself turning your face away for a second."<<endl;
                            Enemy[0].HP-=(3+Reader.MATK);
                            if(Enemy[0].HP<=0) {
                                cout<<Enemy[0].Name<<" has been defeated."<<endl;
                                enemyCount--;
                            for(int i=attackChoice;i<enemyCount;i++) {
                                Enemy[i]=Enemy[i+1];
                                }
                            }
                            else
                                cout<<Enemy[0].Name<<" has "<<Enemy[0].HP<<" health remaining."<<endl;
                            if(emblemUse==5) {
                                cout<<"The emblem loses its lustre, looking as if about to break. You don't think you can use it any more."<<endl;
                                emblem.clear();
                                inventoryCount--;
                            } //end of the emblemUse if
                        } //end of itemChoice switch
                    } //end of the choice validity if
                    else {
                        cout<<"Invalid choie."<<endl;
                        invalid=1;
                        turn++;
                    }
                } //end of initial turn choice switch
            } turn++; //end of user turn
            if(battleCounter[0]==1 && invalid!=1 && enemyCount!=0) {
            //ie Lana is present and supposed to fight
                cout<<"Lana attacks."<<endl;
                srand(time(0));
                int lana=rand()%2+1;
                if(lana==1)
                    damage=Lana.ATK-Enemy[0].DEF;
                else
                    damage=Lana.MATK-Enemy[0].MDEF;
                cout<<"She deals "<<damage<<" damage."<<endl;
                if(damage<=0)
                    damage=1;
                Enemy[0].HP-=damage;
                if(Enemy[0].HP<=0) {
                    cout<<Enemy[0].Name<<" has been defeated."<<endl;
                    enemyCount--;
                    for(int i=0;i<enemyCount;i++) {
                        Enemy[i]=Enemy[i+1];
                    }
                }
                else
                    cout<<Enemy[0].Name<<" has "<<Enemy[0].HP<<" health remaining."<<endl;
            }
        } //end of the first if

        else {
            cout<<"\nEnemy turn:"<<endl;

            //please remember in the future to add conditions for if the enemy is inflicted by a status
            //or unite both Reader and Enemy status effects under one function... which was what beyonderEffect was intended to be...
            for(int i=0;i<enemyCount;i++) {
                if(Enemy[i].HP<=0) {
                    cout<<Enemy[i].Name<<" has been defeated."<<endl;
                    enemyCount--;
                    for(int i=attackChoice;i<enemyCount;i++) {
                        Enemy[i]=Enemy[i+1];
                    }
                }
            }

            for(int i=0;i<enemyCount;i++) {
                damage=Enemy[i].attack();
                if(monsterChoice!=1) {
                    if(monsterChoice==2)
                        Reader.Status=Enemy[i].mattack1effect;
                    else if(monsterChoice==3)
                        Reader.Status=Enemy[i].mattack2effect;
                    beyonderEffects(Reader.Status);
                }
                if(Reader.Status=="DEF Down 1")
                    Reader.DEF-=2;
                if(monsterChoice==1)
                    damage=damage-Reader.DEF;
                else if(monsterChoice>1)
                    damage=damage-Reader.MDEF;
                if(choice==2 && monsterChoice==1)
                    damage=damage-2*Reader.DEF;
                else if(choice==2 && monsterChoice>1)
                    damage=damage-2*Reader.MDEF;
                if(damage<=0)
                    damage=1;
                Reader.HP=Reader.HP-damage;
                cout<<Enemy[i].Name<<" deals "<<damage<<" damage."<<endl;
            }
            
            if(Reader.HP<=0)
                battleEnding();
            
            else
                cout<<Reader.Name<<" has "<<Reader.HP<<" health remaining."<<endl;
            
            turn++;
        }
    } while(enemyCount!=0);
    hp=Reader.HP;
    mainchar.battleExp+=battleExp;
    cout<<endl;
    levelUp(mainchar.battleExp);
}

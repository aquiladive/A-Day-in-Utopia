#include<iostream>
#include "ADayinUtopia.cpp"

//--

void Chapter1_pt2a();

int yn();
int inventoryCheck();
int inventoryCheckName();

//--

void Chapter1_pt2a() {
    //the part where Lana does not join you, ie, eventCounter[0]<4
    generateSave(4);
    cout<<"(The game has been saved.)"<<endl;
    cout<<"\nFor now, the demo ends here."<<endl;
    cout<<"Thank you for playing."<<endl;
    exit(0);
}
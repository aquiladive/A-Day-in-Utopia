#include<iostream>
#include<fstream>
using namespace std;

int main() {
    fstream savefile;
    string line;
    int ch;
    while(1) {
        cout<<"1. Create save"<<endl;
        cout<<"2. Load save"<<endl;
        cin>>ch;
        switch(ch) {
            case 1:
            savefile.open("save.txt",ios::out);
            cout<<"Give a string to save."<<endl;
            cin>>line;
            savefile<<line;
            savefile.close();
            break;

            case 2:
            savefile.open("save.txt", ios::in);
            if(!savefile)
                cout<<"Savefile cannot be found."<<endl;
            else {
                cout<<"Data stored is:"<<endl;
                char ch;
                while(1) {
                    savefile>>ch;
                    if(savefile.eof())
                        break;
                    cout<<ch;
                }
                cout<<endl;
            }
            savefile.close();
            break;
        }
    }
}
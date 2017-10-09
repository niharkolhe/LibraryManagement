#include "includes.cpp"

using namespace std;
string bold_on()
{
    return "\e[1m";
}

string bold_off()
{
    return "\e[0m";
}

string red_text()
{
    return "\033[1;31m";
}
string black_text()
{
    return "\033[1;30m";
}
string green_text()
{
    return "\033[1;32m";
}
string yellow_text()
{
    return "\033[1;33m";
}
string blue_text()
{
    return "\033[1;34m";
}
string magenta_text()
{
    return "\033[1;35m";
}
string cyan_text()
{
    return "\033[1;36m";
}
string white_text()
{
    return "\033[1;37m";
}
string reset_text()
{
    return "\033[0m";
}
string white_bg()
{
    return "\033[1;42m";
}

void libName(){
/*
cout<<"        ___          ___         _____  _____                   _____   ___   ____    ___   ____             "<<endl;
cout<<"       /   \  |     |     \_ _/    |    |                 |       |    |   \  |   \  /   \  |   \  \   /     "<<endl;
cout<<"       |---|  |     |---   _|_     |    -----   ======    |       |    |----  |----  |---|  |----   \ /      "<<endl;
cout<<"       |   |  |___  |___  /   \  __|__  ____|             |___  __|__  |___/  |   \  |   |  |   \    |       "<<endl;
cout<<"                                           DATABASE SYSTEM                                                   "<<endl;
*/
cout<<bold_on()<<magenta_text();
cout<<"           ___         ____         _____  _____                   _____   ___   ____    ___   ____                 "<<endl;
cout<<"          /   \\  |     |     \\_ _/    |    |                 |       |    |   \\  |   \\  /   \\  |   \\  \\   /         "<<endl;
cout<<"          |---|  |     |---   _|_     |    -----   ======    |       |    |----  |----  |---|  |----   \\ /          "<<endl;
cout<<"          |   |  |___  |___  /   \\  __|__  ____|             |___  __|__  |___/  |   \\  |   |  |   \\    |           "<<endl;
cout<<yellow_text();
cout<<"--------------------------------------------------------------------------------------------------------------------";
cout<<blue_text()<<endl;
cout<<"                                               DATABASE SYSTEM                                                      "<<endl;
cout<<yellow_text();
cout<<"--------------------------------------------------------------------------------------------------------------------";
cout<<bold_off()<<endl;

}

void loadingScreen(){
    system("cls");
    libName();
    cout<<"\n\n\n\n";
    cout<<green_text()<<"      WELCOME TO ALEXIS LIBRARY!!!"<<endl<<endl;
    cout<<blue_text()<<"      Wait for the program to load files"<<endl<<endl;
    cout<<magenta_text()<<"      Loading Book Database: ";
    for(int i=0;i<20;i++){
        Sleep(100);
        cout<<red_text()<<"*";
    }
    for(int j=0;j<20;j++){
        Sleep(100);
        cout<<"\b \b";
    }
    for(int i =0;i<15;i++){
        cout<<"\b \b";
    }
    cout<<magenta_text()<<"Member Database: ";
    for(int i=0;i<20;i++){
        Sleep(100);
        cout<<green_text()<<"*";
    }
    for(int j=0;j<20;j++){
        Sleep(100);
        cout<<"\b \b";
    }
    for(int i =0;i<25;i++){
        cout<<"\b \b";
    }
    cout<<green_text()<<"Both Databases are loaded Succesfully!!";
    cout<<endl<<white_text()<<"\n\n\n      Loading complete. Press Enter to continue.";
    getchar();
}

#include "src/win/includes.cpp"
#include "src/win/libwithmap.cpp"
library l;
class menu{
    int choice;
    public:
    void studentmenu(){
        do{
            system("cls");
            libName();
            cout<<red_text()<<"\n Student Menu: ";
            cout<<green_text();
            cout<<"\n\n1:Search Books \n2:View Your Data \n0:Previous Menu.\n";
            cout<<cyan_text()<<"Enter Choice: ";
            cin>>choice;
            switch(choice){
            case 1:
                    searchBooks();
                    break;
            case 2:
                    l.displayMember();
                    break;
            case 0:
                    return;
            default:
                    cout<<red_text()<<"\nInvalid Choice.";

            }
            cin.ignore();
            cout<<white_text()<<"\nPress Enter to continue.";
            getchar();

        }while(1);
    }
    void adminmenu(){
       system("cls");
       libName();
       cout<<red_text()<<"\n Login: ";
       cout<<cyan_text();
       string password="password";
       cin.ignore();
       cout<<"\nEnter admin Password to continue: ";
       cout<<blue_text();
       string ans=getpass();
       if(password==ans){
         cout<<green_text()<<"Correct Password. Enter to continue.\n";
         getchar();
       }
       else{
         cout<<red_text()<<"Incorrect Password. Press Enter to go back to previous Menu.\n";
         getchar();
         return;
       }

        do{
            system("cls");
            libName();
            cout<<red_text()<<"\n Admin Menu: ";
            cout<<green_text();
            cout<<"\n\n1:Search Books \n2:View books \n3:View Members \n4:Add Book \n5:Add Member \n6:Issue Book \n7:Return Book \n8:Reissue Book \n9:Pay Fine \n0:Previous Menu.\n";
            cout<<cyan_text()<<"Enter Choice: ";
            cin>>choice;
            cout<<magenta_text();
            switch(choice){
            case 1:
                    searchBooks();
                    break;
            case 2:
                    l.displayBooks();
                    break;
            case 3:
                    l.displayMembers();
                    break;
            case 4:
                    l.addBooks();
                    break;
            case 5:
                    l.addMember();
                    break;
            case 6:
                    l.issue();
                    break;
            case 7:
                    l.returnB();
                    break;
            case 8:
                    l.reIssueB();
                    break;
            case 9:
                    l.payFine();
                    break;
            case 0:
                    return;
            default:
                    cout<<red_text()<<"\nInvalid Choice.";

            }
            cin.ignore();
            cout<<white_text()<<"\nPress Enter to continue.";
            getchar();

        }while(1);
    }
    void searchBooks(){
        do{
        system("cls");
        libName();
        cout<<red_text()<<"\n Search Menu: ";
        cout<<green_text();
        cout<<"\n\n1:Search By Author \n2:Search By Title \n3:Search By Publication \n4:Search By Series \n0:Previous menu.\n";
        cout<<cyan_text()<<"Enter Choice: ";
        cin>>choice;
        cout<<magenta_text();
            switch(choice){
            case 1:
                    l.displayByAuthor();
                    break;
            case 2:
                    l.displayByTitle();
                    break;
            case 3:
                    l.displayByPublisher();
                    break;
            case 4:
                    l.displayBySeries();
                    break;
            case 0:
                    return;
            default:
                    cout<<red_text()<<"\nInvalid Choice.";
        }
        cin.ignore();
        cout<<white_text()<<"\nPress Enter to continue.";
        getchar();

        }while(1);


    }
};

int main(){
    loadingScreen();
    menu m;
    int choice;
    do{
        system("cls");
        libName();
        cout<<red_text()<<"\n Main Menu: ";
        cout<<green_text();
        cout<<"\n\n1:Student Menu \n2:Admin menu \n0:Exit \n";
        cout<<cyan_text()<<"Enter Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                    m.studentmenu();
                    break;
            case 2:
                    m.adminmenu();
                    break;
            case 0:
                    return 0;

            default:
                    cout<<red_text()<<"\nInvalid Choice.\n";
                    break;

        }
    }while(1);
    return 0;
 }

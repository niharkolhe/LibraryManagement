#include "constants.cpp"
#include "classes.cpp"
#include "functions.cpp"
#include "interface.cpp"
class books{
    public:
    book b;
    map<int,book> database;
    string temp;
    string cell;
    int index;
    int counter;
    public:
        books(){
            database= map<int,book>();
            int mapindex;
            index =0;
            counter=0;
            ifstream in("Data/data.csv");
            getline(in,temp);
            while(getline(in,temp)){
                stringstream  lineStream(temp);
                getline(lineStream,cell,',');
                stringstream data3(cell);
                data3>>b.ID;
                getline(lineStream,b.title,',');
                getline(lineStream,b.series,',');
                getline(lineStream,b.author,',');
                getline(lineStream,b.publisher,',');
                getline(lineStream,cell,',');
                stringstream data1(cell);
                data1>>b.price;
                getline(lineStream,cell,',');
                stringstream data2(cell);
                data2>>b.stock;
                database[b.ID]=b;
                index++; counter++;

            }

        }

        ~books(){
            ofstream fr("Data/data.csv");
            fr<<"Refrence No.,Title,Series,Author,Publisher,Price,Stock"<<endl;
            for(map<int,book>::iterator it=database.begin(); it!=database.end(); ++it){
                book c= it->second;

                fr<<it->first<<","<<c.title<<","<<c.series<<","<<c.author<<","<<c.publisher<<","<<c.price<<","<<c.stock<<endl;
            }


        }
        void displayBooksTitles(){
            cout<<white_text();
            cout<<endl<<right<<setw(reffsize)<<"Index"<<spaceconst<<left<<setw(titlesize)<<"Title"<<setw(seriessize)<<"Series"<<setw(authorsize)<<"Author"<<setw(publicationsize)<<"Publisher"<<right<<setw(pricesize)<<"Price"<<setw(stocksize)<<"Stock";
            cout<<endl;
            for(int i=0;i<(reffsize+titlesize+seriessize+authorsize+publicationsize+pricesize+stocksize+spaceconst.length());i++)
                cout<<"-";
        }
        void displayBook(int bookno){
            book c=database[bookno];
            cout<<black_text();
            if(c.title.length()>titlesize-5){
                  c.title= string(c.title.begin(),c.title.begin()+titlesize-5);
                  c.title+=dots;
            }
            if(c.series.length()>seriessize-5){
                  c.series= string(c.series.begin(),c.series.begin()+seriessize-5);
                  c.series+=dots;
            }
            cout<<endl<<right<<setw(reffsize)<<bookno<<spaceconst<<left<<setw(titlesize)<<c.title<<setw(seriessize)<<c.series<<setw(authorsize)<<c.author<<setw(publicationsize)<<c.publisher<<right<<setw(pricesize)<<c.price<<setw(stocksize)<<c.stock;
            cout<<white_text();
        }
        void displayBooks(){
            displayBooksTitles();
            for(map<int,book>::iterator it=database.begin(); it!=database.end(); ++it){
                displayBook(it->first);

            }
        }
        void addBooks(){
            cout<<endl;
            book c;
            cin.ignore();
            cout<<"Name: ";
            getline(cin, c.title);
            cout<<"Series: ";
            getline(cin, c.series);
            cout<<"Author: ";
            getline(cin, c.author);
            cout<<"Publisher: ";
            getline(cin, c.publisher);
            cout<<"Stock: ";
            cin>>c.stock;
            cout<<"Price: ";
            cin>>c.price;
            c.ID=1001+index;
            database[1001+index]=c;
            cout<<"\nBook has been Added with ID no: "<<1001+index<<endl;
            index++;

        }

        void displayByAuthor(){
            cin.ignore();
            counter=0;
            cout<<endl<<"Enter author name: ";
            getline(cin,temp);
            displayBooksTitles();
            for(map<int,book>::iterator it=database.begin(); it!=database.end(); ++it){
                book c = it->second;

                if(contains(c.author,temp)){
                    displayBook(it->first);
                    counter++;
                }
            }
            cout<<endl<<counter<<" results found."<<endl;

        }
        void displayByTitle(){
            cin.ignore();
            counter=0;
            cout<<endl<<"Enter Title: ";
            getline(cin,temp);
            displayBooksTitles();
            for(map<int,book>::iterator it=database.begin(); it!=database.end(); ++it){
                book c = it->second;
                if(contains(c.title,temp)){
                    displayBook(it->first);
                    counter++;
                }
            }
            cout<<endl<<counter<<" results found."<<endl;

        }
        void displayByPublisher(){
            cin.ignore();
            counter=0;
            cout<<endl<<"Enter Publication: ";
            getline(cin,temp);
            displayBooksTitles();
            for(map<int,book>::iterator it=database.begin(); it!=database.end(); ++it){
                book c = it->second;
                if(contains(c.publisher,temp)){
                    displayBook(it->first);
                    counter++;
                }
            }
            cout<<endl<<counter<<" results found."<<endl;

        }
        void displayBySeries(){
            cin.ignore();
            counter=0;
            cout<<endl<<"Enter Title: ";
            getline(cin,temp);
            displayBooksTitles();
            for(map<int,book>::iterator it=database.begin(); it!=database.end(); ++it){
                book c = it->second;
                if(contains(c.series,temp)){
                    displayBook(it->first);
                    counter++;
                }
            }
            cout<<endl<<counter<<" results found."<<endl;

        }
        int checkBookValidity(int bookno){
            int flag=0;
            for(map<int,book>::iterator it=database.begin(); it!=database.end(); ++it){
              if(it->first==bookno){
                flag=1;
                break;
              }
            }
            return flag;
        }
        int bookAvalability(int bookno){
          if(database[bookno].stock>0)
            return 1;
          else
            return 0;
        }

};



class members: public books{
    public:
    member m;
    map<int,member> memberlist;
    string tem;
    string cel;
    int mindex;
    int mcounter;
public:
    members(){
        memberlist= map<int,member>();
            int temp2;
            mindex =0;
            mcounter=0;
            ifstream in("Data/members.csv");
            getline(in,tem);
            while(getline(in,tem)){
                stringstream  lineStream(tem);
                getline(lineStream,cel,',');
                stringstream data1(cel);
                data1>>m.ID;
                getline(lineStream,m.name,',');
                getline(lineStream,cel,',');
                stringstream data2(cel);
                data2>>m.book[0];
                getline(lineStream,cel,',');
                m.date[0].setdate(cel);
                getline(lineStream,cel,',');
                stringstream data3(cel);
                data3>>m.book[1];
                getline(lineStream,cel,',');
                m.date[1].setdate(cel);
                getline(lineStream, cel,',');
                stringstream data4(cel);
                data4>>m.book[2];
                getline(lineStream,cel,',');
                m.date[2].setdate(cel);
                getline(lineStream, cel,',');
                stringstream data5(cel);
                data5>>m.fine;
                getline(lineStream, cel,',');
                stringstream data6(cel);
                data6>>m.reissue;
                memberlist[m.ID]=m;
                mindex++; mcounter++;


            }

    }
    ~members(){
        ofstream fr("Data/members.csv");
        fr<<"Member no.,Member Name,Book1,DueDate1,Book2,DueDate2,Book3,DueDate3,Fine,ReIssueSlots"<<endl;
        for(map<int,member>::iterator it=memberlist.begin(); it!=memberlist.end(); ++it){
            member c= it->second;
            fr<<it->first<<","<<c.name<<","<<c.book[0]<<","<<c.date[0].displayDate()<<","<<c.book[1]<<","<<c.date[1].displayDate()<<","<<c.book[2]<<","<<c.date[2].displayDate()<<","<<c.fine<<","<<c.reissue <<endl;
        }
    }
    void addMember(){
      cout<<endl;
      cin.ignore();
      member m;
      cout<<magenta_text()<<"Enter Name: ";
      getline(cin,m.name);
      times t;
      t.setdate("none");
      for(int l =0; l<3;l++){
        m.book[l]=0;
        m.date[l]=t;
      }
      m.fine=0;
      m.reissue=5;
      m.ID=101+mindex;
      memberlist[101+mindex]=m;
      cout<<green_text()<<"\nMember has been succesfully assigned ID : "<<red_text()<<101+mindex<<endl;
      displayMemberTitles();
      displayMember(101+mindex);
      mindex++;
    }
    void displayMembers(){
        displayMemberTitles();
        for(map<int,member>::iterator it=memberlist.begin(); it!=memberlist.end(); ++it){
                    displayMember(it->first);
        }

    }
    void displayMemberTitles(){
      cout<<white_text();
      cout<<endl<<right<<setw(membernosize)<<"Member No."<<spaceconst<<left<<setw(namesize)<<"Name"<<right<<setw(booksize)<<"Book1"<<setw(datesize)<<"Due Date"<<setw(booksize)<<"Book2"<<setw(datesize)<<"Due Date"<<setw(booksize)<<"Book3"<<setw(datesize)<<"Due Date"<<setw(finesize)<<"Fine"<<setw(datesize)<<"ReissueSlots";
      cout<<endl;
      for(int i=0;i<(membernosize+namesize+3*booksize+4*datesize+finesize+spaceconst.length());i++)
              cout<<"-";

    }
    int checkMemberValidity(int memberno){
      int flag=0;
      for(map<int,member>::iterator it=memberlist.begin(); it!=memberlist.end(); ++it){
        if(it->first==memberno){
          flag=1;
          break;
        }
      }
      return flag;
    }
    void displayMember(){
        int memberno;
        cout<<blue_text();
        cout<<"\nEnter Member no: ";
        cin>>memberno;
        if(!checkMemberValidity(memberno)){
          cout<<endl<<red_text()<<"Invalid Memberno.\n"<<white_text();
          return;
        }
        displayMemberTitles();
        displayMember(memberno);
    }
    void displayMember(int memberno){
        cout<<black_text();
        member o=memberlist[memberno];
        cout<<endl<<right<<setw(membernosize)<<memberno<<spaceconst<<left<<setw(namesize)<<o.name<<right<<setw(booksize)<<o.book[0]<<setw(datesize)<<o.date[0].displayDate()<<setw(booksize)<<o.book[1]<<setw(datesize)<<o.date[1].displayDate()<<setw(booksize)<<o.book[2]<<setw(datesize)<<o.date[2].displayDate()<<setw(finesize)<<o.fine<<setw(datesize)<<o.reissue;
        cout<<white_text();
    }


};

class library : public members{
public:
    int emptySlot(int memberno){
        int slotindex=-1;
        for(int l=2;l>=0;l--){
            if(memberlist[memberno].book[l]==0)
              slotindex=l;

        }
        return slotindex;
    }

    void issueBook(int memberno,int bookno){
        int slotindex=emptySlot(memberno);
        if(slotindex==-1){
            cout<<red_text()<<"\nNo Empty Slot Avaliable. Please return previous books first\n"<<white_text();
                    return;
            }
        database[bookno].stock=database[bookno].stock-1;
        memberlist[memberno].book[slotindex]=bookno;
        times d;
        d.addDays(15);
        memberlist[memberno].date[slotindex]=d;
        cout<<green_text()<<"\nBook has been isued. Return date is: "<<red_text()<<d.displayDate()<<white_text();
    }

    void issue(){
        int memberno,bookno;
        cout<<magenta_text()<<"\nEnter Member no: ";
        cin>>memberno;
        if(!checkMemberValidity(memberno)){
          cout<<endl<<red_text()<<"Invalid Member No.\n"<<white_text();
          return;
        }
        cout<<magenta_text()<<"\nEnter Book No.: ";
        cin>>bookno;
        if(!checkBookValidity(bookno)){
          cout<<endl<<red_text()<<"Invalid Book No.\n"<<white_text();
          return;
        }
        if(!bookAvalability(bookno)){
            cout<<endl<<red_text()<<"\nBook out of stock.\n";
            return;
        }
        issueBook(memberno,bookno);
    }
    int checkIssuedBookValidity(int memberno,int bookno){
      int flag=-1;
      for(int u=0;u<3;u++){
          if(memberlist[memberno].book[u]==bookno){
              flag=u;
              break;
          }
      }
      return flag+1;
    }
    void returnBook(int slot,int memberno,int bookno){
        //cout<<flag;
        memberlist[memberno].book[slot]=0;
        database[bookno].stock=database[bookno].stock+1;
        times duedate =memberlist[memberno].date[slot];
        memberlist[memberno].date[slot].setdate("none");
        times today;
        memberlist[memberno].fine+= duedate.getFine(today);
        memberlist[memberno].reissue=5;
        cout<<green_text()<<"\nBook has been Returned. Your fine is :"<<red_text()<<memberlist[memberno].fine<<white_text();
        //memberlist[memberno]=t;

    }
     void returnB(){
        int memberno,bookno;
        cout<<magenta_text()<<"\nEnter Member no: ";
        cin>>memberno;
        if(!checkMemberValidity(memberno)){
          cout<<endl<<red_text()<<"Invalid Member No.\n"<<white_text();
          return;
        }
        displayMemberTitles();
        displayMember(memberno);
        cout<<magenta_text()<<"\nEnter Book No.: ";
        cin>>bookno;
        int slot=checkIssuedBookValidity(memberno,bookno);
        if(!slot){
          cout<<endl<<red_text()<<"Invalid Book No.\n"<<white_text();
          return;
        }
        returnBook(slot-1,memberno,bookno);
        //displayMemberTitles();
        //displayMember(memberno);
    }
    void reissueBook(int slot, int memberno, int bookno){
      if(memberlist[memberno].reissue < 1){
        cout<<red_text()<<"\nBook cannot be reissued as you have reissued more than 5 times without returning a book."<<white_text();
        return;
      }
      memberlist[memberno].reissue-=1;
      times duedate = memberlist[memberno].date[slot];
      times today;
      memberlist[memberno].fine+=duedate.getFine(today);
      today.addDays(15);
      memberlist[memberno].date[slot]=today;
      cout<<green_text()<<"\nBook has been Reissued. Your fine is :"<<red_text()<<memberlist[memberno].fine<<white_text();
      cout<<green_text()<<"\nReturn date is: "<<memberlist[memberno].date[slot].displayDate()<<white_text();

    }
    void reIssueB(){
       int memberno,bookno;
       cout<<magenta_text()<<"\nEnter Member no: ";
       cin>>memberno;
       if(!checkMemberValidity(memberno)){
         cout<<endl<<red_text()<<"Invalid Member No.\n"<<white_text();
         return;
       }
       displayMemberTitles();
       displayMember(memberno);
       cout<<magenta_text()<<"\nEnter Book No.: ";
       cin>>bookno;
       int slot=checkIssuedBookValidity(memberno,bookno);
       if(!slot){
         cout<<endl<<red_text()<<"Invalid Book No.\n"<<white_text();
         return;
       }
       reissueBook(slot-1,memberno,bookno);
       //displayMemberTitles();
       //displayMember(memberno);
    }
    void payFine(){
      int memberno;
      cout<<magenta_text()<<"\nEnter Member no: ";
      cin>>memberno;
      if(!checkMemberValidity(memberno)){
        cout<<endl<<red_text()<<"Invalid Member No.\n"<<white_text();
        return;
      }
      if(memberlist[memberno].fine==0){
        cout<<endl<<green_text()<<"No fine due.\n"<<white_text();
        return;
      }
      cout<<green_text()<<"\nYour fine is: "<<red_text()<<memberlist[memberno].fine<<endl;
      cout<<green_text()<<"Do you want to pay? (Y/N)";
      cin.ignore();
      char a;
      cin>>a;
      if(!(a=='Y'||a=='y')){
        return;
      }
      times today;
      string ls=printFee(memberno,memberlist[memberno].name,today.displayDate(),memberlist[memberno].fine);
      cout<<green_text()<<"\nPayment Succesful. Fine Recipt saved at: "<<red_text()<<ls<<white_text();
      memberlist[memberno].fine=0;
    }

};

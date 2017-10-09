#include "includes.cpp"
bool contains(string a, string b){

    char *c= new char[50];
    char *d= new char[50];
    strcpy(c,a.c_str());
    strcpy(d,b.c_str());

    for(int k=0;k<a.size();k++){
        d[k]=tolower(d[k]);
        c[k]=tolower(c[k]);

    }
    if(strstr(c,d)==NULL)
        return false;
    else
        return true;

}
string getpass(){
  const char BACKSPACE=8;
  const char RETURN=13;

  string password;
  unsigned char ch=0;

  while((ch=_getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

string printFee(int memberno, string name, string date, int fine){
    string loc="FineRecipts/";
    stringstream location;
    location<<loc<<date;
    location<<"-"<<memberno;
    location<<"-"<<name;
    location<<".txt";
    string ls;
    location>>ls;
    //cout<<endl<<ls;
    ofstream fr;
    fr.open(ls.c_str());
    fr<<"            ALEXIS LIBRARY            "<<endl;
    fr<<"--------------------------------------"<<endl;
    fr<<"             Fee Recipt               "<<endl;
    fr<<"--------------------------------------"<<endl;
    fr<<"  Name: "<<name<<endl;
    fr<<"  Member No: "<<memberno<<endl;
    fr<<"  Fine Amount: "<<fine<<endl;
    fr<<"  Paid On: "<<date<<endl;
    fr.close();
    return ls;

}
/*
int main(){
  printFee(101,"Nihar","22-12-1996",20);
}
*/

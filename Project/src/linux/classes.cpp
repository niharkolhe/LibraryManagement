#include "includes.cpp"
class book{
    public:
  int ID;
  string title;
  string series;
  string author;
  string publisher;
  int stock;
  int price;

};

class times{
public:
    int day;
    int month;
    int year;
    times(){
        clock_t start = clock();
        tm* my_time;
        time_t t = time(NULL);
        my_time = localtime(&t);
        day=my_time->tm_mday;
        month=(my_time->tm_mon)+1;
        year=(my_time->tm_year)+1900;
    }
    string displayDate(){
        if(day==0||month==0||year==0){
            return "none";
        }
        stringstream ss;
        ss<<day<<"-"<<month<<"-"<<year;
        string str;
        ss>>str;

        return str;
    }
    void setdate(string date){
        if(date.compare("none")==0){
            day=0;
            month=0;
            year=0;
            return;

        }
        string cel;
        stringstream  lineStream(date);
        getline(lineStream,cel,'-');
        stringstream data1(cel);
        data1>>day;
        getline(lineStream,cel,'-');
        stringstream data2(cel);
        data2>>month;
        getline(lineStream,cel,'-');
        stringstream data3(cel);
        data3>>year;
    }

    bool leapyear(){
        if (year % 4 == 0){
            if (year % 100 == 0){
                if (year % 400 == 0)
                    return true;
                else
                    return false;
            }
        else
            return true;
        }
        else
            return false;
    }
    bool leapyear(int year1){
        if (year1 % 4 == 0){
            if (year1 % 100 == 0){
                if (year1 % 400 == 0)
                    return true;
                else
                    return false;
            }
        else
            return true;
        }
        else
            return false;
    }
    void  addDays(int j){
        day=day+j;
        if((month==1||month==3||month==5||month==7||month==8||month==10)&&day>31){
            day=day%31;
            month++;
        }
        if((month==4||month==6||month==9||month==11)&&day>30){
            day=day%30;
            month++;
        }
        if(month==2&&day>28){
            if(leapyear()&&day>29){
                day=day%29;
                month++;
            }
            if(day>28){
                day=day%28;
                month++;
            }

        }
        if(month==12 && day>31 ){
            day=day%31;
            month=1;
            year++;
        }
    }
    int getFine(times today){

        int year1[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
        int nodays=0;
        int i=0,x1=0,x2=0,flag;
        if(leapyear())
            flag=1;
        else
            flag=0;
        while(i<month-1){
            x1+=year1[flag][i];
            i++;
        }
        x1+=day;
        if(leapyear(today.year))
            flag=1;
        else
            flag=0;
        i=0;
        while(i<today.month-1){
            x2+=year1[flag][i];
            i++;
        }
        x2+=today.day;
        if(year>today.year)
            return 0;
        if(year==today.year){
            if(x2>x1)
                return x2-x1;
            else
                return 0;
        }
        if(year<today.year){
            if(today.year-year==1){
                if(leapyear(year))
                    return x2+(366-x1);
                else
                    return x2+(365-x1);
            }
            else{
                int then=year;
                nodays=0;
                while(then<today.year-1){
                    if(leapyear(then))
                        nodays+=366;
                    else
                        nodays+=365;
                    then++;
                }
                if(leapyear(then))
                    nodays+= x2+(366-x1);
                else
                    nodays+= x2+(365-x1);
                return nodays;
            }
        }

    }

};

class member{
public:
    int ID;
    string name;
    int book[3];
    times date[3];
    int fine;
    int reissue;

};
/*
int main(){
    times l,m;
    l.setdate("20-8-2013");
    cout<<l.getFine(m);
}
*/

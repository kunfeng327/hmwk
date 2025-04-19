#include <iostream>
#include <cstring>
using namespace std;
class Date    //日期类
{
private:
    int Date_year;    //年
    int Date_month;    //月
    int Date_day;    //日
public:
    Date(int year=2000, int month=1, int day=1);
    void show() const;    //以“年-月-日”格式输出年月日
};
Date::Date(int year, int month, int day)    //构造函数
{
    Date_year = year;
    Date_month = month;
    Date_day = day;
}
void Date::show() const    //显示年月日
{
    cout <<"Birthday: "<< Date_year << "-" << Date_month << "-" << Date_day;
}

class Croster    //名单类
{
private:
    string name;
    Date birthday;
public:
    Croster();
    Croster(string name,int year,int month,int day);
    Croster(string name, Date date);
    void show() const;//显示姓名和出生日期
};
Croster::Croster()    //默认构造函数
{
    name = "NULL";
    birthday = Date(0,0,0);
}
Croster::Croster(string name,int year,int month,int day)    //构造函数
{
    this->name = name;
    birthday = Date(year,month,day);
}
Croster::Croster(string name, Date date)    //构造函数
{
    this->name = name;
    birthday = date;
}
void Croster::show() const    //显示姓名和出生日期
{
    cout <<"Name: "<< name << ", ";
    birthday.show();
    cout << endl;
}
int main(){
    int choice;
    while (true) {
        cin >> choice;
        if (choice == -1) {
            break;
        } else if (choice == 0) {
            Croster c;
            c.show();
        } else if (choice == 1) {
            string n;
            int y, m, d;
            cin >> n >> y >> m >> d;
            Croster c(n, y, m, d);
            c.show();
        } else if (choice == 2) {
            string n;
            int y, m, d;
            cin >> n >> y >> m >> d;
            Date dObj(y, m, d);
            Croster c(n, dObj);
            c.show();
        }
    }
    return 0;
}
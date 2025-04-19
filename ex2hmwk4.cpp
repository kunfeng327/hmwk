#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Date
{
public:
   Date(int d = 0, int m = 0, int y = 0); //构造函数
   int get_day() const; // 返回day
   int get_month() const; //返回month
   int get_year() const; // 返回year
   static void set_default(int, int, int); //设置default_date
   static int get_default_day(); //返回缺省day
   static int get_default_month(); //返回缺省month
   static int get_default_year(); //返回缺省year
   Date & add_year(int n); //加n年
   Date & add_month(int n); //加n月，考虑超过12月
   Date & add_day(int n); //加n天，考虑进位月和年，考虑闰年
private:
   int day, month, year;
   static Date default_date; //初始化为 1901年1月1日
};
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {} //构造函数
int Date::get_day() const { return day; } //返回day
int Date::get_month() const { return month; } //返回month
int Date::get_year() const { return year; } //返回year
void Date::set_default(int d, int m, int y) //设置default_date
{
   default_date.day = d;
   default_date.month = m;
   default_date.year = y;
}
int Date::get_default_day() //返回缺省day
{
   return default_date.day;
}
int Date::get_default_month() //返回缺省month
{
   return default_date.month;
}
int Date::get_default_year() //返回缺省year
{
   return default_date.year;
}
Date Date::default_date(1, 1, 1901); //初始化为 1901年1月1日

Date & Date::add_year(int n) //加n年
{
   year += n;
   return *this;
}
Date & Date::add_month(int n) //加n月，考虑超过12月
{
    month += n;
    if (month > 12)
    {
        year += (month - 1) / 12; // 减去 1，确保月份从 1 开始
        month = (month - 1) % 12 + 1; // 确保月份从 1 到 12
    }
    return *this;
}
Date & Date::add_day(int n) // 加n天，考虑进位月和年，考虑闰年
{
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 判断当前年份是否为闰年
    auto is_leap_year = [](int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    };

    if (is_leap_year(year))
        days_in_month[2] = 29; // 当前年份是闰年

    day += n;

    // 处理天数进位
    while (day > days_in_month[month])
    {
        day -= days_in_month[month];
        month++;

        // 处理月份进位
        if (month > 12)
        {
            month = 1;
            year++;

            // 更新闰年状态
            if (is_leap_year(year))
                days_in_month[2] = 29;
            else
                days_in_month[2] = 28;
        }
    }

    return *this;
}
//主函数
int main()
{
   char type[110];
   int day,mon,year;
   int addday,addmon,addyear;
   while(cin>>type)
   {
      if(strcmp(type,"Date") == 0)
      {
         cin>>day>>mon>>year;
         Date mydate(day,mon,year);
         cin>>addday>>addmon>>addyear;
         mydate.add_day(addday).add_month(addmon).add_year(addyear);
         cout << mydate.get_day() << " " << mydate.get_month() << " " << mydate.get_year() << endl;
      }
      else if(strcmp(type,"defaultDate") == 0) 
      {
          cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;
      }
      else if(strcmp(type,"setdefaultDate") == 0)
      {
         cin>>day>>mon>>year;
         Date::set_default(day,mon,year);
         cout << Date::get_default_day() << " " << Date::get_default_month() << " " << Date::get_default_year() << endl;
      }
   }
   return 0;
}
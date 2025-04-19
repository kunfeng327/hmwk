#include<iostream>
using namespace std;
#include<cstring>
class String
{
private:
char * s;
public:
String();
String(const char *);
String(const String &);
~String();
String & operator=(const char *);
String & operator=(const String &);
String operator+(const char *);
String operator+(const String &);
String & operator+=(const char *);
String & operator+=(const String &);
friend istream & operator>>(istream &, String &);
friend ostream & operator<<(ostream &, const String &);
friend bool operator==(const String &, const char *);
friend bool operator==(const String &, const String &);
friend bool operator!=(const String &, const char *);
friend bool operator!=(const String &, const String &);
};

String::String(){
    s = new char[1];
    s[0] = '\0';
}
String::String(const char * str){
    s = new char[strlen(str) + 1];
    strcpy(s, str);
}
String::String(const String & str){
    s = new char[strlen(str.s) + 1];
    strcpy(s, str.s);
}
String::~String(){
    delete[] s;
}
String & String::operator=(const char * str){
    if (s != str) {
        delete[] s;
        s = new char[strlen(str) + 1];
        strcpy(s, str);
    }
    return *this;
}
String & String::operator=(const String & str){
    if (this != &str) {
        delete[] s;
        s = new char[strlen(str.s) + 1];
        strcpy(s, str.s);
    }
    return *this;
}
String String::operator+(const char * str){
    String temp;
    temp.s = new char[strlen(s) + strlen(str) + 1];
    strcpy(temp.s, s);
    strcat(temp.s, str);
    return temp;
}
String String::operator+(const String & str){
    String temp;
    temp.s = new char[strlen(s) + strlen(str.s) + 1];
    strcpy(temp.s, s);
    strcat(temp.s, str.s);
    return temp;
}
String & String::operator+=(const char * str){
    char * temp = new char[strlen(s) + strlen(str) + 1];
    strcpy(temp, s);
    strcat(temp, str);
    delete[] s;
    s = temp;
    return *this;
}
String & String::operator+=(const String & str){
    char * temp = new char[strlen(s) + strlen(str.s) + 1];
    strcpy(temp, s);
    strcat(temp, str.s);
    delete[] s;
    s = temp;
    return *this;
}
istream & operator>>(istream & is, String & str){
    char buffer[100];
    is >> buffer;
    str = buffer;
    return is;
}
ostream & operator<<(ostream & os, const String & str){
    os << str.s;
    return os;
}
bool operator==(const String & str, const char * s){
    return strcmp(str.s, s) == 0;
}
bool operator==(const String & str1, const String & str2){
    return strcmp(str1.s, str2.s) == 0;
}
bool operator!=(const String & str, const char * s){
    return strcmp(str.s, s) != 0;
}
bool operator!=(const String & str1, const String & str2){
    return strcmp(str1.s, str2.s) != 0;
}

// 使用以下main函数进行测试：

int main()
{
String s;
s += "hello";
cout<<s<<endl;
String s1("String1");
String s2("copy of ");
s2 += "String1";
cout << s1 << "\n" << s2 << endl;
String s3;
cin >> s3;
cout << s3 << endl;
String s4("String4"), s5(s4);
cout << (s5 == s4) << endl;
cout << (s5 != s4) << endl;
String s6("End of "), s7("my string.");
s6 += s7;
cout << s6 << endl;
return 0;
}
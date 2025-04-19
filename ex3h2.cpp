#include<iostream>
using namespace std;
class Person
{
    private:
        char name[20];
    public:
        virtual void input();
        virtual void display();
};
class Student:public Person{
    private:
        char name[20];
        string id;
    public:
        void input();
        void display();
};
void Person::input()
{
    cin >> name;
}
void Person::display()
{
    cout << name << endl;
}
void Student::input()
{
    cin >> id >> name;
}
void Student::display()
{
    cout << id << " " << name << endl;
}
int main()

{

    Person * p;

    p = new Person;

    p->input();

    p->display();

    delete p;

    p = new Student;

    p->input();

    p->display();

    delete p;

    return 0;
}
// Mary
// 001 Mary
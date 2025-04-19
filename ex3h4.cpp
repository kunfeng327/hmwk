#include<iostream>
using namespace std;
#include<string.h>

class Vehicle

{

    protected:
        string name;
        string color;

    public:
        Vehicle(char *n,char *c){
            name = n;
            color = c;
        }

        virtual void display() = 0;

};
class Car: public Vehicle
{
    private:
        int passengers;

    public:
        Car(char *n,char *c,int p):Vehicle(n,c){
            passengers = p;
        }

        void display(){
            cout<<"Car name:"<<name<<" Car color:"<<color<<" Car passenger:"<<passengers<<endl;
        }

};
class Truck: public Vehicle
{
    private:
        double capacity;

    public:
        Truck(char *n,char *c,double cap):Vehicle(n,c){
            capacity = cap;
        }

        void display(){
            cout<<"Truck name:"<<name<<" Truck color:"<<color<<" Truck capacity:"<<capacity<<endl;
        }
};
int main()

{

Vehicle *p;

char type;

char name[110],color[110];

int pas;

double cap;

while(cin>>type)

{

cin>>name>>color;

if(type == 'C')

{

cin>>pas;

Car car(name,color,pas);

p = &car;

p->display();

}

else if(type == 'T')

{

cin>>cap;

Truck truck(name,color,cap);

p = &truck;

p->display();

}

}

return 0;

}
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Circle
{
private:
    double r;
public:
    void input();
    double area();
    void output();
};
void Circle::input()
{
    // cout << "Enter the radius: ";
    cin >> r;
}
double Circle::area() {
    const double PI = acos(-1.0);
    return PI * r * r;
}
void Circle::output() {
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<area() << endl;
}
int main() {
    Circle c;
    c.input();
    c.output();
    return 0;
}
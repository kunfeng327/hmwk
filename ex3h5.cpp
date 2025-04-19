#include<iostream>
#include<cmath>
const double pi=acos(-1.0);
using namespace std;

class Shape {

    public:
    
    Shape() {}
    
    virtual double area() = 0;
    
    virtual void input() = 0;
    
    virtual double volume() = 0;
    
    virtual ~Shape() {}
    
};
class Cylinder : public Shape {

    double r, h;
    
    public:
    
    Cylinder() {}
    
    void input() {
    
        cin >> r >> h;
    
    }
    
    double area() {
    
        return 2 * pi* r * (r + h);
    
    }
    double volume() {
    
        return pi* r * r * h;
    
    }
    
};
class Cuboid : public Shape {
    private:

    double l, w, h;
    
    public:
    
    Cuboid() {}
    
    void input() {
    
        cin >> l >> w >> h;
    
    }
    
    double area() {
    
        return 2 * (l * w + w * h + h * l);
    
    }
    
    double volume() {
    
        return l * w * h;
    
    }
    
};
class Ball : public Shape {
    private:

    double r;
    
    public:
    
    Ball() {}
    
    void input() {
    
        cin >> r;
    
    }
    
    double area() {
    
        return 4 * pi * r * r;
    
    }
    
    double volume() {
    
        return (4.0 / 3.0) * pi * r * r * r;
    
    }
    
};
void work(Shape *s) {

    s->input();
    
    cout << s->area() << " " << s->volume() << endl;
    
    delete s;
    
    }
    
int main() {
    
    char c;
    
    while (cin >> c) {
    
    switch (c) {
    
    case 'y':
    
    work(new Cylinder());
    
    break;
    
    case 'c':
    
    work(new Cuboid());
    
    break;
    
    case 'q':
    
    work(new Ball());
    
    break;
    
    default:
    
    break;
    
    }
    
    }
    
    return 0;
    
    }
    
    
    
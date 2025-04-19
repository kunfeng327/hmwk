#include<iostream>
using namespace std;
class Rectangle

{

private:

  double length; //长

  double width; //宽

public:

  Rectangle(double Length=10.,double Width=5.);

  double Area() const; //获取面积

  double Perimeter() const;//获取周长

};
Rectangle::Rectangle(double Length,double Width){
    length=Length;
    width=Width;
}
double Rectangle::Area() const{
    double s=length*width;
    return s;
}
double Rectangle::Perimeter() const{
    double c=((length+3)+(width+3))*2;
    return c;
}
int main(){
    double l,w;
    cin>>l>>w;
    Rectangle rect1(l,w);
    Rectangle rect2(l+3,w+3);
    cout<<rect1.Perimeter()*50<<endl<<(rect2.Area()-rect1.Area())*240;
}
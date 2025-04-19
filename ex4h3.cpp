#include<iostream>
using namespace std;
class Complex

{

private:

double x;

double y;

public:

Complex(double x = 0.0, double y = 0.0);

Complex & operator+=(const Complex &);

Complex & operator-=(const Complex &);

Complex & operator*=(const Complex &);

Complex & operator/=(const Complex &);

friend Complex operator+(const Complex &, const Complex &);

friend Complex operator-(const Complex &, const Complex &);

friend Complex operator*(const Complex &, const Complex &);

friend Complex operator/(const Complex &, const Complex &);

friend bool operator==(const Complex &, const Complex &);

friend bool operator!=(const Complex &, const Complex &);

friend ostream & operator<<(ostream &, const Complex &);

friend istream & operator>>(istream &, Complex &);

};
ostream & operator<<(ostream & os, const Complex & c)
{
os << c.x <<" + "<< c.y << "i";
return os;
}
istream & operator>>(istream & is, Complex & c)
{
is >> c.x >> c.y;
return is;
}
Complex::Complex(double x, double y) : x(x), y(y) {}
Complex & Complex::operator+=(const Complex & c){
x += c.x;
y += c.y;
return *this;
}
Complex & Complex::operator-=(const Complex & c){
x -= c.x;
y -= c.y;
return *this;
}
Complex & Complex::operator*=(const Complex & c){
double temp_x = x * c.x - y * c.y;
double temp_y = x * c.y + y * c.x;
x = temp_x;
y = temp_y;
return *this;
}
Complex & Complex::operator/=(const Complex & c){
    double temp_x = (x * c.x + y * c.y) / (c.x * c.x + c.y * c.y);
    double temp_y = (y * c.x - x * c.y) / (c.x * c.x + c.y * c.y);
    x = temp_x;
    y = temp_y;
    return *this;
}
Complex operator+(const Complex & c1, const Complex & c2){
    return Complex(c1.x + c2.x, c1.y + c2.y);
}
Complex operator-(const Complex & c1, const Complex & c2){
    return Complex(c1.x - c2.x, c1.y - c2.y);
}
Complex operator*(const Complex & c1, const Complex & c2){
    return Complex(c1.x * c2.x - c1.y * c2.y, c1.x * c2.y + c1.y * c2.x);
}
Complex operator/(const Complex & c1, const Complex & c2){
    double temp_x = (c1.x * c2.x + c1.y * c2.y) / (c2.x * c2.x + c2.y * c2.y);
    double temp_y = (c1.y * c2.x - c1.x * c2.y) / (c2.x * c2.x + c2.y * c2.y);
    return Complex(temp_x, temp_y);
}
bool operator==(const Complex & c1, const Complex & c2){
    return (c1.x == c2.x && c1.y == c2.y);
}
bool operator!=(const Complex & c1, const Complex & c2){
    return !(c1 == c2);
}
// 通过以下主函数测试：

int main()

{

Complex c1, c2;

cin >> c1 >> c2;

cout << "c1 = " << c1 << "\n" << "c2 = " << c2 << endl;

cout << "c1+c2 = " << c1 + c2 << endl;

cout << "c1-c2 = " << c1 - c2 << endl;

cout << "c1*c2 = " << c1 * c2 << endl;

cout << "c1/c2 = " << c1 / c2 << endl;

cout << (c1 += c2) << endl;

cout << (c1 -= c2) << endl;

cout << (c1 *= c2) << endl;

cout << (c1 /= c2) << endl;

cout << (c1 == c2) << " " << (c1 != c2) << endl;

return 0;

}
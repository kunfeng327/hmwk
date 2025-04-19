#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Point2
{
private:
    double x, y;
public:
    Point2(double x, double y) : x(x), y(y) {}
    double GetX() { return x; }
    double GetY() { return y; }
};
class Line2
{
private:
    Point2 p1, p2;
public:
    Line2(Point2 p1, Point2 p2) : p1(p1), p2(p2) {}
    double Length()
    {
        double dx = p2.GetX() - p1.GetX();
        double dy = p2.GetY() - p1.GetY();
        return sqrt(dx * dx + dy * dy);
    }
};
int main()
{
    Point2 pt1(1.0, 1.0);
    Point2 pt2(3.0, 4.0);
    Line2 line(pt1, pt2);
    std::cout << line.Length() << std::endl;

    double x1,y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Line2 nLine(Point2(x1, y1), Point2(x2, y2));
    std::cout << nLine.Length()<< std::endl;

    return 0;
}
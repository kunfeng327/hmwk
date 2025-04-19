#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
class Vector
{
    private:
        T x, y, z;
    public:
        Vector();
        Vector(T a, T b, T c);
        Vector(const Vector<T>& v);
        Vector<T>& operator=(const Vector<T>& v);
        Vector<T> operator+(const Vector<T>& v) const;
        bool operator==(const Vector<T>& v) const;
        T getX() const;
        T getY() const;
        T getZ() const;
};

// 默认构造函数
template<typename T>
Vector<T>::Vector() : x(0), y(0), z(0) {}

// 带参数构造函数
template<typename T>
Vector<T>::Vector(T a, T b, T c) : x(a), y(b), z(c) {}

// 拷贝构造函数
template<typename T>
Vector<T>::Vector(const Vector<T>& v) : x(v.x), y(v.y), z(v.z) {}

// 赋值运算符
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    if (this != &v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    return *this;
}

// 加法运算符
template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& v) const
{
    return Vector<T>(x + v.x, y + v.y, z + v.z);
}

// 相等运算符
template<typename T>
bool Vector<T>::operator==(const Vector<T>& v) const
{
    const double epsilon = 1e-9; // 定义误差范围
    return (std::abs(x - v.x) < epsilon &&
            std::abs(y - v.y) < epsilon &&
            std::abs(z - v.z) < epsilon);
}

// 获取 x 分量
template<typename T>
T Vector<T>::getX() const { return x; }

// 获取 y 分量
template<typename T>
T Vector<T>::getY() const { return y; }

// 获取 z 分量
template<typename T>
T Vector<T>::getZ() const { return z; }

// 全局运算符重载：double * Vector
template<typename T>
Vector<T> operator*(const double& d, const Vector<T>& v) {
    return Vector<T>(v.getX() * d, v.getY() * d, v.getZ() * d);
}

// 输入流运算符重载
istream& operator>>(istream& in, Vector<double>& v)
{
    double a, b, c;
    in >> a >> b >> c;
    v = Vector<double>(a, b, c);
    return in;
}

// 输出流运算符重载
ostream& operator<<(ostream& out, Vector<double>& v)
{
    out << v.getX() << " " << v.getY() << " " << v.getZ() ;
    return out;
}

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;
    Vector<double> v1(a, b, c), v2(v1), v3, v4;
    double d;
    std::cin >> d;
    v4 = d * v1 + v2;

    std::cout << v4 << std::endl;

    Vector<double> v;
    std::cin >> v;

    int flag = (v4 == v);
    std::cout << flag << std::endl;

    return 0;
}
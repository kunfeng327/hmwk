#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class VectorN
{
private:
    int dim;
    double *values;
public:

    VectorN(int d, double *v) : dim(d)
    {
        values = new double[dim];
        for (int i = 0; i < dim; i++)
            values[i] = v[i];
    }
    ~VectorN()
    {
        delete[] values;
    }
    double Mag()
    {
        double sum = 0;
        for (int i = 0; i < dim; i++)
            sum += values[i] * values[i];
        return sqrt(sum);
    }
};

int main()
{
    int num;
    std::cin >> num;
    double *dtemp = new double[num];
    for(int i=0; i<num; i++)
        std::cin >> dtemp[i];
    VectorN vn2(num, dtemp);
    delete[] dtemp;
    std::cout << vn2.Mag() << std::endl;
    return 0;
}
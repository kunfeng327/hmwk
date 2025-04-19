#include<iostream>
using namespace std;

template <typename T>
int Search(T*a,int n,T d){
    for (int i=0;i<n;i++){
        if (a[i]==d){
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    std::cin >> n;
    int *nValues  = new int[n];
    for (int i = 0; i < n; i++) 
    {
        std::cin >> nValues[i];
    }    
    int d;
    std::cin >> d;
    std::cout << Search(nValues, n, d) << std::endl;
    delete[] nValues;

    double f;
    std::cin >> n;
    double *dValues = new double[n];
    for (int i = 0; i < n; i++) 
    {
        std::cin >> dValues[i];
    }
    std::cin >> f;
    std::cout << Search(dValues, n, f) << std::endl;
    delete[] dValues;

    std::cin >> n;
    char *cValues = new char[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> cValues[i];
    }
    char c;
    std::cin >> c;
    std::cout << Search(cValues, n, c) << std::endl;
    delete[] cValues;

    return 0;
}

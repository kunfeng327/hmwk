#include <iostream>
#include <string>
using namespace std;
class Hotel
{
private:
    string name;
    int index;
    static int total;
public:
    Hotel()
    {
        name = "";
        
    }
    void add(string n)
    {
        name = n;
        total++;
        index = total;
    }
    string getName()
    {
        return name;
    }
    static int getTotal()
    {
        return total;
    }
    void print()
    {
        cout << index<<" "<< name <<" "<<total<< endl;
        
    }   
};
int Hotel::total = 0;
int main(){
    Hotel h[100];
    h[0].add("Susan");
    h[1].add("Peter");
    h[2].add("John");
    h[3].add("Mary");
    h[4].add("Alice");
    string name;
    cin>>name;

    for(int i=0;i<Hotel::getTotal();i++)
    {
        if(h[i].getName()==name)
        {
            h[i].print();
            break;
        }
    }

    return 0;
}
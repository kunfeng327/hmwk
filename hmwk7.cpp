#include <iostream>
#include <string>
using namespace std;
class TestConstClass {
    private:
        string str;
    public:
        TestConstClass() : str("") {}
        void set (const string & s) {
            str = s;
        }
        string get () const {
            return str;
        }
        
};
void print (const TestConstClass & tcs) {

    cout << tcs.get()<<'\n';
    
}    
int main() {

    string tmp;
    
    TestConstClass tcs;
    
    while(cin>>tmp){
    
        tcs.set(tmp);
        
        print(tcs);
    
    }
    
    return 0;
    
}
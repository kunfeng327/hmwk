#include<iostream>
using namespace std;
class CheckedPtr

{

public:

CheckedPtr(int * b, int * e) : beg(b), end(e), curr(b) {  }

CheckedPtr & operator ++(); // prefix ++

CheckedPtr & operator --(); // prefix --

CheckedPtr   operator ++(int); // postfix ++

CheckedPtr   operator --(int); // postfix --

int * GetBeg();

int * GetEnd();

int * GetCurr();

private:

int * beg;  // pointer to beginning of the array

int * end;  // one past the end of the array

int * curr; // current position within the array

};

CheckedPtr & CheckedPtr::operator ++(){
    if (curr < end) ++curr;
    return *this;
}
CheckedPtr & CheckedPtr::operator --(){
    if (curr > beg) --curr;
    return *this;
}
CheckedPtr CheckedPtr::operator ++(int){
    CheckedPtr temp = *this;
    if (curr < end) curr++;
    return temp;
}
CheckedPtr CheckedPtr::operator --(int){
    CheckedPtr temp = *this;
    if (curr > beg) curr--;
    return temp;
}
int * CheckedPtr::GetBeg(){
    return beg;
}
int * CheckedPtr::GetEnd(){
    return end;
}
int * CheckedPtr::GetCurr(){
    return curr;
}
// 下面是一个简单的测试程序，创建一个CheckedPtr对象并使用它来遍历一个整数数组。
// 实现CheckedPtr类并通过以下main函数测试。

int main(){

int n;

cin>>n;

int * array = new int[n];

for(int i=0;i<n;i++)

cin>>array[i];

CheckedPtr cp(array, array+n);

for(;cp.GetCurr()<cp.GetEnd();cp++)

cout<<*cp.GetCurr()<<" ";

cout<<endl;

for(--cp;cp.GetCurr()>cp.GetBeg();cp--)

cout<<*cp.GetCurr()<<" ";

cout<<*cp.GetCurr()<<endl;

delete [] array;

return 0;

}
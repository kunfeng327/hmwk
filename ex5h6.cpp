#include<iostream>
#include<cmath>
using namespace std;

template <typename T> class MyQueue;//前置声明
template <typename T> std::ostream & operator<<(std::ostream &, const MyQueue<T> &); 

template <typename T> 
class QueueItem
{
public:
    QueueItem(const T & t) :item(t), next(0)
    {} 
private:
    T item; //value stored in this element
    QueueItem *next; // pointer to next element in the MyQueue

    friend class MyQueue<T>;//友元类    
    //通过友元函数重载<<运算符模板函数，要写上<<后的<Type>
    friend ostream & operator<< <T> (ostream & os, const MyQueue<T> & q);
};

template <typename T> 
class MyQueue
{
public:
    MyQueue() : head(0), tail(0) {} // Empty MyQueue

    MyQueue(const MyQueue &Q) //拷贝构造函数
        :head(0), tail(0) 
    { CopyElements(Q); };

    ~MyQueue() { Destroy(); }

    MyQueue & operator=(const MyQueue &);

    // return element from head of MyQueue
    T & Front() { return head->item; }
    const T & Front() const { return head->item; }
    void Push(const T &); //add element to back of MyQueue
    void Pop(); // remove element from head of MyQueue
    bool Empty() const { return head == 0; }
    void Display() const;
private:
    QueueItem<T> *head;
    QueueItem<T> *tail;
    void Destroy(); //delete all the elements
    void CopyElements(const MyQueue &);

    //设置友元函数
    friend ostream & operator<< <T> (ostream & os, const MyQueue<T> & q);
};

// 实现这个类模板中的成员函数，然后使用如下所示的main()函数测试这一类模板。

int main()
{
    MyQueue<int> qi;
    qi.Push(1);
    qi.Push(2);
    qi.Push(3);
    qi.Push(4);
    qi.Push(5);
    qi.Pop();
    qi.Display();
    cout<<"\n";
    cout<<qi;
    cout<<endl;

    MyQueue<int> qi2(qi);
    qi2.Display();
    cout<<endl;

    MyQueue<int> qi3;
    qi3 = qi;
    cout<<qi3;

    return 0;
}
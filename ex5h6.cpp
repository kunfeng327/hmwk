#include<iostream>
#include<cmath>
using namespace std;

template <typename T> class MyQueue; // 前置声明
template <typename T> std::ostream & operator<<(std::ostream &, const MyQueue<T> &);

template <typename T>
class QueueItem {
public:
    QueueItem(const T & t) : item(t), next(0) {}
private:
    T item; // 存储的值
    QueueItem *next; // 指向下一个元素的指针

    friend class MyQueue<T>; // 友元类
    friend ostream & operator<< <T>(ostream & os, const MyQueue<T> & q); // 友元函数
};

template <typename T>
class MyQueue {
public:
    MyQueue() : head(0), tail(0) {} // 空队列

    MyQueue(const MyQueue &Q) // 拷贝构造函数
        : head(0), tail(0) 
    { 
        CopyElements(Q); 
    }

    ~MyQueue() { Destroy(); } // 析构函数

    MyQueue & operator=(const MyQueue &Q) { // 赋值运算符重载
        if (this != &Q) {
            Destroy();
            CopyElements(Q);
        }
        return *this;
    }

    T & Front() { return head->item; } // 返回队列头部元素
    const T & Front() const { return head->item; }
    void Push(const T &); // 添加元素到队列尾部
    void Pop(); // 从队列头部移除元素
    bool Empty() const { return head == 0; } // 判断队列是否为空
    void Display() const; // 显示队列中的所有元素

private:
    QueueItem<T> *head; // 队列头部指针
    QueueItem<T> *tail; // 队列尾部指针
    void Destroy(); // 删除所有元素
    void CopyElements(const MyQueue &); // 复制队列中的所有元素

    friend ostream & operator<< <T>(ostream & os, const MyQueue<T> & q); // 友元函数
};

// 添加元素到队列尾部
template <typename T>
void MyQueue<T>::Push(const T &val) {
    QueueItem<T> *newItem = new QueueItem<T>(val);
    if (tail) {
        tail->next = newItem;
    } else {
        head = newItem;
    }
    tail = newItem;
}

// 从队列头部移除元素
template <typename T>
void MyQueue<T>::Pop() {
    if (head) {
        QueueItem<T> *temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr; // 如果队列为空，更新尾部指针
        }
    }
}

// 显示队列中的所有元素
template <typename T>
void MyQueue<T>::Display() const {
    QueueItem<T> *current = head;
    while (current) {
        cout << current->item << " ";
        current = current->next;
    }
}

// 删除所有元素
template <typename T>
void MyQueue<T>::Destroy() {
    while (head) {
        Pop();
    }
}

// 复制队列中的所有元素
template <typename T>
void MyQueue<T>::CopyElements(const MyQueue &Q) {
    QueueItem<T> *current = Q.head;
    while (current) {
        Push(current->item);
        current = current->next;
    }
}

// 重载 << 运算符
template <typename T>
ostream & operator<<(ostream &os, const MyQueue<T> &q) {
    QueueItem<T> *current = q.head;
    os << "< ";
    while (current) {
        os << current->item << " ";
        current = current->next;
    }
    os << ">";
    return os;
}

// 测试代码
int main() {
    MyQueue<int> qi;
    qi.Push(1);
    qi.Push(2);
    qi.Push(3);
    qi.Push(4);
    qi.Push(5);
    qi.Pop();
    qi.Display();
    cout << "\n";
    cout << qi;
    cout << endl;

    MyQueue<int> qi2(qi);
    qi2.Display();
    cout << endl;

    MyQueue<int> qi3;
    qi3 = qi;
    cout << qi3;

    return 0;
}
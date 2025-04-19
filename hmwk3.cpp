#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char *name; //**书名
    char *author; //**作者
    int sale; //**销售量

public:
    Book(); //**无参构造函数
    Book(const char *, const char *, int); //**有参构造函数
    Book(const Book &); //**拷贝构造函数
    void print() const; //**显示数据
    ~Book(); //**析构函数
};

Book::Book() {
    name = new char[strlen("No name") + 1];
    strcpy(name, "No name");
    author = new char[strlen("No author") + 1];
    strcpy(author, "No author");
    sale = 0;
}

Book::Book(const char *n, const char *a, int s) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    author = new char[strlen(a) + 1];
    strcpy(author, a);
    sale = s;
}

Book::Book(const Book &b) {
    name = new char[strlen(b.name) + 1];
    strcpy(name, b.name);
    author = new char[strlen(b.author) + 1];
    strcpy(author, b.author);
    sale = b.sale;
}

void Book::print() const {
    cout << "Name: " << name << "\t" << "Author: " << author << "\t" << "Sale: " << sale << endl;
}

Book::~Book() {
    delete[] name;
    delete[] author;
}

int main() {
    char name[100], author[100];
    int sale;
    
    cin.getline(name, 100);
    cin.getline(author, 100);
    cin >> sale;
    cin.ignore(); 
    if(strcmp(name,"-1")==0&&strcmp(author,"-1")==0&&sale==-1){
        Book bk1;
        bk1.print();
    }
    else if(strcmp(name,"0")==0&&strcmp(author,"0")==0&&sale==0){
        Book bk1;
        Book bk2(bk1); 
        bk2.print();
    }
    else{
        Book bk1(name, author, sale);
        bk1.print();
    }
    return 0;
}
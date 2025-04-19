#include<iostream>
using namespace std;
class Sales_data {

    //依次输入书号、销量和收入
    
    friend istream & operator>>(istream&, Sales_data &);
    
    //依次输出书号、销量、收入和均价
    
    friend ostream & operator<<(ostream &, const Sales_data &);
    
    friend bool operator==(const Sales_data &, const Sales_data &);
    
    friend bool operator!=(const Sales_data &, const Sales_data &);
    
    // for "+", assume that both objects refer to the same book
    
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    
    public:
    
    Sales_data(): units_sold(0), revenue(0.0) {}
    
    Sales_data(const string & s, unsigned n, double r): bookNo(s), units_sold(n), revenue(r) {}
    
    string get_bookNo() const;
    
    // for "+=", assume that both objects refer to the same book
    
    Sales_data & operator+=(const Sales_data &);
    
    private:
    
    double avg_price() const;  //均价，等于收入除以销量
    
    string bookNo;        //书号
    
    unsigned units_sold; //销量
    
    double revenue;      //收入
    
    };
    istream & operator>>(istream & in, Sales_data & item) {
        // double price = 0.0;
        in >> item.bookNo >> item.units_sold >> item.revenue;
        
        return in;
    }
    ostream & operator<<(ostream & os, const Sales_data & item) {
        os<<item.bookNo<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
        return os;
    }
    bool operator==(const Sales_data & item1, const Sales_data & item2) {
        return item1.bookNo == item2.bookNo;
    }
    bool operator!=(const Sales_data & item1, const Sales_data & item2) {
        return !(item1 == item2);
    }
    Sales_data operator+(const Sales_data & item1, const Sales_data & item2) {
        Sales_data sum = item1; // copy data from item1
        sum += item2;          // add in the data from item2
        return sum;           // return the new object
    }
    Sales_data & Sales_data::operator+=(const Sales_data & item) {
        units_sold += item.units_sold; //累加销量
        revenue += item.revenue;       //累加收入
        return *this;                 //返回当前对象的引用
    }
    string Sales_data::get_bookNo() const {
        return bookNo; //返回书号
    }
    double Sales_data::avg_price() const {
        if (units_sold) //如果销量不为0
            return revenue / units_sold; //返回均价
        else
            return 0; //否则返回0
    }

    // 通过以下main函数的测试
    
    int main(){
    
    Sales_data item1,item2;
    
    while(cin>>item1>>item2){
    
    cout<<item1<<"\n"<<item2<<"\n";
    
    if(item1==item2)
    
    cout<<item1.get_bookNo()<<" equals "<<item2.get_bookNo()<<"\n";
    
    if(item1!=item2)
    
    cout<<item1.get_bookNo()<<" doesn't equal "<<item2.get_bookNo()<<"\n";
    
    cout<<(item1+item2)<<"\n";
    
    item1 += item2;
    
    cout<<item1<<"\n";
    
    }
    
    return 0;
}
    
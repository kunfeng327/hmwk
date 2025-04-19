#include <iostream>
#include <locale>
using namespace std;

int main(){
    // 设置区域设置为 UTF-8
    setlocale(LC_ALL, "en_US.UTF-8");
    // 使用 cout 输出 UTF-8 编码的字符串
    cout << "表示" << endl;
    return 0;
}
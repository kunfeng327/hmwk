#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Score
{
private:
    string name; // 记录学生姓名
    double s[4]; // 存储4次成绩，s[0]和s[1]存储2次随堂考试，s[2]存储期中考试，s[3]存储期末考试
    double total; // 记录总评成绩
    char grade;   // 记录对应的等级
    bool valid;   // 标记输入是否有效
public:
    Score() // 构造函数
    {
        grade = 'B'; // 默认等级为B
        valid = true; // 默认输入有效
    }
    void Input() // 输入学生姓名和成绩
    {
        cin >> name;
        for (int i = 0; i < 4; i++)
            cin >> s[i];
        if (s[0] > 50 || s[1] > 50 || s[2] > 100 || s[3] > 100||
            s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0) // 判断成绩是否在合理范围内
        {
            cout << "error" <<endl;
            valid = false; // 标记输入无效
        }
    }
    void Evalauate() // 计算总评成绩和等级
    {
        if (!valid) // 如果输入无效，直接返回
            return;
        total = (s[0] + s[1]) * 0.25 + s[2] * 0.25 + s[3] * 0.5;
        if (total >= 90)
            grade = 'A';
        else if (total >= 80)
            grade = 'B';
        else if (total >= 70)
            grade = 'C';
        else if (total >= 60)
            grade = 'D';
        else
            grade = 'E';
    }
    void Output() // 输出学生姓名、总评成绩和等级
    {
        if (!valid) // 如果输入无效，直接返回
            return;
        cout << "name: " << name << ", ";
        cout << "total: " << total << ", ";
        cout << "grade: " << grade << endl;
    }
};

int main()
{
    Score *s1 = new Score;
    s1->Input();
    s1->Evalauate();
    s1->Output();
    return 0;
}
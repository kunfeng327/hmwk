#include<iostream>
using namespace std;

class Singer
{
    private:
        string name;
        string gender;
        int age;
        double score;
    public:
        Singer(string n="",int s=0)
        {
            name=n;
            score=s;
        }
        
        string getName()
        {
            return name;
        }
        
        double getScore()
        {
            return score;
        }
        bool operator>(Singer &s)
        {
            return score>s.score;
        }
        bool operator==(Singer &s)
        {
            return score==s.score;
        }
        friend istream& operator>>(istream &in,Singer &s)
        {
            // cout<<"Enter name: ";
            in>>s.name>>s.gender>>s.age>>s.score;
            return in;
        }
        friend ostream& operator<<(ostream &out,Singer &s){
            out<<s.name<<" "<<s.gender<<" "<<s.age<<" "<<s.score;
            return out;
        }

};
int main()

{

Singer s1,s2;

cin>>s1>>s2;

cout<<s1<<"\n"<<s2<<endl;

if(s1>s2)

cout<<s1.getName()<<"'s score is higher than "<<s2.getName()<<"'s.\n";

else if(s1==s2)

cout<<s1.getName()<<"'s score is equal to "<<s2.getName()<<"'s.\n";

else

cout<<s1.getName()<<"'s score is lower than "<<s2.getName()<<"'s.\n";

return 0;

}



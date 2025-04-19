#include<iostream>
using namespace std;
class TableTennisPlayer{
    private:
        string firstname;
        string lastname;
        bool hasTable;
    public:
        TableTennisPlayer(const string &, const string &, bool);
        string FirstName() const;
        string LastName() const;
        bool HasTable() const;
        
};

class RatedPlayer: public TableTennisPlayer{
    private:
        int rating; 
    public:
        RatedPlayer(int,const string &, const string &, bool);
        int Rating() const { return rating; } // Added this function to get the rating
};
 
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht): firstname(fn), lastname(ln), hasTable(ht) {}
string TableTennisPlayer::FirstName() const { return firstname; }
string TableTennisPlayer::LastName() const { return lastname; }
bool TableTennisPlayer::HasTable() const { return hasTable; }



RatedPlayer::RatedPlayer(int r,const string &fn, const string &ln, bool ht): TableTennisPlayer(fn,ln,ht), rating(r) {}

int main(){

    string firstname, lastname;

    bool hasTable;

    int rating;

    char flag;

    while(cin>>flag){

        if(flag=='T'){

        cin>>firstname>>lastname>>hasTable;

        TableTennisPlayer tp(firstname,lastname,hasTable);

        if(tp.HasTable())
            cout<<tp.FirstName()<<" "<<tp.LastName()<<" has a table.\n";
        else
            cout<<tp.FirstName()<<" "<<tp.LastName()<<" hasn't a table.\n";

    } else if(flag=='R'){

        cin>>firstname>>lastname>>hasTable>>rating;

        RatedPlayer rp(rating,firstname,lastname,hasTable);

        if(rp.HasTable())
            cout<<rp.FirstName()<<" "<<rp.LastName()<<" has a table. The rating is "<<rp.Rating()<<".\n";

        else
            cout<<rp.FirstName()<<" "<<rp.LastName()<<" hasn't a table. The rating is "<<rp.Rating()<<".\n";
        }
    }
    return 0;

}    
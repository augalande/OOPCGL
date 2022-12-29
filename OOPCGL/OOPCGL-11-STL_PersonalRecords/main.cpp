#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class PersonInfo
{
    private:
    string name;
    string dob;
    string telno;

    public:
    PersonInfo()
    {
        name="";
        dob="";
        telno="";
    }

    PersonInfo(string a,string b,string c)
    {
        name=a;
        dob=b;
        telno=c;
    }

    void create()
    {
        cout<<"Enter Name :"<<endl;
        cin>>name;
        cout<<"Enter Date of Birth :"<<endl;
        cin>>dob;
        cout<<"Enter Telephone Number :"<<endl;
        cin>>telno;
    }

    void display()
    {
        cout<<endl;
        cout<<name<<"\t"<<dob<<"\t\t"<<telno<<endl;
    }

    friend bool operator==(const PersonInfo &p1,const PersonInfo &p2)
    {
        return(p1.name==p2.name);
    }

    string getname()
    {
        return name;
    }
};

int search(vector<PersonInfo> s,string name)
{
    vector<PersonInfo>::iterator iter;
    iter=find(s.begin(),s.end(),PersonInfo(name,"",""));
    if(iter!=s.end())
    {
    return(iter-s.begin());//both are pointers to objects...they have addresses 503,500....(503-500)..returns 3
    }
    else
    {
        return -1;
    }
}

bool compareNames(PersonInfo p1,PersonInfo p2)
{
    return(p1.getname()<p2.getname());
}

int main()
{
    int ch=0;
    vector<PersonInfo> s;
    do
    {
        cout<<endl;
        cout<<"* * * * * Student Records * * * * *"<<endl;
        cout<<"1) Create Record"<<endl;
        cout<<"2) Display Records"<<endl;
        cout<<"3) Search Record"<<endl;
        cout<<"4) Sort Records"<<endl;
        cout<<"5) Exit"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1: {PersonInfo p;
                    p.create();
                    s.emplace_back(p);
                    break;}

            case 2: {
                    cout<<endl;
                    cout<<"Name"<<"\t"<<"Date of Birth"<<"\t"<<"Telephone Number"<<endl;
                    for(int i=0;i<s.size();i++)
                            {
                                s[i].display();
                            }
                    break;}

            case 3: {cout<<"Enter Name to be searched :"<<endl;
                    string name;
                    cin>>name;
                    int i=search(s,name);
                    if( i==-1)
                    {
                        cout<<endl;
                        cout<<name<<" cannot be found in Student Records"<<endl;
                    }
                    else
                    {
                        cout<<endl;
                        cout<<name<<" found at position "<<i+1<<" in Student Records"<<endl;
                        cout<<endl;
                        cout<<"Name"<<"\t"<<"Date of Birth"<<"\t"<<"Telephone Number"<<endl;
                        s[i].display();
                    }
                    break;}

            case 4: {sort(s.begin(),s.end(),compareNames);
                    cout<<endl;
                    cout<<"Name"<<"\t"<<"Date of Birth"<<"\t"<<"Telephone Number"<<endl;
                    for(int i=0;i<s.size();i++)
                            {
                                s[i].display();
                            }
                    break;}

            case 5: {exit(0);}

            default:{cout<<endl;
                    cout<<"Invalid Choice"<<endl;
                    break;}
        }

    } while (ch!=5);
    
    return 0;
}
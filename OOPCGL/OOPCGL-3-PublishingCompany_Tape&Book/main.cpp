#include<iostream>
#include<string>
using namespace std;

class publication
{
    private:
    string title;
    float price;

    public:

    publication()
    {
        title="";
        price=0.0;
    } 
     void add()
     {
        cout<<"Enter Title of Publication :"<<endl;
        cin.ignore();
        getline(cin,title);
        cout<<"Enter Price of Publication :"<<endl;
        cin>>price;
     }
    void display()
    {
        cout<<"Title of Publication :"<<title<<endl;
        cout<<"Price of Publication :"<<price<<endl;
    }


};

class book:public publication
{
    private:
    int page_count;

    public:
    book()
    {
        page_count=0;
    }

    void add_page()
    {
        try{
        cout<<endl;
        add();
        cout<<"Enter Page Count of Book :"<<endl;
        cin>>page_count;
        if(page_count<0)
        {
            throw page_count;
        }
        }
        catch(...)
        {
            page_count=0;
        }

    }
    void display_page()
    {
        cout<<endl;
        cout<<"* * * * * * * * * *"<<endl;
        display();
        cout<<"Page Count of Publication :"<<page_count<<endl;
        cout<<"* * * * * * * * * *"<<endl;
    }
    

};

class tape:public publication
{
    private:
    float play_time;

    public:
    tape()
    {
        play_time=0.0;
    }
    void add_tape()
    {
        try{
        cout<<endl;
        add();
        cout<<"Enter Play Time of Tape :"<<endl;
        cin>>play_time;
        if(play_time<0)
        {
            throw play_time;
        }
        }
        catch(...)
        {
            play_time=0.0;
        }

    }
    void display_tape()
    {
        cout<<endl;
        cout<<"* * * * * * * * * *"<<endl;
        display();
        cout<<"Play Time of Publication :"<<play_time<<endl;
        cout<<"* * * * * * * * * *"<<endl;
    }

};

int main ()
{
    book b[10];
    tape t[10];
    int ch=0,b_count=0,t_count=0;
    do
    {
        cout<<endl;
       cout<<"* * * * * Publication System * * * * *"<<endl;
       cout<<"1)Add Book to Publication System"<<endl;
       cout<<"2)Add Tape to Publication System"<<endl;
       cout<<"3)Display Books in Publication System"<<endl;
       cout<<"4)Display Tapes in Publication System"<<endl;
       cout<<"5)Exit"<<endl;
       cout<<"Enter your choice :"<<endl;
       cin>>ch;
       switch(ch)
       {
        case 1:b[b_count].add_page();
                b_count++;
                break;

        case 2:t[t_count].add_tape();
                t_count++;
                break;

        case 3: for(int i=0;i<b_count;i++)
                {
                    b[i].display_page();
                }                
                break;

        case 4: for(int i=0;i<t_count;i++)
                {
                    t[i].display_tape();
                }
                break;

        case 5: exit(0);
                 break;

        default:cout<<endl;
                cout<<"Invalid Choice"<<endl;
                break;                        

       }
    } while (ch!=5);
    
    return 0;
}

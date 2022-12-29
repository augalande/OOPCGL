#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Database
{
    private:
    char name[10],rollno[10],cls[10],div[10],dob[10],bg[10];
    static int count;

    public:
    Database()
    {
        char *name =new char[10];
        char *rollno=new char[10];
        char *cls=new char[10];
        char *div=new char[10];
        char *dob=new char[10];
        char *bg=new char[10];
    }

    Database(Database *obj)
    {
        strcpy(this->name,obj->name);    // strcpy(destination,source)
        strcpy(this->rollno,obj->rollno);
        strcpy(this->cls,obj->cls);
        strcpy(this->div,obj->div);
        strcpy(this->dob,obj->dob);
        strcpy(this->bg,obj->bg);
    }

    ~Database()
    {
        cout<<endl;
        cout<<this->name<<" object is destroyed"<<endl;
    }

    static void getcount()
    {
        cout<<endl;
        cout<<"Total number of Students in Database :"<<(count-1)<<endl;
    }

    friend class Information;

};

int Database::count=0;

class Information
{
    private:
    char ca[10],telno[10],dlno[10];

    public:
    Information()
    {
        char* ca=new char[10];
        char* telno=new char[10];
        char* dlno=new char[10];
    }

    void accept(Database *obj);
    void display(Database *obj);
    friend class Database;
};

void Information::accept(Database *obj)
{
    cout<<endl;
    cout<<"Name :"<<endl;
    cin>>obj->name;
    cout<<"Roll Number :"<<endl;
    cin>>obj->rollno;
    cout<<"Class :"<<endl;
    cin>>obj->cls;
    cout<<"Division :"<<endl;
    cin>>obj->div;
    cout<<"Date of Birth :"<<endl;
    cin>>obj->dob;
    cout<<"Blood Group :"<<endl;
    cin>>obj->bg;
    cout<<"Telephone Number :"<<endl;
    cin>>this->telno;
    cout<<"Contact Address :"<<endl;
    cin>>this->ca;
    cout<<"Driving License Number :"<<endl;
    cin>>this->dlno;
    obj->count++;
}

void Information::display(Database *obj)
{
    cout<<obj->name<<setw(10)<<obj->rollno<<setw(10)<<obj->cls<<setw(10)<<obj->div<<setw(10)<<obj->dob<<setw(10)<<obj->bg<<setw(10)<<this->telno<<setw(10)<<this->ca<<setw(10)<<this->dlno<<endl;
}

int main()
{
    Database *d1,*a[10];
    Information *i1,*b[10];

    d1=new Database;
    i1=new Information;

    i1->accept(d1);
    i1->display(d1);

    Database *d2(d1);
    d2=new Database;
    i1->display(d2);

    delete i1;
    delete d1;
    delete d2;

    int ch=0,n=0;

    do
    {
        try
        {
        cout<<endl;
        cout<<"* * * * * Student Information System * * * * *"<<endl;
        cout<<"1) Accept"<<endl;
        cout<<"2) Display"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>ch;
        if(ch!=1&&ch!=2&&ch!=3)
        {
            throw ch;
            exit(0);
        }
        }
        catch(...)
        {
            cout<<endl;
            cout<<"Ivalid Choice"<<endl;
        }

        switch(ch)
        {
            case 1: a[n]=new Database;
                    b[n]=new Information;
                    b[n]->accept(a[n]);
                    n++;
                    break;

            case 2: cout<<endl;
                    cout<<"Name"<<setw(10)<<"RollNo"<<setw(10)<<"Cls"<<setw(10)<<"Div"<<setw(10)<<"DOB"<<setw(10)<<"BldGrp"<<setw(10)<<"TelNo"<<setw(10)<<"ContAdd"<<setw(10)<<"DLNo"<<endl;
                    for(int i=0;i<n;i++)
                    {
                        cout<<endl;
                        b[i]->display(a[i]);
                        cout<<endl;
                    }
                    Database::getcount();
                    break;

            case 3:exit(0);
        }

    } while (ch!=3);
}
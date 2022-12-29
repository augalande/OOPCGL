#include<iostream>
#include<fstream>
using namespace std;

class student
{
    private:
    string name;
    int rollno;

    public :
    student()
    {
        name ="";
        rollno=0;
    }
    
    void add()
    {
        fstream fs;
        fs.open("data.txt",ios::app);
        if(!fs)
        {
            cout<<"File Creation Failed"<<endl;
        }
        else 
        {
            cout<<endl;
            cout<<"Enter Name :"<<endl;
            cin>>name;
            cout<<"Enter Roll Number :"<<endl;
            cin>>rollno;
            fs<<name<<"   ";
            fs<<rollno<<endl;
        }
        fs.close();
    }

    void display()
    {
        fstream fs;
        fs.open("data.txt",ios::in);
        if(!fs)
        {
            cout<<"File Openning Failed"<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"File Contents :"<<endl;
            while(!fs.eof())
            {
                fs>>name;
                fs>>rollno;
                if(!fs.eof())   //Double Verification for .eof()
                {
                cout<<name<<"   "<<rollno<<endl;
                }
                else
                {
                    break;
                }
            }
        }
        fs.close();

    }
};

int main()
{
    student s;
    int ch=0;
    do
    {
        cout<<endl;
        cout<<"* * * * * Student Information System * * * * *"<<endl;
        cout<<"1) Add Data"<<endl;
        cout<<"2) Display Data"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>ch;
        
        switch(ch)
        {
            case 1:s.add();
                   break;

            case 2:s.display();
                   break;

            case 3:exit(0);

            default:cout<<"Invalid Choice :"<<endl;
                    break;
        }

        
    } while (ch!=3);
    
    return 0;
}
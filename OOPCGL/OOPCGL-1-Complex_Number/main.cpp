#include<iostream>
using namespace std;

class Complex
{
    private:
    float x,y;

    public:
    Complex()
    {
        x=0;
        y=0;
    }
    Complex operator+(Complex);
    Complex operator*(Complex);
    friend istream & operator>>(istream &,Complex &);
    friend ostream & operator<<(ostream &,Complex &);
};

Complex Complex :: operator+(Complex obj)
{
    Complex temp;
    temp.x=x+obj.x;
    temp.y=y+obj.y;
    return temp;
}

Complex Complex :: operator*(Complex obj)
{
    Complex temp;
    temp.x=(x*obj.x)-(y*obj.y);
    temp.y=(x*obj.y)+(y+obj.x);
    return temp;
}

istream & operator>>(istream &ain,Complex &obj)
{
    cout<<"Enter Real part:-"<<endl;
    ain>>obj.x;
    cout<<"Enter Imaginary part:-"<<endl;
    ain>>obj.y;
    return ain;
}

ostream & operator<<(ostream &aout,Complex &obj)
{
    aout<<obj.x<<"+"<<obj.y<<"i"<<endl;
    return aout;
}

int main()
{
    Complex a,b,c,d;

    cout<<"First Complex Number:-"<<endl;
    cin>>a;
    cout<<a;

    cout<<"Second Complex Number:-"<<endl;
    cin>>b;
    cout<<b;

    cout<<"Addition of these Complex Numbers:-"<<endl;
    c=a+b;
    cout<<c;

    cout<<"Multiplication of these Complex Numbers:-"<<endl;
    d=a*b;
    cout<<d;
    return 0;
}
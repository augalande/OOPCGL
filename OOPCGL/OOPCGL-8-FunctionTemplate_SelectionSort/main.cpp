#include<iostream>
using namespace std;

template<typename T>
void sort(T a[],int n)
{
    T temp;
    int pos_min;
    for(int i=0;i<n-1;i++)
    {
        pos_min=i;
        for(int j=i+1;i<=n-1;i++)
        {
            if(a[j]<a[pos_min])
            {
                pos_min=j;
            }
        }
        if(pos_min!=i)
        {
            temp=a[i];
            a[i]=a[pos_min];
            a[pos_min]=temp;
        }
    }
    for(int i=0;i<=n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int ch=0;
    int a[10];
    float b[10];
    int n;
    do
    {
        cout<<"* * * * * Selection Sort Using Function Template * * * * *"<<endl;
        cout<<"1) Integer Array"<<endl;
        cout<<"2) Float Array"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:cout<<"Enter number of elements in Integer Array :"<<endl;
                   cin>>n;
                   cout<<"Enter elements in Integer Array :"<<endl;
                   for(int i=0;i<n;i++)
                   {
                    cin>>a[i];
                   }
                   cout<<endl;
                   cout<<"Sorted Integer Array :"<<endl;
                   sort<int> (a,n);
                   cout<<endl;
                   break;

            case 2:cout<<"Enter number of elements in Float Array :"<<endl;
                   cin>>n;
                   cout<<"Enter elements in Float Array :"<<endl;
                   for(int i=0;i<n;i++)
                   {
                    cin>>b[i];
                   }
                   cout<<endl;
                   cout<<"Sorted Float Array :"<<endl;
                   sort<float> (b,n);
                   cout<<endl;
                   break;

            case 3:exit(0);

            default:cout<<"Invalid Choice"<<endl;
                    cout<<endl;
                    break;
        }
    } while (ch!=3);
    
    return 0;
}
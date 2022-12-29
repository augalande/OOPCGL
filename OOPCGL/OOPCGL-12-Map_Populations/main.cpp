#include<iostream>
#include<map>
using namespace std;

int main()
{
    typedef map<string,int> maptype;
    maptype populationMap;

    populationMap.insert(pair<string,int>("Maharashtra",938765));
    populationMap.insert(pair<string,int> ("Karnataka",873693));
    populationMap.insert(pair<string,int> ("Goa",3235));
    populationMap.insert(pair<string,int> ("Gujrat",783746));
    populationMap.insert(pair<string,int> ("Rajasthan",563735));

    cout<<endl;
    cout<<"* * * * * Population of Indian States System * * * * *"<<endl;
    cout<<endl;
    cout<<"Total Number of Indian States in Database :"<<populationMap.size()<<endl;

    string s;
    cout<<endl;
    cout<<"Enter the name of a State :"<<endl;
    cin>>s;

    maptype::iterator iter;
    iter=populationMap.find(s);

    if(iter!=populationMap.end())
    {
        cout<<endl;
        cout<<"Population of "<<s<<" is "<<iter->second<<endl;
    }
    else
    {
        cout<<endl;
        cout<<s<<" state cannot be found"<<endl;
    }

    populationMap.clear();
    return 0;
}
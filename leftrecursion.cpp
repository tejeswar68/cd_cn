#include<bits/stdc++.h>

using namespace std;

void leftrecursion(string &s )
{
    vector<string> v;
    string temp;
    string com;
    string main;
    for(int i=0;i<s.length();i++)
    {

        if(s[i-1]=='>')
        {
            main+=temp;
            temp.clear();
        }
        if(i==s.length()-1)
            temp+=s[i];

        if(s[i]=='|'||i==s.length()-1)
        {

              v.push_back(temp);
              temp.clear();
        }
        else
        {
            temp+=s[i];
        }

    }
    vector<string>v2;
    vector<string> v3;
    for(int i=0;i<v.size();i++)
    {

        if(v[i].substr(0,1)!=s.substr(0,1))
        {
            v3.push_back(v[i]);
        }
        else
        {
            v[i].erase(v[i].begin(),v[i].begin()+1);
            v2.push_back(v[i]);
        }

    }


    cout<<"Left Recursed Grammar of "<<s<<endl;
    if(v2.size()>0)
    {
         string res1;
    res1+=main;
    for(int i=0;i<v3.size();i++)
    {
        if(i!=0)
            res1+="|";
        res1+=v3[i]+s.substr(0,1)+'`';
    }
    cout<<res1<<endl;
    string res2;
    res2+=main;
    res2.insert(res2.begin()+1,'`');
    for(int i=0;i<v2.size();i++)
    {
        if(i!=0)
            res2+="|";
        res2+=v2[i]+s.substr(0,1)+'`';
    }
    res2+="|e";
    cout<<res2<<endl;
}
else
        cout<<s<<endl;
}

int main()
{
    int n;
    cout<<"Enter no.of Equations:";
    cin>>n;
    cout<<"Enter Equations:";
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        leftrecursion(x);
    }
    return 0;
}

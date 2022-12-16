#include<bits/stdc++.h>

using namespace std;

string commonprefix(string &s1,string s2)
{
 string s;
 int len = min(s1.length(),s2.length());
 for(int i=0;i<len;i++)
 {
     if(s1[i]==s2[i])
     {
        s+=s1[i];
     }
     else
        break;
 }
 return s;

}
void leftfactoring(string &s )
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
    for(int i=0;i<v.size()-1;i++)
    {
        com = commonprefix(v[i],v[i+1]);
        if(com.length()>0)
            break;
    }
    vector<string>v2;
    vector<string> v3;
    for(int i=0;i<v.size();i++)
    {

        if(v[i].substr(0,com.length())!=com)
        {
            v3.push_back(v[i]);
        }
        else
        {
            v[i].erase(v[i].begin(),v[i].begin()+com.length());
            v2.push_back(v[i]);
        }

    }
    cout<<"Left factored Grammar of "<<s<<endl;
    string res1;
    res1+=main+com+s[0]+"`";
    for(int i=0;i<v3.size();i++)
    {
         res1+="|";
        res1+=(v3[i]);

    }
    cout<<res1<<endl;
    string res2;
    res2+=main;
    res2.insert(res2.begin()+1,'`');
    for(int i=0;i<v2.size();i++)
    {
        if(i!=0)
            res2+="|";
        res2+=v2[i];
    }
    cout<<res2<<endl;



}

int main()
{
    int n;
    cout<<"Enter no.of Equations:";
    cin>>n;
    cout<<"Enter Equations:";
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }
    string com;
    for(int i=0;i<v.size();i++)
    {
        leftfactoring(v[i]);
    }


    return 0;
}

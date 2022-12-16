#include<bits/stdc++.h>

using namespace std;

string bytestuffing()
{
    string s;
    cout<<"Enter string to Bytestuff:";
    cin >> s;
    s.insert(0,"F");
    for(int i=0;i<s.length();i++)
    {
        if(s.substr(i,3)=="ESC"||s.substr(i,4)=="FLAG"){
            s.insert(i,"ESC");
            i+=3;
        }
    }
    s+="F";
    cout<<"Bytestuffed String is : "<<s<<endl;
    return s;
}

void bytedestuffing(string s)
{
    s.erase(0,1);
    s.erase(s.size()-1,1);

    for(int i=0;i<s.length();i++)
    {
        if(s.substr(i,3)=="ESC"&&(s.substr(i+3,4)=="FLAG"||s.substr(i+3,3)=="ESC"))
        {
            s.erase(i,3);
        }
    }
    cout<<"Byte Destuffed String : "<<s<<endl;
}

int main()
{
    bytedestuffing(bytestuffing());
    
    return 0;
}
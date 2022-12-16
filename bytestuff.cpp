#include <bits/stdc++.h>

using namespace std;

void bytestuffing()
{
    string  s1;
    cout<<"Enter the Message to be send:";
    cin >> s1;
    s1.insert(0,"F");
    for(int i=1;i<s1.size();i++)
    {
        if(s1.substr(i,3)=="ESC"||s1.substr(i,4)=="FLAG")
        {
            s1.insert(i,"ESC");
            i+=3;
        }
    }
    s1.insert(s1.size(),"F");
    cout<<"Byte Stuffed String : "<<s1<<endl;
}
void bytedestuffing()
{
    string s;
    cout<<"Enter The Byte Stuffed String:";
    cin >> s;
    s.erase(0,1);
    s.erase(s.size()-1,1);
    for(int i=0;i<s.length()-1;i++)
    {
        if(s.substr(i,3)=="ESC" && (s.substr(i+3,3)=="ESC"||s.substr(i+3,4)=="FLAG"))
        {
            s.erase(i,3);
        }
    }
    cout<<"Byte Destuffed String : "<<s<<endl;

}
int main()
{
 bytestuffing();
 bytedestuffing();

}
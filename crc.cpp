#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout<<"SENDER\n";
    string msg,crc,encoded="";
    cout<<"Enter message: ";
    getline(cin,msg);
    cout<<"Enter Crc generator polynomial: ";
    getline(cin,crc);
    int m=msg.length(),n=crc.length();
    encoded+=msg;
    for(int i=1;i<=n-1;i++)
        encoded+='0';
    for(int i=0;i<=encoded.length()-n;)
    {
        for(int j=0;j<n;j++)
            encoded[i+j]=encoded[i+j]==crc[j]?'0':'1';
        for(; i<encoded.length()&&encoded[i]!='1';i++);
    }
    cout<<msg+encoded.substr(encoded.length()-n+1);

    cout<<"RECEIVER\n";
    string rcrc,rencoded;
    int flag=0;
    cout<<"Enter Encoded data: ";
    getline(cin,rencoded);
    cout<<"Enter Crc generator polynomial: ";
    getline(cin,rcrc);
    for(int i=0;i<=rencoded.length()-rcrc.length();)
    {
        for(int j=0;j<rcrc.length();j++)
            rencoded[i+j]=rencoded[i+j]==rcrc[j]?'0':'1';
        for(; i<rencoded.length()&&rencoded[i]!='1';i++);
    }
    for(char i:rencoded.substr(rencoded.length()-rcrc.length()))
    {
        if(i!='0')
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"No Error";
    else
    cout<<"Error in coomunication";
    
return 0;
}

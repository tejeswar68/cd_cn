#include<bits/stdc++.h>

using namespace std;

int i=0,err=0;
string s;

void T();
void EP();
void E()
{
    T();
    EP();
}

void F()
{
    if(isalpha(s[i])||isdigit(s[i]))
        i++;
    else if(s[i]=='(')
    {
        i++;
        E();
        if(s[i]==')')
            i++;
        else
            err=1;

    }
    else
        err = 1;
}

void TP()
{
    if(s[i]=='*')
    {
        i++;
        F();
        TP();
    }
}

void T()
{
    F();
    TP();
}


void EP()
{
    if(s[i]=='+')
    {
        i++;
        T();
        EP();
    }
}



int main()
{
    cout<<"Enter input string:";
    cin >> s;
    i = 0,err=0;
    E();
    if(s.length()==i && err==0)
        cout<<"String Accepted\n";
    else
        cout<<"String Rejected\n";
    return 0;
}
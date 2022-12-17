#include<bits/stdc++.h>

using namespace std;

int findnr(int m)
{
    int r = 1;
    while((1<<r)< m+r+1)
        r++;
    return r;
}

void sender()
{
    int m;
    cout<<"Enter no.of message Bits  : ";
    cin >> m;
    vector<int> msg(m);
    cout<<"Enter Message Bits from 0 to n-1 order: ";
    for(int i=0;i<m;i++)
        cin >> msg[i];
    int parity;
    cout<<"Enter 1 for odd || 0 for even Parity :";
    cin >> parity;
    int r = findnr(m);
    vector<int> hamming(m+r);
    vector<int> dataind ;
    int j=0;
    for(int i=1;i<=(m+r);i++)
    {
        if(i == (1<<j) && j<r)
        {
            hamming[(1<<j)-1]=-1;
            j++;
        }
            
        else
            dataind.push_back(i-1);
    }
    j=0;
    for(int i=0;i<m+r;i++)
    {
        if(hamming[i]!=-1)
        {
            hamming[i] = msg[j];
            ++j;
        }
    }
    for(int i=0;i<m+r;i++)
    {
        if(hamming[i]==-1)
        {
            int x= 0;
            for(int k =0 ; k < dataind.size();k++)
            {
                if((1LL<<i) & (dataind[k]+1))
                    x ^= hamming[dataind[k]];
            }
            if(x & parity || (!x & !parity))
                hamming[i] = 0;
            else
                hamming[i] = 1;

        }
    }
    cout<<"CODE WORD : \n";
    for(int i=0;i<hamming.size();i++)
        cout<<hamming[i]<<" ";
    cout<<endl;
}

void receiver()
{
    
    cout<<"Enter Codeword size : ";
    int s;
    cin >> s;
    cout<<"Enter Codeword : ";
    vector<int> hamming(s);
    for(int i=0;i<s;i++)
        cin >> hamming[i];
     int parity;
    cout<<"Enter parity : ";
    cin >> parity;
    int r = ceil(log2(s));
    vector<int> dataind,parityind;
    int j=0;
    for(int i=1;i<=s;i++)
    {
        if(i == (1<<j) && j<r)
        {
             parityind.push_back((1<<j)-1);
              j++;
        }
        else
            dataind.push_back(i-1);
    }
    int flag=0;
    for(int i=0;i<parityind.size();i++)
    {
        int x  =0;
        for(int k=0;k<dataind.size();k++)
        {
            if((1LL<<parityind[i]) & dataind[k]+1)
                x^=hamming[dataind[k]];
        }
        x ^= hamming[parityind[i]];
        if((!x && parity)||(x && !parity))
        {
            flag+=(1<<i);
        }
        
    }
   flag? cout<<"Error at postion \n"<<flag : cout<<"No Error!\n";
 

}

int main()
{
    
    // sender(m,msg,parity);
    sender();
    receiver();
    receiver();
        return 0;
}
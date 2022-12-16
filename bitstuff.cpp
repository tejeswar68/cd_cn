#include<bits/stdc++.h>

using namespace std;

vector<string> bsframes;
int fs;
string flagg;
void receiver()
{
  if(bsframes.size()==0)
    cout<<"Sender Doesn't Transfer any data"<<endl;
  else
  {
     vector<string> frames = bsframes;
     bsframes.clear();
     int fsize = fs;
     fs=0;
     string flag = flagg;
     string data;
     for(int i=0;i<frames.size();i++)
     {
         frames[i].erase(0,flag.size());
         frames[i].erase(frames[i].end()-flag.size(),frames[i].end());
         int c1=0;
         for(int j=0;j<frames[i].size();j++)
         {
             if(frames[i][j]=='1')
                c1++;
             else
                c1=0;
             if(c1==5)
                frames[i].erase(j+1,1);
         }
         data.append(frames[i]);

     }
     cout<<"Transmitted Data after BitUnstuffing and frame Elimination :"<<endl;
     cout<<data <<endl;
  }
}

void transfer(vector<string> &frames,int fsize,string flag)
{
    bsframes = frames;
    fs= fsize;
    flagg = flag;
}

void sender()
{
    string data;
    int fsize;
    cout<<"Enter Payload/Data : ";
    cin>>data;
    cout<<"Enter Frame Size : ";
    cin>>fsize;
    vector<string> frames;
    string flag = "01111110";
    int nf = data.length()/fsize;
    int j=0;
    for(int i=0;i<nf;i++)
    {
        string s1,s2;
        s1.append(flag);
        for(int k=j;k<j+fsize;k++)
            s2.push_back(data[k]);
        int c1=0;
        for(int k=0;k<s2.size();k++)
        {
            if(s2[k]=='1')
                c1++;
            else
                c1=0;

            if(c1==5)
                s2.insert(k+1,"0");

        }
        s1.append(s2);
        s1.append(flag);
        frames.push_back(s1);
        j=j+fsize;
    }

    cout<<"No.of frames :"<<nf<<endl;
    cout<<"Bit Stuffed Frames : "<<endl;
    for(int i=0;i<frames.size();i++)
        cout<<frames[i]<<endl;
    transfer(frames,fsize,flag);

}

int main()
{
      while(1)
      {

        cout<<"Select Option:"<<endl<<"1.SENDER"<<endl<<"2.RECEIVER"<<endl<<"3.QUIT"<<endl;
        int op;
        cin>>op;
        if(op==3)
            break;
    switch(op) {
                case 1: sender();
                        break;
                case 2: receiver();
                        break;
                }
      }



    return 0;
}
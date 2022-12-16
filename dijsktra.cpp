#include<bits/stdc++.h>

using namespace std;

int v,cost[100][100],src;
 int dist[100];
bool visited[100] = {0};
int parent[100] ;


void init()
{
   for(int i=0;i<v;i++)
   {
    dist[i]=INT_MAX;
    parent[i]=i;
   }
    
  dist[src] = 0;

}

int getNearest()
{
    int minvalue = INT_MAX;
    int minnode = 0;
    for(int i=0;i<v;i++)
    {
        if(!visited[i] && dist[i]<minvalue && dist[i])
        {
            minvalue = dist[i];
            minnode = i;
        }
    }
    return minnode;
}

void display()
{
    cout<<"Node:\t\t\tCost : \t\t\tPath:\n";
    for(int i=0;i<v;i++)
    {
        cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<" ";
        cout<<i<<" ";
        int parnode  = parent[i];
        while(parnode!=src)
        {
            cout<<" <- "<<parnode<<" ";
            parnode = parent[parnode];
        }
        if(i!=src)
            cout<<" <- "<<src;
        cout <<endl;
    }
}


void dijkstra()
{
    for(int i=0;i<v;i++)
    {
        int nearest = getNearest();
        visited[nearest] = true;
        for(int adj =0;adj<v;adj++)
        {
            if(cost[nearest][adj]!=0 && dist[adj] > dist[nearest]+cost[nearest][adj])
            {
                dist[adj] = dist[nearest]+cost[nearest][adj];
                parent[adj] = nearest; 
            }
               
        }
    }
}


int main()
{
    cout<<"Enter no.of vertices : ";
    cin >> v;
    cout<<"Enter Adjacency matrix : ";
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
        cin >> cost[i][j];
    cout<<"Enter source vertex : ";
    cin >> src;
    init();
    dijkstra();
    display();


    return 0;
}
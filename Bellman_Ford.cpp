#include<iostream>
#include<vector>
using namespace std;

void bellman_ford(int src, vector<pair<int,int> > *Graph, int *dist ,int n)
{
  vector<pair<int,int> > :: iterator it;
  dist[src]=0; //distance of source vertex to itself is zero
  // Distance from source vertex each other vertex is updated if its less than the current value
  for(int i=0;i<n;i++)
  {
      for(it=Graph[i].begin();it<Graph[i].end();it++)
      {
          if((dist[it->first]>dist[i]+it->second)&&dist[i]!=10000)
            dist[it->first]=dist[i]+it->second;
      }
  }

/*  The distance value is checked again to detect the negetive edges */
    for(int i=0;i<n;i++)
  {
      for(it=Graph[i].begin();it<Graph[i].end();it++)
      {
          if(dist[i]+it->second < dist[it->first])
           cout<<"Negetive cycle detected\n";

      }
  }
}

int main()
{
     /*Driver Program to test the algorithm */
    int n,s,u,v,wt;
    char ans;
    cout<<"Enter the number of vertices = ";
    cin>>n;
    vector<pair<int,int> > Graph[n];
    int dist[n];

    for (int i=0;i<n;i++)
  {
      dist[i]=10000; //10000 represents infinity value
  }

    while(true)
    {
        cout<<"1st: ";
        cin>>u;
        cout<<"2nd: ";
        cin>>v;
        cout<<"enter weight";
        cin>>wt;
        Graph[u].push_back(make_pair(v,wt)); //Directed graph
        cout<<"Want to add more Y/N\n";
        cin>>ans;
        if(ans=='N' || ans=='n')
           break;


    }
  cout<<"Enter the starting vertex = ";
  cin>>s;
  vector<pair<int,int> >:: iterator it;
 bellman_ford(s,Graph,dist,n);
 /*Display graph using adjacency list */
  cout<<"\nThe graph is: \n";
  for(int i=0;i<n;i++)
    {
        cout<<i<<" :- ";
        for(it=Graph[i].begin();it<Graph[i].end();it++)
        {
            cout<<it->first<<" weight "<<it->second<<"->";

        }
        cout<<"\n";
    }
    cout<<"\nDistance from "<<s<<" to all vertices are:-\n";
    cout<<"\nVertex :- "<<"Distance"<<"\n";
  for(int i=0;i<n;i++)
  {
      cout<<i<<"        "<<dist[i]<<"\n";
  }
    return 0;
}

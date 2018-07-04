#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void dijkistra(int src, bool *visited, vector<pair<int,int> > *Graph, int *dist ,int n)
{
     vector<pair<int,int> >:: iterator it;
     dist[src]=0; // Distance of Source vertex is 0
     int min_idx=0; //Index of vertex having minimum distance value
     int vis_c; //Number of visited vertices

    while(vis_c!=n) //Loop until number of visited vertices are equal to number of vertices of the graph
    {
       vis_c=0;
       int min=1000;

       //Vertex having minimum distance and which is not visited is selected
       for(int i=0;i<n;i++)
       {
         if(dist[i]>=0&&dist[i]<min&&visited[i]!=true)
         {
           min=dist[i];
           min_idx=i;

         }
       }
       visited[min_idx]=true; //Selected vertex is marked visited
     for (it=Graph[min_idx].begin();it<Graph[min_idx].end();it++)
     {
       if(!visited[it->first]&&dist[it->first]>dist[min_idx]+it->second&&dist[min_idx]!=10000) //If vertices adjacent to the selected vertex are not visited and its distance is greater than the current distance then it is updated
         dist[it->first]=dist[min_idx]+it->second; //Distance of the vertices adjacent to selected index are updated
     }
     for(int i=0;i<n;i++)
     {
         if(visited[i]==true) //Number of visited vertices are counted
            vis_c++;
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
    bool visited[n];
    int dist[n];

    for (int i=0;i<n;i++)
  {
      visited[i]=false;
      dist[i]=10000;


  }

    while(true)
    {
        cout<<"1st: ";
        cin>>u;
        cout<<"2nd: ";
        cin>>v;
        cout<<"enter weight";
        cin>>wt;
        Graph[u].push_back(make_pair(v,wt));
        Graph[v].push_back(make_pair(u,wt));
        cout<<"Want to add more Y/N\n";
        cin>>ans;
        if(ans=='N' || ans=='n')
           break;


    }
  cout<<"Enter the starting vertex = ";
  cin>>s;
  vector<pair<int,int> >:: iterator it;
 dijkistra(s,visited,Graph,dist,n);
 /*Display graph using adjacency list */
  for(int i=0;i<n;i++)
    {
        cout<<i<<" :- ";
        for(it=Graph[i].begin();it<Graph[i].end();it++)
        {
            cout<<it->first<<" weight "<<it->second<<"->";

        }
        cout<<"\n";
    }
    cout<<"Vertex :- "<<"Distance"<<"\n";
  for(int i=0;i<n;i++)
  {
      cout<<i<<"        "<<dist[i]<<"\n";
  }
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

/*Shortest Path Algorithm for Unweighted graph*/
void bfs_mod(int src,int dest,bool *visited,vector<int> *Graph, int *dist , vector<int> *path)
{
    //Modified BFS algorithm to show shortest path between two vertices and show the path between them
   vector<int> queue;  //Queue to hold values in BFS
   vector<int>:: iterator it; //Vector Iterator
   visited[src]=true; //Source Vertex is visited
   queue.push_back(src); //Source is pushed back in the queue
   path[src].push_back(src); //Add source in its path
   dist[src]=0; //Dist of source to itself is zero
   while(true) //Loop until destination vertex is not reached
   {
      int temp=queue.front();
      it=queue.begin(); //pointing iterator to front element of queue
      queue.erase(it); //Removing first element from the queue

      for (it=Graph[temp].begin();it<Graph[temp].end();it++)
      {
          if(!visited[*it])
          {
              visited[*it]=true;
              dist[*it]=dist[temp]+1; //Updating the distance
              path[*it].insert(path[*it].end(),path[temp].begin(),path[temp].end()); //Appending the path of the parent vertex to the current vertex
              queue.push_back(*it);
              path[*it].push_back(*it); //Appending the current vertex the path
              if(*it==dest) //If destinaqtion is found then return
                return;
          }

      }


   }


}
int main()
{
    /*Driver Program to test the algorithm */
    int n,s,u,v,d;
    char ans;
    cout<<"Enter the number of vertices = ";
    cin>>n;
    vector<int> Graph[n],path[n];
    bool visited[n];
    int dist[n];

    for (int i=0;i<n;i++)
  {
      visited[i]=false;
      dist[i]=-1;


  }

    while(true)
    {
        cout<<"1st: ";
        cin>>u;
        cout<<"2nd: ";
        cin>>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);

        cout<<"Want to add more Y/N\n";
        cin>>ans;
        if(ans=='N' || ans=='n')
           break;


    }

    vector <int> :: iterator  it;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" :- ";
        for(it=Graph[i].begin();it<Graph[i].end();it++)
        {
            cout<<*it<<"->";
        }
        cout<<"\n";
    }

        cout<<"Enter the starting vertex = ";
        cin>>s;


        cout<<"Enter the destination vertex = ";
        cin>>d;
        bfs_mod(s,d,visited,Graph,dist,path);
        cout<<"Distance = "<<dist[d]<<"\n";
        cout<<"Path = ";
        for (it=path[d].begin();it<path[d].end();it++)
            cout<<*it<<"->";







    return 0;
}

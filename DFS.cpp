#include<vector>
#include<iostream>
using namespace std;
void initialize(bool *visited,int n)
{
  for (int i=0;i<n;i++)
  {
      visited[i]=false;

  }

}
void bfs(bool *visited ,int st ,vector <int> *V)
{
visited[st]=true;
vector <int> Queue;
Queue.push_back(st);
int vt=0;
    while(!Queue.empty())
    {
        vector <int> :: iterator  it,it1;
        vt=Queue.front();
        it1=Queue.begin();
        Queue.erase(it1);
        cout<<vt<<"\n";

            for(it=V[vt].begin();it<V[vt].end();it++)
            {
                if(!visited[*it])
                {
                    //cout<<*it<<"\n";
                    visited[*it]=true;
                    Queue.push_back(*it);

                }

            }

       }

}
int main()
{
    int n,s,u,v;
    char ans;
    cout<<"Enter the number of vertices = ";
    cin>>n;
    vector<int> V[n],Ret;
    bool visited[n];

    initialize(visited,n);

    while(true)
    {
        cout<<"want to add edges \n";
        cout<<"1st: ";
        cin>>u;
        cout<<"2nd: ";
        cin>>v;
        V[u].push_back(v);
        V[v].push_back(u);

        cout<<"Want to add more Y/N\n";
        cin>>ans;
        if(ans=='N' || ans=='n')
           break;


    }

    vector <int> :: iterator  it;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" :- ";
        for(it=V[i].begin();it<V[i].end();it++)
        {
            cout<<*it<<"->";
        }
        cout<<"\n";
    }
    cout<<"Enter the starting vertex = ";
    cin>>s;
    bfs(visited,s,V);


    return 0;
}

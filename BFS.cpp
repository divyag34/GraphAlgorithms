#include<iostream>
#include<vector>
using namespace std;
void dfs(int *visited,int n, vector<int> *V,int st)
{
    vector<int>::iterator it;
    visited[st]=1;
    cout<<st<<"\n";
    for(it=V[st].begin();it<V[st].end();it++)
    {
        if(!visited[*it])
        {
          visited[*it]=1;
          dfs(visited,n,V,*it);
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
    int visited[n];

    for (int i=0;i<n;i++)
  {
      visited[i]=0;

  }

    while(true)
    {
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
    dfs(visited,n,V,s);


    return 0;
}

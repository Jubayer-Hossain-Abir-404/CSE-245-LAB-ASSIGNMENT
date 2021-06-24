#include<iostream>
#include<limits>
#include<list>
using namespace std;
list <int> adj[100];

int color[100],prev[100],d[100],f[100],v,a,b,u,time,low[100],p[100];

void build_graph()
{
    cout<< "\nInput\n\n";
    int k=1;
    do
    {
        cout<<"Edge "<<k<<":";
        cin>>a>>b;
        if(a==0&&b==0)
        {
            break;
        }
        else if(a<=0||b<=0)
        {
            cout<<"\nInvalid Input\n";
        }
        else if(a>v||b>v)
        {
            cout<<"\nInvalid Input\n";
        }
        else
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
            k++;
        }
    }
    while(1);
}

void DFS_Visit(int u)
{
    color[u]=1;
    d[u]=++time;
    low[u]=d[u];
    for(list <int>::iterator it =adj[u].begin();it!=adj[u].end();++it)
    {
        if(color[*it]==0)
        {
            prev[*it]=u;
            DFS_Visit(*it);
            if(low[*it]>=d[u]&&p[u]==0)
            {
                int c=0;
                if(prev[u]==-1)
                {
                    for(list <int>::iterator jt =adj[u].begin();it!=adj[u].end();++it)
                    {
                        if(prev[*jt]==u)
                        {
                            c++;
                        }
                    }
                }
                if(prev[u]==-1&&c>1)
                {
                    cout<<endl<<u<< " is an articulation point\n";
                    p[u]=1;
                }
                else if(c==0)
                {
                    cout<<endl<<u<< " is an articulation point\n";
                    p[u]=1;
                }

            }
            if(low[*it]<low[u])
            {
                low[u]=low[*it];
            }
        }
        else if(color[*it]!=0)
        {
            if(d[*it]<low[u])
            {
                low[u]=d[*it];
            }
        }
    }
    color[u]=2;
    f[u]=++time;
}

void DFS()
{
    for(int i=1; i<=v; i++)
    {
        color[i]=0;
        prev[i]=-1;
        p[i]=0;
        d[i]=numeric_limits<int>::max();
        f[i]=numeric_limits<int>::max();
        low[i]=numeric_limits<int>::max();
    }
    time=0;
    for(int i=1; i<=v; i++)
    {
        if(color[i]==0)
        {
            DFS_Visit(i);
        }
    }
}

int main()
{
    cout<< "Input number of vertex:";
    cin>>v;
    build_graph();
    DFS();
}



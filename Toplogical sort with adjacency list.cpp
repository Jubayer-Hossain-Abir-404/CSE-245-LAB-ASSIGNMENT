#include<iostream>
#include<limits>
#include<stack>
#include<list>
using namespace std;
list<int> adj[100];

int color[100],prev[100],d[100],f[100],v,a,b,u,time;
stack <int> s;

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
            k++;
        }
    }
    while(1);
}

void DFS_Visit(int u)
{
    color[u]=1;
    d[u]=++time;
    for(list <int>::iterator it=adj[u].begin();it!=adj[u].end();++it)
    {
        if(color[*it]==0)
        {
            prev[*it]=u;
            DFS_Visit(*it);
        }
    }
    color[u]=2;
    f[u]=++time;
    s.push(u);
}
void DFS()
{
    for(int i=1; i<=v; i++)
    {
        color[i]=0;
        prev[i]=-1;
        d[i]=numeric_limits<int>::max();
        f[i]=numeric_limits<int>::max();
    }
    time=0;
    for(int i=1; i<=v; i++)
    {
        int c=0;
        for(int j=1; j<=v; j++)
        {
            for(list<int>::iterator it=adj[j].begin(); it!=adj[j].end(); it++)
            {
                if(*it==i)
                {
                    c++;
                }
            }
        }
        if(c==0&&color[i]==0)
        {
            DFS_Visit(i);
        }
    }
}

void display()
{
    cout<< "\n\nOutput:\n";
    cout<< "\n\nVertex   : ";
    for(int i=1; i<=v; i++)
    {
        cout<<i<<" ";
    }
    cout<< "\n\nColor    : ";
    for(int i=1; i<=v; i++)
    {
        cout<<color[i]<< " ";
    }
    cout<< "\n\nDis Time  : ";
    for(int i=1; i<=v; i++)
    {
        cout<<d[i]<< " ";
    }
    cout<< "\n\nFin Time : ";
    for(int i=1; i<=v; i++)
    {
        cout<<f[i]<< " ";
    }
    cout<< "\n\nPrevious : ";
    for(int i=1; i<=v; i++)
    {
        cout<<prev[i]<< " ";
    }
    cout<< "\n\nToplological Sort : ";
    while(!s.empty())
    {
        cout<<s.top()<< " ";
        s.pop();
    }
    cout<<"\n";
}

int main()
{
    cout<< "Vertex:";
    cin>>v;
    build_graph();
    DFS();
    display();
}


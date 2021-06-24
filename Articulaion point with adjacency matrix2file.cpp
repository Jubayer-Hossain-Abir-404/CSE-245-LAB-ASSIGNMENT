#include<bits/stdc++.h>
using namespace std;

int adj[100][100]= {0},color[100],prev[100],d[100],f[100],v,p,q,u,time1,low[100],a[100];
ifstream art_input("art_input.txt",ios::in);

void build_graph()
{
    cout<< "\nInput\n\n";
    int k=1;
    do
    {
        cout<<"Edge "<<k<<":";
        art_input>>p>>q;
        cout<<p<< " "<<q<<endl;
        if(p==0&&q==0)
        {
            break;
        }
        else if(p<=0||q<=0)
        {
            cout<<"\nInvalid Input\n";
        }
        else if(p>v||q>v)
        {
            cout<<"\nInvalid Input\n";
        }
        else
        {
            adj[p][q]=1;
            adj[q][p]=1;
            k++;
        }
    }
    while(1);
}

void DFS_Visit(int u)
{
    color[u]=1;
    d[u]=++time1;
    low[u]=d[u];
    for(int i=1; i<=v; i++)
    {
        if(adj[u][i]==1&&color[i]==0)
        {
            prev[i]=u;
            DFS_Visit(i);
            if(low[i]>=d[u]&&a[u]==0)
            {
                int c=0;
                if(prev[u]==-1)
                {
                    for(int j=1; j<=v; j++)
                    {
                        if(adj[u][j]==1&&prev[j]==u)
                        {
                            c++;
                        }
                    }
                }
                if(prev[u]==-1&&c>1)
                {
                    cout<<endl<<u<< " is an articulation point\n";
                    a[u]=1;
                }
                else if(c==0)
                {
                    cout<<endl<<u<< " is an articulation point\n";
                    a[u]=1;
                }

            }
            if(low[i]<low[u])
            {
                low[u]=low[i];
            }
        }
        else if(adj[u][i]==1)
        {
            if(d[i]<low[u])
            {
                low[u]=d[i];
            }
        }
    }
    color[u]=2;
    f[u]=++time1;
}

void DFS()
{
    for(int i=1; i<=v; i++)
    {
        color[i]=0;
        prev[i]=-1;
        a[i]=0;
        d[i]=numeric_limits<int>::max();
        f[i]=numeric_limits<int>::max();
        low[i]=numeric_limits<int>::max();
    }
    time1=0;
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
    if(!art_input)  //If file is not open
    {
        cout<<endl<< "File could not be opened"<<endl;
        exit(EXIT_FAILURE);    //indication of program failure is returned to the operating system.
    }
    cout<< "Input number of vertex:";
    art_input>>v;
    cout<<v<<endl;
    build_graph();
    DFS();
}


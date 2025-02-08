#include<iostream>
using namespace std;
const int MAX_NODE=100;
int child[MAX_NODE];
int parent[MAX_NODE];
void init()
{
    for(int i=0;i<MAX_NODE;i++)
    {
        child[i]=1; 
        parent[i]=i;
    }
}
int findParent(int a)
{
    int node=a;
    while(parent[node]!=node)
    {
        int parent_node=parent[node];
        node=parent_node;
    }
    return node;
}
void join(int a,int b)
{
    int firstParent=findParent(a);
    int secondParent=findParent(b);
    if(child[firstParent]>child[secondParent])
    {
        parent[secondParent]=firstParent;
        child[firstParent]+=child[secondParent];
    }
    else{
        parent[firstParent]=secondParent;
        child[secondParent]+=child[secondParent];
    }
}

int main()
{
    init();
    int queries;
    cin>>queries;
    while(queries--)
    {
        int type;
        cin>>type;
        if(type==1)//find Parent
        {
            int node;
            cin>>node;
            cout<<findParent(node)<<endl;
        }
        else// join two nodes
        {
            int node1,node2;
            cin>>node1>>node2;
            join(node1,node2);
        }
    }

}

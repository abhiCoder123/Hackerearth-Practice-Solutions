/*
   Question : Mancunian And Colored Tree
   Link : https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/mancunian-and-colored-tree/description/

   Problem Statement:

   After a hectic week at work, Mancunian and Liverbird decide to go on a fun weekend camping trip.
   As they were passing through a forest, they stumbled upon a unique tree of N nodes.
   Vertices are numbered from 1 to N.

   Each node of the tree is assigned a color (out of C possible colors).
    Being bored, they decide to work together (for a change) and test their reasoning skills.
    The tree is rooted at vertex 1. For each node, they want to find its closest ancestor having the same color.
   Input format

   The first line contains two integers N and C denoting the number of vertices in the tree and the number of possible colors.
   The second line contains N- 1 integers. The ith integer denotes the parent of the i+1 th vertex.

   The third line contains N integers, denoting the colors of the vertices.
   Each color lies between 1 and C inclusive.
   Output format

   Print N space-separated integers. The ith integer is the vertex number of lowest ancestor of the

   node which has the same color. If there is no such ancestor, print -1 for that node.




*/


// Solution

/*


To solve this problem we can simply start a depth first search from the root.
Till the time we don't come out of this node in our dfs, all nodes we explore
will have the current node as a parent. To remember this, when entering a node
in your depth first search, you can insert that node into a stack representing
the color of that node and pop it out when leaving the node in depth first search.

This way, whenever you enter a node during your dfs, the node at the top of a stack
for a particular color is the most recent ancestor of that particular colour for
the current node.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll N=0,C=0,col[100005],ans[100005];
vector<ll> adj[100005];         // Since Tree is a special case of graph , it is represented as an array of vector using STL
stack<ll> st[100005];   //Array of stack... "ith stack" represent a color and its members are the nodes having that color

void dfs(int v){
  if(st[col[v]].empty()){      //If there are no ancestor nodes having color as col[v] then set ans[v]=-1
    ans[v]=-1;
  }
  else{
    ans[v]=st[col[v]].top(); // closest ancestor having same color found
  }
  st[col[v]].push(v);      // Push the current node onto the stack and do a dfs for its children

  for(ll i=0;i<(ll)adj[v].size();i++){
    dfs(adj[v][i]);
  }
  st[col[v]].pop();   // Since all the children of current node are visited then it cannot be the ancestor node having same color
                      //Therefore it is popped out of the stack
}
int main()
{
  cin>>N>>C;                   //Number of nodes and number of colors
  ll parent_node=0;
  for(ll i=2;i<=N;i++){
    cin>>parent_node;           // ith vertex is parent of i+1 th node , therefore loop is run from "2" for simplicity
    adj[parent_node].push_back(i); //Constructing the tree
  }
  for(ll i=1;i<=N;i++)
    cin>>col[i];         //Accepting the color of various nodes

  dfs(1);
  for(ll i=1;i<=N;i++)       
    cout<<ans[i]<<" ";
  return 0;
}

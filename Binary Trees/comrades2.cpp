/*
Quesion : Comrades II

Link : https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/comrades-ii-6/

Problem statement :
It’s the year 2552, the Humans just won a war against a very powerful alien race
that had invaded our solar system. The Human army is in celebration mode!
The army has n soldiers. The soldiers are numbers from 1 to n. The army has a
superiority hierarchy. Every soldier has one immediate superior. The superior of
a superior of a soldier is also a superior to that soldier. So, a soldier may have
one or more superiors but only one immediate superior.
Every soldier has to congratulate every other soldier. For a pair of soldiers if
one of them is the superior of the other, they will shake hands. Otherwise, they
will bump their fists.
You are given the list of immediate superior of all soldiers. Your job is to tell
how many handshakes and fist bumps will be there.
NOTE: Among all soldiers there is one soldier who does not have any superior.
He is the commander of the whole army.

Input:
The first line of the input contains t, the number of test cases.
The first line of each test case contains n, the number of soldiers. The next line contains n space separated integers. The ith integer represents the immediate superior of the ith soldier.
The immediate superior of the commander of the army will be '0'.

Output:
Output two space separated integers, the number of handshakes and the number of fist bumps.

Constraints:
1<=t<=10
1<=n<=100000

It is guaranteed that the commander of the army is a superior of all soldiers.
*/




#include<bits/stdc++.h>
using namespace std;
#define ll long long


 ll hand_shakes=0; //Global Variable to store number of handshakes for each test case

void dfs(ll v,ll ht,vector<ll> adj[]){ // A function to do depth firsr search and determine number of handshakes

   /*
   This is the heart of the program.
   Explanation for determining the number of handshakes :
    A soldier or node of the tree will do handshakes with all its superiors
    ie., number of edges from root node to the given soldier of node
    which is the distance(counting edges) from root node to that node = ht  ... for root node ht = 0 (inital value)
    for each recursive call ht is incremented by 1 and for each node... ht is added to the total handshakes
   */
    hand_shakes+=ht;
  for(ll i=0;i<(ll)adj[v].size();i++){
    dfs(adj[v][i],ht+1,adj);
  }

}
int main()
{
    ll T=0,N=0;
  cin>>T;
  while(T--){
      cin>>N;
      vector<ll> adj[100005];     // Stores the given tree ... (Note it may or may not be  a binary tree)
  ll parent_node=0;
  for(ll i=1;i<=N;i++){
    cin>>parent_node;
    adj[parent_node].push_back(i);       // Building the tree
  }


  dfs(adj[0][0],0,adj);
 ll total=(N*(N-1))/2;                  // Considering all edges between the nodes ... ie., a complete graph
 ll bumps=total-hand_shakes;             // Soldiers will bump fists with the remaining number of soldiers which is total-hand_shakes
 cout<<hand_shakes<<" "<<bumps<<endl;        //Printing the answer
 ans=0;
  }
  return 0;
}

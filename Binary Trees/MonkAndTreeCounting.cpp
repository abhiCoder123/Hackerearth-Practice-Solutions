/*
Question : Monk and Tree counting
(This Question is tough and requires very clean implementation and logic)

Link :https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/tree-counting-3/
*/


/*
Solution :
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ans=0;
vector<ll> G[100005];      // All operations will be done on this newly constructed graph
                           // Here G[i] will contain all descendants of  node "i"
ll arr[100005];

void dfs(ll parent,ll v,vector<ll> adj[]){          //Dfs to construct G
    for(ll i=0;i<(ll)adj[v].size();i++){
        G[parent].push_back(adj[v][i]);
        dfs(parent,adj[v][i],adj);
    }
}

bool compare(ll i, ll j){                 // To sort each vector G[i] according to arr[i]
    return arr[i]<arr[j];
}

int main(){
    ll N=0,K=0;
    cin>>N>>K;

    vector<ll> adj[100005];
    for(ll i=1;i<=N;i++)
        cin>>arr[i];
    ll parent=0;
    for(ll i=2;i<=N;i++){           //Constructing the tree
        cin>>parent;
        adj[parent].push_back(i);
    }
    for(ll i=1;i<=N;i++)
        dfs(i,i,adj);                // Constructing Graph G

   /* for(ll i=1;i<=N;i++){                             To check whether G and adj are well constructed
        cout<<i<<" ";
        for(ll j=0;j<(ll)adj[i].size();j++)
            cout<<"-->"<<adj[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"The actual graph\n";
      for(ll i=1;i<=N;i++){
          cout<<i << " ";
        for(ll j=0;j<(ll)adj[i].size();j++)
            cout<<"-->"<<arr[adj[i][j]];
        cout<<endl;
    }
*/
  //  cout<<"Graph G\n";
    for(ll i=1;i<=N;i++){                                      //Sorting each vector of G
        sort(G[i].begin(),G[i].end(),compare);
    }

/*
    for(ll i=1;i<=N;i++){
          cout<<i << " ";
        for(ll j=0;j<(ll)G[i].size();j++)
            cout<<"-->"<<arr[G[i][j]];
        cout<<endl;
    }
    */


    for(ll i=1;i<=N;i++){                             //This is the main loop
        ll n1=arr[i];                              // choosing the 1st element of the triplet
        if(G[i].size()>=1){
        for(ll j=0;j<G[i].size()-1;j++){          //Choosing the 2nd element of the triplet
            for(ll p=j+1;p<G[i].size();p++){          //Choosing 3rd element of the triplet
                if(n1+arr[G[i][j]]+arr[G[i][p]]>=K)     //Checking if the triplet satisfies the condition
                ans++;                               //incremeneting count of triplets
            }
        }
      }

    }

    cout<<ans<<endl; //Printing answer

    return 0;
}

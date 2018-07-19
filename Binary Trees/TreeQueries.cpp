/*
Question : Tree Queries
Link : https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/tree-queries-45/

There is a complete Binary tree in which there are N nodes. Each vertex of the tree is assigned a value.
You are given the values of all nodes in level order traversal of the binary tree (from left to right).
You are given three types of queries.
1 X  LV  Find the value of Xth node from left on the level LV.
2  L R  Find the the sum of values of nodes from level L to R (L and R are inclusive).
3  X  LV  VAL Update the value of Xth node from left which is at level LV to VAL.
Note: Root is at level 1.

INPUT
In the first line you are given two integers N, Q.
In the next line you are given an array A where the ith value denotes the value of ith node.
In the next Q lines you are given one of the three queries.
It is guaranteed that there exists at least one query of type 1 or 2.
Also it is guaranteed all given queries are valid.

OUTPUT
For each query of 1st and 2nd type print the required value.

*/


/*
Solution

Since the tree is a complete binary tree and Level order travesal is given , therefore if
we store it in an array it will perfectly fit the array representation of a binary tree ie.,
for parent "i" left child =2*i  and right child=2*i+1

Also number of levels = log2(N) + 1;


*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N=0,Q=0;
    cin>>N>>Q;
    ll arr[2000005],sum[100005]; // arr to store the binary tree and sum to store sum of different levels
    for(ll i=1;i<=N;i++)
        cin>>arr[i];

    ll level=(ll)(log(N) /log(2));
    for(ll j=0;j<=level;j++){                 // Here "j" denotes the current level of binary tree
    for(ll i=(1<<j);i<(1<<(j+1));i++){      // Iterating through a particular level of the binary tree
     sum[j]+=arr[i];                        // For a particular level , starting node is 2^j and number of nodes is also 2^j
     //Storing sum of a particular level
    }
    }


    ll type=0,X=0,LV=0,val=0,L=0,R=0;
    while(Q--){
        cin>>type;          // Type of query
        if(type==1){
            cin>>X>>LV;
            cout<<arr[(ll)(pow(2,LV-1)+X-1)]<<endl;   //Since my solution considers level of root as zero... LV-1 is taken instead of LV
            // 2^LV-1 is the index of 1st node of that level and we are adding X -1 as offset to get the Xth nodes index of that level
        }
        else if(type==2){
            cin>>L>>R;
            ll temp=0;
            for(ll t=L-1;t<R;t++)     // Since 1st level is "0" we iterate from L-1 to R-1
                temp+=sum[t];       // Storing sum of all levels
            cout<<temp<<endl;
        }
        else{
            cin>>X>>LV>>val;
            ll tempo=arr[(ll)(pow(2,LV-1)+X-1)];          // To store the current value of Xth Node
            arr[(ll)(pow(2,LV-1)+X-1)] =val;            // Updating new value to Xth Node
            sum[LV-1]=sum[LV-1]+val-tempo;             //Updating sum of level LV by subtracting previous value and adding new value
        }

    }

    return 0;
}

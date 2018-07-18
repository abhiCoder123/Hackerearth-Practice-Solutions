/*
Question : Mirror Image

Link :
https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/mirror-image-2/description/

Problem Statement :

You are given a binary tree rooted at 1. You have to find the mirror image of any node qi about node 1.
If it doesn't exist then print -1.
Input:
First line of input is N and Q.
Next N-1 line consists of two integers and one character first of whose is parent node ,
second is child node and character "L" representing Left child and "R" representing right child.
Next Q lines represents qi.
Output:

For each qi print it mirror node if it exists else print -1.
NOTE: 1 is mirror image of itself.
Constraints:
1 <= N <= 103
1<= Q <= 103
*/

//Solution :

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N=0,Q=0;
    cin>>N>>Q; // N is number of nodes in the tree and Q is number of queries

    /*
    The idea is to store the binary tree in the form of an array (root index =1 )
    if index of parent is "i"  then index of left child=2*i and right child=2*i+1
    The unordered_map stores the node as Key and the index of the node in the array as value
    This helps to build the tree easily
    */
    unordered_map<int,int> mp;             //Stores node of the tree as key and index of node in array as value
    int arr[100000];       // Array based implementation of tree
    arr[1]=1;             //Root of the tree is 1 stored at index 1
    int parent=0,child=0;  // Variables to store parent node and child node during execution of the program
    char ch;              // To determine whether given child is left or right
    mp[1]=1;              // Initialize the map with root node =1 as Key and its index "1" as value
    int par_index=0,child_index=0;         // Variables to store index of parent and child during execution of program
    for(int t=1;t<=N-1;t++){
        cin>>parent>>child>>ch;
        if(ch=='L'){                          //left child
            par_index=mp[parent];            //Get the value of parent index from the map
            child_index=2*par_index;          // compute the child index in the array
            arr[child_index]=child;          //Store the child node

            mp[child]=child_index;         //store the child node as key and value as its index

        }
        else{                                   //Right Child

            par_index=mp[parent];                 //Get the value of parent index from the map
            child_index=2*par_index+1;             // compute the child index in the array
            arr[child_index]=child;             //Store the child node

            mp[child]=child_index;              //store the child node as key and value as its index

        }

    }
    int q=0;
    while(Q--){                               // Loop for all queries
        cin>>q;
      /*
      This is Tricky !
      Process to determine the mirror image :
      Step 1 : Determine the index of given node in the query using the unordered_map ie.,   mp [q]
      Step 2 : Determine the level of the node in the tree (Consider Level of root = 0 ) which is  log2(mp[q]) = log (mp[q]) / log (2);
              Let this be idx
      Step 3 : The number of levels before idx is...   " idx" itself considering root level as 0.
                Therefore number of nodes before that level = 2^0 +2^1+2^2+ .... + 2^ (idx-1)  = (2^idx) -1 ;
              Therefore starting index of that level = 2^idx
      Step 4 : Now , starting index = 2^ idx  and number of nodes also equal to 2 ^ idx (Since number of nodes at "j" level is 2^j)
              and we know the index of given node = mp[q] ;
      Step 5 : This boils down to determining the "k-th index " from the end if we know the kth index from the begining ;
               Therefore index of mirror image =  3 *(2^idx)  - mp[q] -1 =ans_idx
      Step 6 : answer is arr[ans_idx] if it is non zero else answer is -1

      */

     int idx=(int)(log(mp[q])/log (2 ));
     int ans_idx=3*pow(2,idx) -mp[q] -1 ;
     if(arr[ans_idx])
        cout<<arr[ans_idx]<<endl;
    else
    cout<<-1<<endl;
    }



return 0;
}

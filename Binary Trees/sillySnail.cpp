/*
Question : The Silly Snail

Link :https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/the-silly-snail-3/description/
*/

/*
Solution :
The answer is basically the preorder traversal of the binary tree
Constructing The Binary tree is a crucuial Step
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{       //Node of a binary Tree
    ll data;
    struct Node* left;
    struct Node* right;
};
struct Node* create(ll data){         //Function to create a new Node of a binary tree
    struct Node* temp=(struct Node*)(malloc(sizeof(struct Node)));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

void preorder(struct Node* root){      //Function to do preorder traversal of a binary tree
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    if(root->left)
    preorder(root->left);
    if(root->right)
    preorder(root->right);
}
void deleteTree(struct Node* node)        //Clearing the tree after every iteration is a good practice
{
    if (node == NULL) return;

    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}
int main(){
    ll T=0,N=0;
    cin>>T;
    while(T--){
        cin>>N;

        struct Node* root=NULL;
        root=create(1);            //Root of the binary tree
        create(1);
        unordered_map<ll,struct Node*> mp;  //this stores data of node as Key and Value as pointer of that node
                                            //THe map helps in constant time access to the pointer of the node and helps in building the tree
        mp.clear();
        mp[1]=root;         // Initialising the root of the tree as 1
        ll parent=0,left_child=0,right_child=0;
        struct Node* left_node=NULL;
        struct Node* right_node=NULL;
        struct Node* parent_node=NULL;
       for(ll i=1;i<=N;i++){                               //Constructing the tree
            cin>>parent>>left_child>>right_child;
            parent_node=mp[parent];                       //Getting the pointer to parent node , to which the children will be attached
            if(left_child){                                 // If left child exists
                left_node=create(left_child);             //creating left child
                parent_node->left=left_node;               //Linking left child to parent
                mp[left_child]=left_node;                //Storing pointer of left child to map
            }
                if(right_child){                      //^^ Similar explanation for right child
                right_node=create(right_child);
                parent_node->right=right_node;
                mp[right_child]=right_node;
            }
        }
        preorder(root);                //preorder traversal of tree is the answer
        cout<<endl;
        deleteTree(root);          //Clearing the tree and map ... Good practice
        mp.clear();
    }
    return 0;
}

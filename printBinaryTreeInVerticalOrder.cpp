/*
Print a Binary Tree in Vertical Order (Map based Method)
Difficulty Level : Medium

Test Case 1:-
given root node
           1
        /    \ 
       2      3
      / \   /   \
     4   5  6   7
               /  \ 
              8   9
Output:
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9

IDEA :-
We need to check the Horizontal Distances from the root for all nodes.
If two nodes have the same Horizontal Distance (HD), then they are on the
same vertical line. The idea of HD is simple. HD for root is 0, a right edge
(edge connecting to right subtree) is considered as +1 horizontal distance
and a left edge is considered as -1 horizontal distance. For example, in the
above tree, HD for Node 4 is at -2, HD for Node 2 is -1, HD for 5 and 6 is 0
and HD for node 7 is +2.
We can do preorder traversal of the given Binary Tree.
While traversing the tree, we can recursively calculate HDs.
We initially pass the horizontal distance as 0 for root. For left subtree,
we pass the Horizontal Distance as Horizontal distance of root minus 1.
For right subtree, we pass the Horizontal Distance as Horizontal Distance of root plus 1.
For every HD value, we maintain a list of nodes in a hash map. Whenever we see a
node in traversal, we go to the hash map entry and add the node to the hash map
using HD as a key in a map.
*/

#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

void preorder(Node* root,int hd,map<int,vector<int>> &mp){
    if(root == NULL){
        return;
    }

    // root
    mp[hd].push_back(root->data);
    // left
    preorder(root->left,hd-1,mp);
    // right
    preorder(root->right,hd+1,mp);


}

void printVerticalOrder(Node* root){

    // hash map
    map<int,vector<int>> mp;
    int hd = 0;

    preorder(root,hd,mp);

    // printing

    map<int,vector<int>> :: iterator it;
    for(it = mp.begin();it != mp.end();it++){
        for(int  i =0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }


}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    cout << "Vertical order traversal is n"<<endl;
    printVerticalOrder(root);
    return 0;
}
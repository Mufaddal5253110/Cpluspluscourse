/*
-------------Binary Search Tree (BST)----------
1. Insertion :- data<root insert at left else at right
2. InorderTraversal :- print left , than root, than right :: Inorder gives sorted order of BST
3. Searching:- TimeComplexity : O(log(n)) , Worst Case TC :- O(height of tree)
4. BST from PreOrder
*/

#include <iostream>
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

Node *insertBST(Node *root, int data)
{

    if (root == NULL)
    {
        return new Node(data);
    }

    if (data > root->data)
    {
        // insert at right
        root->right = insertBST(root->right, data);
    }
    else
    {
        // insert at left
        root->left = insertBST(root->left, data);
    }

    return root;
}

bool searchInBST(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }

    if (data > root->data)
    {
        // search in right
        return searchInBST(root->right, data);
    }
    else
    {
        // search in left
        return searchInBST(root->left, data);
    }
}

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteInBST(Node *root, int data)
{
    if (root == NULL)
    {
        cout << "Element " << data << " Not Found";
        return NULL;
    }
    if (data > root->data)
    {
        // search in right
        root->right = deleteInBST(root->right, data);
    }
    else if (data < root->data)
    {
        // seacrh in left
        root->left = deleteInBST(root->left, data);
    }
    else if (root->data == data)
    {
        // element found now delete it

        // case 1 : Leaf Node
        if (root->left == NULL && root->right == NULL)
        {

            return NULL;
        }

        // case 2 : having only one child or no child
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        // case 3 : having both child , find successor and replace it with data
        if (root->left != NULL && root->right != NULL)
        {
            Node *temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = deleteInBST(root->right, temp->data);
        }

        return root;
    }
}

Node *preOrderToBST(int preorder[], int start, int end)
{

    // Base Condition
    if (start > end)
    {
        return NULL;
    }

    // Step 1: Make node of index start
    Node *root = new Node(preorder[start]);

    // Step 2: Find index of element greater than root data in preorder array
    int i;
    for (i = start; i <= end; i++)
    {
        if (preorder[i] > root->data)
        {
            break;
        }
    }

    // Step 3 : recursively call for left and right nodes
    root->left = preOrderToBST(preorder, start + 1, i - 1);
    root->right = preOrderToBST(preorder, i, end);

    // return current Node
    return root;
}

bool isBSTValid(Node *root, Node *min, Node *max)
{
    /*
    Logic: Node > Max of left && Node < Min of right
    OR
    Node > min allowed
    Node < max allowed
    */

    if (root == NULL)
    {
        return true;
    }

    if ((min != NULL && root->data <= min->data) || (max != NULL && root->data >= max->data))
    {
        return false;
    }

    return isBSTValid(root->left, min, root) && isBSTValid(root->right, root, max);
}

Node* sortedArrayToBST(int array[],int start,int end){
    if(start>end){
        return NULL;
    }

    int mid = (start+end)/2;

    Node* root = new Node(array[mid]);
    root->left = sortedArrayToBST(array,start,(mid)-1);
    root->right = sortedArrayToBST(array,(mid)+1,end);

    return root;

}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    /*
            5
          /   \
        1       7
          \    /  \
            3 6      8
           / \
          2    4  
    
    */

    // Creating BST
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 6);
    insertBST(root, 8);

    // InOrder Traversal
    cout << "\nInOrder Traversal" << endl;
    inorderTraversal(root);

    // // Searching
    // cout << "\n"
    //      << searchInBST(root, 7) <<endl;

    // Deleting
    Node *root2 = deleteInBST(root, 7);
    cout << "\nAfter Deletion :: Check By printing InOrder" << endl;
    inorderTraversal(root2);

    // PreOrder To BST
    int preorder[] = {15, 10, 8, 12, 20, 16, 25};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    Node *root3 = preOrderToBST(preorder, 0, n - 1);
    cout << "\nPreOrder To BST :: Check By printing InOrder" << endl;
    inorderTraversal(root3);

    // Check For Valid BST
    if (isBSTValid(root3, NULL, NULL))
    {
        cout << "\nBST is Valid";
    }
    else
    {
        cout << "\nBST is InValid";
    }

    // Sorted Array To BST
    int array[] = {1,2,3,4,5,6,7,8};
    int n2 = sizeof(array) / sizeof(array[0]);
    Node* root4 = sortedArrayToBST(array,0,n2-1);
    cout << "\nSorted Array To BST :: Check By printing InOrder" << endl;
    inorderTraversal(root4);

    return 0;
}
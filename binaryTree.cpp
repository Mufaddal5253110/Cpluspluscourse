/*
Binary Tree : Elements are not linear but stored in hirechical manner
1. Pre-Order Traversal : root,left,right
3. In-Order Traversal : left,root,right
3. Post-Order Traversal : left,right,root
4. Build Tree using preorder and inorder array
5. Build Tree using postorder and inorder array
6. Level Order Traversal
7. Sum of Nodes at K-th level
8. Number of Nodes in binary tree



*/

#include <iostream>
#include <queue>

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

void preOrderTraversal(Node *root)
{
    // Base condition
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    // Base condition
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // Base condition
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int search(int inorder[], int start, int end, int elem)
{
    for (int i = start; i <= end; i++)
    {
        if (elem == inorder[i])
        {
            return i;
        }
    }
    return -1;
}

Node *buildTreeWithPreIn(int preorder[], int inorder[], int start, int end)
{

    static int indx = 0;
    int curr = preorder[indx];
    indx++;
    Node *root = new Node(curr);
    if (start == end)
    {
        return root;
    }
    int pos = search(inorder, start, end, curr);
    root->left = buildTreeWithPreIn(preorder, inorder, start, pos - 1);
    root->right = buildTreeWithPreIn(preorder, inorder, pos + 1, end);

    return root;
}

Node *buildTreeWithPostIn(int postorder[], int inorder[], int start, int end)
{

    static int indx = 6;
    int curr = postorder[indx];
    indx--;
    Node *root = new Node(curr);
    if (start == end)
    {
        return root;
    }
    int pos = search(inorder, start, end, curr);
    root->right = buildTreeWithPostIn(postorder, inorder, pos + 1, end);
    root->left = buildTreeWithPostIn(postorder, inorder, start, pos - 1);

    return root;
}

void levelOrderTraversal(Node *root)
{
    static queue<Node *> que;

    if (root == NULL)
    {
        return;
    }

    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        Node *node = que.front();
        que.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
        }
        else if (!que.empty())
        {
            que.push(NULL);
        }
    }
}

int sumOfNodeAtKthLvl(Node *root, int lvl)
{
    static queue<Node *> que;
    int ans = 0;
    int k = 0;

    if (root == NULL)
    {
        return ans;
    }
    else if (lvl == 1)
    {
        return root->data;
    }

    que.push(root);
    que.push(NULL);
    // k++;

    while (!que.empty() && k < lvl)
    {
        Node *node = que.front();
        que.pop();
        if (node != NULL)
        {
            if (k == lvl - 1)
            {
                ans += node->data;
            }
            // cout << node->data << " ";
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
        }
        else if (!que.empty())
        {
            que.push(NULL);
            k++;
        }
    }
    return ans;
}

int countNodes(Node *root)
{
    // Base condition
    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main()
{

    /*
        1
     2       3
  4    5    6  7  
    
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Pre-Order Traversal" << endl;
    preOrderTraversal(root);
    cout << "\nIn-Order Traversal" << endl;
    inOrderTraversal(root);
    cout << "\nPost-Order Traversal" << endl;
    postOrderTraversal(root);

    int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
    int inOrder[] = {4, 2, 5, 1, 6, 3, 7};
    int postOrder[] = {4, 5, 2, 6, 7, 3, 1};

    // Building Tree
    Node *root1 = buildTreeWithPreIn(preOrder, inOrder, 0, 6);
    // Checking Build Tree by printing
    cout << "\nChecking Build Tree by Pre-Order Traversal" << endl;
    preOrderTraversal(root1);

    // Building Tree
    Node *root2 = buildTreeWithPostIn(postOrder, inOrder, 0, 6);
    // Checking Build Tree by printing
    cout << "\nChecking Build Tree by Pre-Order Traversal" << endl;
    preOrderTraversal(root2);

    // Level Order Traversal
    cout << "\nLevel Order Traversal" << endl;
    levelOrderTraversal(root);

    // Sum At Kth
    cout << "\nSum At Kth" << endl
         << sumOfNodeAtKthLvl(root, 3);

    // Count Nodes
    cout<<"\nCount : "<<countNodes(root);

    return 0;
}
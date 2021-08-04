/*
Binary Tree : Elements are not linear but stored in hirechical manner
1. Pre-Order Traversal : root,left,right
3. In-Order Traversal : left,root,right
3. Post-Order Traversal : left,right,root
4. Build Tree using preorder and inorder array
5. Build Tree using postorder and inorder array
6. Level Order Traversal :- Using queue
7. Sum of Nodes at K-th level
8. Number of Nodes in binary tree :- O(n)
9. Sum of  All Nodes in binary tree :- O(n)
10. Height of binary tree :- O(n)
11. Diameter of binary tree :- O(n^2) , O(n)
12. Sum Replacement : root data = left child + right child + root data :- O(n)
13. Check For binary tree is balanced or not : |leftheight -rightheight| <= 1 :- O(n^2)
14. Right View : using lvl order traversal
15. Left View : using lvl order traversal
16. Lowest Common Ancestor (LCA) - 2 methods
17. Distance between two node :- Find LCA , then distanceBetween(LCA+n1) + distanceBetween(LCA+n2)
18. Flatten Tree





*/

#include <iostream>
#include <queue>
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

int sumOfNodes(Node *root)
{
    // Base condition
    if (root == NULL)
    {
        return 0;
    }
    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
}

int heightOfTree(Node *root)
{
    // Base condition
    if (root == NULL)
    {
        return 0;
    }
    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

int diameterOfTree(Node *root) //O(n^2)
{
    // Base condition
    if (root == NULL)
    {
        return 0;
    }
    int lheight = heightOfTree(root->left);
    int rheight = heightOfTree(root->right);
    int currentDia = lheight + rheight + 1;

    int lDiameter = diameterOfTree(root->left);
    int rDiameter = diameterOfTree(root->right);

    return max(currentDia, max(lDiameter, rDiameter));
}

int simpleDiameterOfTree(Node *root, int *height) //O(n)
{

    // Base condition
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    // int lheight = heightOfTree(root->left);
    // int rheight = heightOfTree(root->right);

    int lDiameter = simpleDiameterOfTree(root->left, &lh);
    int rDiameter = simpleDiameterOfTree(root->right, &rh);
    int currentDia = lh + rh + 1;

    *height = max(lh, rh) + 1;

    return max(currentDia, max(lDiameter, rDiameter));
}

Node *sumReplacement(Node *root)
{
    // Base condition
    if (root == NULL)
    {
        return root;
    }
    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }

    if (root->right != NULL)
    {
        root->data += root->right->data;
    }

    return root;
}

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->left) + getHeight(root->right) + 1;
}

void isBalanced(Node *root) // O(n^2)
{
    if (root == NULL)
    {
        return;
    }
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    if (abs(lh - rh) <= 1)
    {
        cout << "\nBinary Tree is Balanaced";
    }
    else
    {
        cout << "\nBinary Tree is Not Balanced";
    }
}

void rightView(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node)
        {

            if (q.front() == NULL)
            {
                cout << node->data << " ";
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

void leftView(Node *root)
{
    queue<Node *> q;

    q.push(root);
    // q.push(NULL);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *node = q.front();
            q.pop();

            if (i == 1)
            {
                cout << node->data << " ";
            }

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
    }
}

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findDistance(Node *root, int n, int dis)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == n)
    {
        return dis;
    }

    int leftdist = findDistance(root->left, n, dis + 1);
    if (leftdist != -1)
    {
        return leftdist;
    }

    return findDistance(root->right, n, dis + 1);
}

int distanceBetween(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);

    return d1 + d2;
}

bool getPath(Node *root, int n1, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == n1)
    {
        return true;
    }
    if (getPath(root->left, n1, path) || getPath(root->right, n1, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA2(Node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (getPath(root, n1, path1) && getPath(root, n2, path2))
    {
        int pc;
        for (pc = 0; pc < path1.size() && pc < path2.size(); pc++)
        {
            if (path1[pc] != path2[pc])
            {
                break;
            }
        }
        return path1[pc - 1];
    }
    return -1;
}

void flattenTree(Node *root)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        flattenTree(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        // calculating left tail which is in right now
        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }

        // Attaching right subtree to left subtrees tail which we get now
        t->right = temp;
    }

    flattenTree(root->right);
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
    cout << "\nCount : " << countNodes(root);

    // Sum Of Nodes
    cout << "\nTotal Sum : " << sumOfNodes(root);

    // Height Of tree
    cout << "\nHeight of tree : " << heightOfTree(root);

    // Diameter Of tree
    cout << "\nDiameter of tree : " << diameterOfTree(root);

    // SImple Diameter Of tree
    int height = 0;
    cout << "\nSimple Diameter of tree : " << simpleDiameterOfTree(root, &height);

    // SImple Diameter Of tree
    // Node *root3 = sumReplacement(root);
    // cout << "\nAfter Some replacement preorder form is : ";
    // preOrderTraversal(root3);

    // Is Tree Balanced?
    isBalanced(root);

    // Right View
    cout << "\nRight View : ";
    rightView(root);

    // Left View
    cout << "\nLeft View : ";
    leftView(root);

    // LCA Of Two number
    cout << "\nLCA 4,7 : " << LCA(root, 4, 7)->data;

    // LCA Of Two number Method 2
    cout << "\nLCA2 4,5 : " << LCA2(root, 4, 5);

    // distance between Two number
    cout << "\nDistance Between 4,7 : " << distanceBetween(root, 4, 7);

    // Flattening Tree
    flattenTree(root);
    cout<<"\nAfter Flatten Inorder is :";
    inOrderTraversal(root);

    return 0;
}
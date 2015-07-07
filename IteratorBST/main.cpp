// Task:
// Given a binary tree, implement an iterator that will iterate through its elements.

#include <iostream>
using namespace std;

struct Node
{
    char value;
    Node *left = 0;
    Node *right = 0;
};


void binaryTreeInorderTraversal(struct Node *n)
{
    if(n)
    {
        binaryTreeInorderTraversal(n->left);
        cout << n->value << " ";
        binaryTreeInorderTraversal(n->right);
    }
}

void binaryTreePreOrderTraversal(struct Node *n)
{
    if(n)
    {
        cout << n->value << " ";
        binaryTreePreOrderTraversal(n->left);
        binaryTreePreOrderTraversal(n->right);
    }
}

void binaryTreePostorderTraversal(struct Node *n)
{
    if(n)
    {
        binaryTreePostorderTraversal(n->left);
        binaryTreePostorderTraversal(n->right);
        cout << n->value << " ";
    }
}

int main()
{
 Node a,b,c,d,e,f;

 a.value = 'a';
 a.left = &b;
 a.right = &c;

 b.value = 'b';
 b.left = &d;
 b.right = &e;

 c.value = 'c';
 c.right = &f;

 d.value = 'd';
 e.value = 'e';
 f.value = 'f';

 binaryTreeInorderTraversal(&a);
 cout << endl;
 binaryTreePreOrderTraversal(&a);
 cout << endl;
 binaryTreePostorderTraversal(&a);
}

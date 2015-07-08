// Task:
// Given a binary tree, implement an iterator that will iterate through its elements.

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    char value;
    Node *left = 0;
    Node *right = 0;
};

class Iterator
{
public:
    explicit Iterator(Node *ptr): ptr_(ptr)
    {
        if(ptr_)
        {
            if(ptr_->left) q.push(ptr_->left);
            if(ptr_->right) q.push(ptr_->right);
        }
    }

    bool operator != (const Iterator &i) {return i.ptr_ != ptr_;}
    bool operator == (const Iterator &i) {return i.ptr_ == ptr_;}

    Node& operator *() {return *ptr_;}
    Node* operator ->() {return ptr_;}

    Iterator operator ++ ()
    {
        if(ptr_ && !q.empty())
        {
            ptr_ = q.front();
            q.pop();

            if(ptr_->left) q.push(ptr_->left);
            if(ptr_->right) q.push(ptr_->right);
        }
        else ptr_ = nullptr;

        return *this;
    }
private:
    queue<Node*> q;
    Node* ptr_;
};

class Tree
{
public:
    explicit Tree (Node *r):root(r), iter(Iterator(root)){}
    Iterator begin() {return Iterator(root);}
    Iterator end() {return Iterator(nullptr);}
private:
    Node *root;
    Iterator iter;
};

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

    Tree t(&a);

    for (Iterator i = t.begin(); i != t.end(); ++i)
        cout << (*i).value << " ";

    return 0;
}

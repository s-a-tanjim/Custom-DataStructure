#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left, *right, *parent;
    Node(int x)
    {
        val = x;
        left = right = NULL;
        parent = NULL;
    }
};

class BST
{
    Node *root;

    void inorder(Node *r)
    {
        if (r == NULL)
            return;
        inorder(r->left);
        cout << r->val << "   ";
        inorder(r->right);
    }
    void preorder(Node *r)
    {
        if (r == NULL)
            return;
        cout << r->val << "   ";
        inorder(r->left);
        inorder(r->right);
    }
    void postorder(Node *r)
    {
        if (r == NULL)
            return;
        inorder(r->left);
        inorder(r->right);
        cout << r->val << "   ";
    }
    Node *insert(Node *r, int val, Node *parent)
    {
        if (r == NULL)
        {
            Node *ptr = new Node(val);
            ptr->parent = parent;
            return ptr;
        }
        else
        {
            if (r->val > val)
            {
                r->left = insert(r->left, val, r);
            }
            else if (r->val < val)
            {
                r->right = insert(r->right, val, r);
            }
            return r;
        }
    }

    void Delete(int val)
    {
        Node *ptr = search(val);
        if (ptr->left == NULL)
            transplant(ptr, ptr->right);
        else if (ptr->right == NULL)
            transplant(ptr, ptr->left);
        else
        {
            Node *y = findMin(ptr->right);
            if (y->parent != ptr)
            {
                transplant(y, y->right);
                y->right = ptr->right;
                y->right->parent = y;
            }
            transplant(ptr, y);
            y->left = ptr->left;
            y->left->parent = y;
        }
    }

    void transplant(Node *u, Node *v)
    {
        if (u->parent == NULL)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        if (v != NULL)
            v->parent = u->parent;
    }

public:
    BST()
    {
        root = NULL;
    }
    void inorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty!\n";
            return;
        }
        inorder(root);
    }
    void preorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty!\n";
            return;
        }
        preorder(root);
    }
    void postorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty!\n";
            return;
        }
        postorder(root);
    }
    void insert(int val)
    {
        root = insert(root, val, NULL);
    }

    void insert_(int val)
    {
        Node *x = root, *y = NULL;
        while (x != NULL)
        {
            y = x;
            if (x->val > val)
                x = x->left;
            else if (x->val < val)
                x = x->right;
        }
        Node *temp = new Node(val);
        temp->parent = y;
        if (y == NULL)
            root = temp;
        else if (y->val > val)
            y->left = temp;
        else if (y->val < val)
            y->right = temp;
    }

    Node *search(int val)
    {
        Node *x = root;
        while (x != NULL)
        {
            if (x->val == val)
            {
                return x;
            }
            if (x->val > val)
                x = x->left;
            else if (x->val < val)
                x = x->right;
        }
        return NULL;
    }

    Node *findMin(Node *x)
    {
        //if(x==NULL) return NULL;
        while (x->left != NULL)
            x = x->left;
        return x;
    }
};

int main()
{
    BST x;
    x.insert(31);
    x.insert(12);
    x.insert(21);
    x.insert(52);
    x.insert(43);
    x.insert(82);
    x.insert(71);
    x.insert(62);
    x.insert(93);
    x.inorder();

    Node *p = x.search(93);
    if (p != NULL)
        cout << "##: " << p->val;
    else
        cout << "Not found!\n";

    return 0;
}

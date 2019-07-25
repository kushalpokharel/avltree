#include "avl.h"
#include<iostream>
#include<string>
using namespace std;

Avl::Avl()
{
    available=0;
    total=0;
    root=NULL;
}

struct node* Avl:: maketree(int b)
{
    struct node* p=new node;
    if(available==0)
        root=p;
    p->data=b;
    p-> left=NULL;
    p-> right=NULL;
    available++;
    total++;
    return p;
}

void Avl:: add(std::string a)
{
    int n=convert(a);
    auxadd(n,root);
    display();
    //cout<<"root"<<root->data;
}

struct node* Avl:: auxadd(int key,struct node* ptr)
{

    if(ptr==NULL)
        return maketree(key);
    else if(ptr->data==key)
        cout<<"Invalid insertion";
    else if(key<ptr->data)
    {
        ptr->left=auxadd(key,ptr->left);
        ptr=rebalance_left(ptr);
    }
    else if(key>ptr->data)
    {
        ptr->right=auxadd(key,ptr->right);
        ptr=rebalance_right(ptr);
    }
    root=ptr;
    return ptr;
}

struct node* Avl:: rebalance_left(struct node* p)
{
    if(height(p->left) > (height(p->right)+1))
    {
        if(height(p->left->left) > height(p->left->right))
        {
            return rotate_right(p);
        }
        else
        {
            p->left=rotate_left(p->left);
            return rotate_right(p);
        }
    }
    else
        return p;
}

struct node* Avl:: rebalance_right(struct node* p)
{

    if(height(p->right)>(height(p->left)+1))
    {
    //cout<<"here";
        if(height(p->right->right)>height(p->right->left))
        {
            p=rotate_left(p);
            return p;
        }
        else
        {
            p->right=rotate_right(p->right);
            p=rotate_left(p);
            return p;
        }
    }
    else
    {
        return p;
    }
}

struct node* Avl:: rotate_right(struct node* a)
{

    struct node* r= a->left;
    a->left=r->right;
    r->right=a;
    return r;
}

struct node* Avl:: rotate_left(struct node* a)
{
    cout<<"rotate left";
    struct node* t= a->right;
    a->right=t->left;
    t->left=a;
    return t;
}

void Avl:: del(std::string a)
{
    int n=convert(a);
    if(root==NULL)
        cout<<"NULL WRD~~";
    auxdel(root,n);
    display();
    available--;
};

struct node* Avl:: auxdel(struct node* rot, int key)
{
    cout<<"we here";
    if(rot==NULL)
    {
        cout<<"nowhere";
        return NULL;
    }
    cout<<"hell";
    if(key == rot->data)
    {

        if(rot->left==NULL)
        {
            struct node* hold=rot->right;
            delete(rot);
            root=hold;
            return hold;
        }
        else if(rot->right==NULL)
        {
            struct node* hold=rot->left;
            delete(rot);
            root=hold;
            return hold;
        }
        else
        {
            int del_key=find_min(rot->right);
            //cout<<del_key;
            rot->data=del_key;
            rot->right=auxdel(rot->right,del_key);
            return rot;
        }
        //available--;
    }
    if(key < rot->data)
    {
        rot->left = auxdel(rot->left,key);
        rot = balance_left(rot);
    }
    else if(key > rot->data)
    {
        rot->right = auxdel(rot->right,key);
        rot = balance_right(rot);
    }
    root=rot;
    return rot;
}

struct node* Avl:: balance_left(struct node* inp)
{

    if(height(inp->right)>(height(inp->left)+1))
    {
        if(height(inp->right->left)>height(inp->right->right))
        {
            inp->right=rotate_right(inp->right);
            inp=rotate_left(inp);
        }
        else
        {
            inp=rotate_left(inp);
        }
    }
    return inp;
}

struct node* Avl:: balance_right(struct node* inp)
{
    if(height(inp->left)>(height(inp->right)+1))
    {
        if(height(inp->left->left)<height(inp->left->right))
        {
            inp->left=rotate_left(inp->left);
            inp=rotate_right(inp);
        }
        else
        {
            inp=rotate_right(inp);
        }
    }
    return inp;
}

int Avl:: find_min(struct node* a)
{
    while(a->left!=NULL)
        a = a->left;
    return a->data;
}

void Avl:: display()
{
    cout<<endl<<"preorder"<<endl;
    preorder(root);
    cout<<"inorder"<<endl;
    inorder(root);
    cout<<"breadth first search "<<endl;
    bfs(root);
}
//breadthfirstsearch is like printing leaves nodes for all levels
void Avl:: bfs(node* root)
{
    int h = height(root);
    int i,j;
    for (i = 1; i <= h; i++)
    {
        for(j=(20-5*i);j>0;j--)
            cout<<" ";
        printGivenLevel(root, i);
        cout<<endl;
    }
    cout<<endl;
}

/* Print nodes at a given level */
void Avl:: printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        cout<<"       ";
        printGivenLevel(root->right, level-1);
    }
}

void Avl:: preorder(struct node* a)
{
    if(a==NULL)
        return;
    cout<<a->data<<endl;
    preorder(a->left);
    preorder(a->right);
}
void Avl:: inorder(struct node* a)
{
    if(a==NULL)
        return;
    inorder(a->left);
    cout<<a->data<<endl;
    inorder(a->right);
}
void Avl:: print_height()
{
   cout<<"height of the tree is " <<auxheight(root)<<endl;
}

int Avl:: height(struct node* ro)
{
   return auxheight(ro);
}

int Avl:: auxheight(struct node* ptr)
{
    if(ptr==NULL)
        return 0;
    int ldepth=auxheight(ptr->left);
    int rdepth=auxheight(ptr->right);
    if(ldepth>rdepth)
        return ldepth+1;
    else
        return rdepth+1;

}

int Avl::convert(std::string a)
{
    int len=a.length();
    int num=0;
    int aux,j=0,i;
    for(i=len-1;i>=0;i--)
    {
        aux=(a[i]-48)*pow(10,j);
        num+=aux;
        j++;
    }
    std::cout<<"num"<<num;
    return num;

}


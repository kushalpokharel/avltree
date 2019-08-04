#include "avl.h"
#include<iostream>
#include<string>
#include<sstream>

extern sf::Font font;
using namespace std;

int Avl::called=0;
int Avl::counter=0;
int Avl::mat[5][32]={0};
int Avl::calls=0;
int Avl::calls2=0;
int Avl::num=0;

Avl::Avl()
{
    available=0;
    total=0;
    root=NULL;
    xpos=600;
    ypos=100;
    called =0;
    ino.setFont(font);
    preo.setFont(font);
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
    return p;
}

void Avl:: add(std::string a)
{
    int n=convert(a);
    auxadd(n,root);
    called++;
    display();
    cout<<"called"<<called;
}

struct node* Avl:: auxadd(int key,struct node* ptr)
{
    cout<<"called"<<called;
    if(ptr==NULL)
    {
        struct node* c = maketree(key);
//        c->Create(xpos,ypos,numtostr(c->data));
//        container.push_back(*c);
        if(called==0)
        {
            root=c;
            cout<<"no";
        }
        return c;
    }
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
    //cout<<"rotate left";
    struct node* t= a->right;
    a->right=t->left;
    t->left=a;
    return t;
}

void Avl:: del(std::string a)
{
    int n=convert(a);
 //   int index=0;
 /*   while(1)
    {
        if(n==(container[index]).data);
        {
            cout<<"container index"<<index;
            std::vector<node>::iterator it=container.begin();
            std::advance(it,index);
            container.erase(it);
            break;
        }
        index++;
    }*/
    if(root==NULL)
        cout<<"NULL WRD~~";
    auxdel(root,n);
    display();
    cout<<"called"<<called;
};

struct node* Avl:: auxdel(struct node* rot, int key)
{
{
    if(rot==NULL)
        return NULL;
    if(key == rot->data)
    {
        cout<<"del"<<rot->data;
        called--;
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
            root=rot;
            return rot;
        }
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
    in="In-order:   ";
    pre="Pre-order: ";
    int i,j;
    cout<<endl<<"preorder"<<endl;
    preorder(root);
    cout<<"inorder"<<endl;
    inorder(root);
    for(i=0;i<5;i++)
    {
        for(j=0;j<32;j++)
        {
            mat[i][j]=0;
        }
    }
    cout<<"breadth first search "<<endl;
    bfs(root);
    cout<<"printing array"<<endl;
    container.clear();
    edges.clear();
    total=0;
    num=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<32;j++)
        {
            cout<<mat[i][j]<<" ";
            if(mat[i][j]==0)
                break;
            setpos(root,mat[i][j]);
        }
        ypos+=50;
        cout<<endl;
    }
    ypos=100;
    if(root!=NULL)
        setedges(root,root->getPosition());
    cout<<"here";
}

void Avl:: setedges(struct node* r,sf::Vector2f pos)
{
    cout<<"no";
    if(r==NULL)
        return;
    if(r->left==NULL && r->right==NULL)
        return;
    if(r->left != NULL)
    {
        class edge* e = new edge();
        e->create(pos,r->left->getPosition());
        edges.push_back(*e);
        num++;
        setedges(r->left,r->left->getPosition());
    }
    if(r->right!= NULL)
    {
        class edge* e = new edge();
        e->create(pos,r->right->getPosition());
        edges.push_back(*e);
        num++;
        setedges(r->right,r->right->getPosition());
    }

}

void Avl:: setpos(struct node*r ,int data )
{

    if(r->data==data)
    {
        struct node* c=new node();
        c->Create(xpos,ypos);
        r->Create(xpos,ypos);
        c->setString(numtostr(data));
        container.push_back(*c);
        total++;
        xpos=600;
        //ypos=100;
    }
    else if(data<r->data)
    {
        calls++;
        xpos-=200/calls;
       // calls++;
        setpos(r->left,data);
    }
    else if(data>r->data)
    {
        calls++;
        xpos+=200/calls;
       // calls++;
        setpos(r->right,data);
    }
    calls=0;
}

//breadthfirstsearch is like printing leaves nodes for all levels
void Avl:: bfs(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i, i);
        counter=0;
        cout<<endl;
    }
    cout<<endl;
}

/* Print nodes at a given level */
void Avl:: printGivenLevel(node* root, int level, int lev)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        cout<<"level"<<level<<endl;
        cout<<"counter"<<counter<<endl;
        cout << root->data << " ";
        mat[lev-1][counter] = root->data;
        counter++;
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1,lev);
        cout<<"       ";
        printGivenLevel(root->right, level-1,lev);
    }

}

void Avl::sear(std::string s)
{
    int i;
    for(i=0;i<total;i++)
    {
        if(container[i].st==s)
        {
            cout<<"color";
            container[i].highlight();
        }
    }
}

void Avl::preorder(struct node* a)
{
    if(a==NULL)
    {
        return;
    }
    cout<<a->data<<endl;
    pre+=numtostr(a->data);
    pre+=" ";
    preorder(a->left);
    preorder(a->right);
}
void Avl:: inorder(struct node* a)
{
    if(a==NULL)
        return;
    inorder(a->left);
    cout<<a->data<<endl;
    in+=numtostr(a->data);
    in+=" ";
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
    float num=0;
    float aux,j=0,i;
    for(i=len-1;i>=0;i--)
    {
        aux=(a[i]-48)*pow(10,j);
        num+=aux;
        j++;
    }
    std::cout<<"num"<<num<<endl;
    return num;

}

void Avl::render(Window &l_win)
{
    int i;
    for(i=0;i<total;i++)
    {
        container[i].Render(l_win.GetRenderWindow());
    }
    for(i=0;i<num;i++)
    {
        edges[i].render(l_win);
    }
    ino.setString(in);
    preo.setString(pre);
    ino.setCharacterSize(20);
    preo.setCharacterSize(20);
    ino.setFillColor(sf::Color::Magenta);
    preo.setFillColor(sf::Color::Magenta);
    preo.setPosition(sf::Vector2f(380,650));
    ino.setPosition(sf::Vector2f(380,600));
    l_win.Draw(preo);
    l_win.Draw(ino);
}

/*void Avl:: levels(node* root, int level,Window& w)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        root->Create(xpos,ypos);
        root->setString(numtostr(root->data));
        root->Render(w.GetRenderWindow());
    }
    else if (level > 1)
    {
        levels(root->left, level-1,w);
        levels(root->right, level-1,w);
    }
}
*/
std::string Avl:: numtostr(int n)
{
    ostringstream str1;
    str1 << n;
    string a = str1.str();
    return a;
}


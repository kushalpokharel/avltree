#pragma once
#include "node.h"

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

class Avl
{
public:
    Avl();
    struct node* maketree(int b);
    void add(std::string a);
    int convert(std::string a);
    struct node* auxadd(int key,struct node* ptr);
    struct node* rebalance_left(struct node* p);
    struct node* rebalance_right(struct node* p);
    struct node* rotate_right(struct node* a);
    struct node* rotate_left(struct node* a);
    void del(std::string );
    struct node* auxdel(struct node* rot, int key);
    struct node* balance_left(struct node* inp);
    struct node* balance_right(struct node* inp);
    int find_min(struct node* a);
    void display();
    void bfs(node* root);
    void printGivenLevel(node* root, int level);
    void preorder(struct node* a);
    void inorder(struct node* a);
    void print_height();
    int height(struct node* ro);
    int auxheight(struct node* ptr);
private:
    Node nodes[15];
    int available;
    struct node* root;
    int total;
    //int num;
};

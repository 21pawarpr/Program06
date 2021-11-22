/**********************************************
 * Tree Public
 * Written by Prabhleen Pawar
 **********************************************/

#define TREE_MAX 1024
#define TREE_ERR -1
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#include "Tree.h"


/****************************
 * tree()
 ****************************/
tree::tree()
{
    root = NULL;
}

/****************************
 * Destructor
 ****************************/
tree::~tree()
{
    if (root != NULL)
    {
        delete root;
    }
}

/****************************
 * show()
 ****************************/
void tree::show(string order, ostream& out)
{

    //Check if root is anything
    if (root == NULL)
    {
        //Get out
        return;
    }
    //LMR  OUT
    if (order == "LMR")
    {
        root->lmr(out);
    }
    //RML OUT
    if (order == "RML")
    {
        root->rml(out);
    }
    //MLR OUT
    if (order == "MLR")
    {
        root->mlr(out);
    }


}
/****************************
 * insert()
 ****************************/
void tree::insert(string value)
{
    //Declare pointers
    node* p = NULL;

    //If root is nothing
    if (root == NULL)
    {
        root = new node(value);
        return;
    }
    //Walk through tree
    p = root;

    //While loop
    while (p->value != value)
    {
        //Check left side
        if (value <= p->value)
        {
            if (p->left == NULL)
            {
                p->left = new node(value);
            }
            p = p->left;
        }
        //Check right side
        else
        {
            if (p->right == NULL)
            {
                p->right = new node(value);
            }
            p = p->right;
        }
    }

}
/****************************
 * find()
 ****************************/
bool tree::find(string value)
{

    //Pointer declarations
    node* q;

    //Check root
    if (root == NULL)
    {
        return false;
    }

    //Set q as root
    q = root;

    while (q->value != value)
    {
        //Values equal
        if (value == q->value)
        {
            return true;
        }
        //Less than situation
        else if (value <= q->value)
        {
            //If not found
            if (q->left == NULL)
            {
                return false;
            }
            q = q->left;
        }
        //More than
        else
        {
            //If not found
            if (q->right == NULL)
            {
                return false;
            }
            q = q->right;
        }
    }

    return true;
}

/****************************
 * depth()
 ****************************/
int tree::depth()
{
    //Return formula
    //Recursion call
    return root->depth() - 1;
}

/****************************
 * count()
 ****************************/
int tree::count()
{
    //Call other count function
    return root->count();
}

/****************************
 * remove()
 ****************************/
bool tree::remove(string value)
{
    //Variables
    node* p;
    node* q = NULL;
    node* right;
    node* left;

    //Null Check
    if (root == NULL)
    {
        return false;
    }

    //Assign root
    p = root;

    //First scenario
    while (p != NULL && p->value != value)
    {
        q = p;

        //Move left
        if (value < p->value)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    //Null Check
    if (p == NULL)
    {
        return false;
    }

    if (p == root)
    {
        root = NULL;
    }
    else if (p == q->left)
    {
        q->left = NULL;
    }
    else
    {
        q->right = NULL;
    }

    left = p->left;
    right = p->right;

    //Set to null
    p->left = NULL;
    p->right = NULL;

    cout << (left == NULL) << endl;
    cout << (right == NULL) << endl;

    if (left != NULL)
    {
        //Call insert
        insert(left->value);
    }
    if (right != NULL)
    {
        //Call insert
        insert(right->value);
    }

    return true;
}
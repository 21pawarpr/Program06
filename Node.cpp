/**********************************************
 * Node.cpp
 * Written by Prabhleen Pawar
 **********************************************/


#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

#include "Node.h"

#define NODE_MAX 1024
#define NODE_ERR -1
/*******************************
 * Constructor
 *******************************/
node::node(string arg1)
{
    value = arg1;
    //Intialize to zero
    left = right = NULL;
}

/**********************************************
 * Destructor
 **********************************************/
node::~node()
{
    //Clean up
    if (left != NULL)
    {
        delete left;
    }
    if (right != NULL)
    {
        delete right;
    }
}

/****************************
 * lmr()
 ****************************/
void node::lmr(ostream& out)
{
    //Automatically checks if it is null or not
    if (left != NULL)
    {
        //Recursive Call
        left->lmr(out);
    }

    put(out);

    if (right != NULL)
    {
        //Reucursive Call
        //Pass out for parameters
        right->lmr(out);
    }
}
/****************************
 * rml()
 ****************************/
void node::rml(ostream& out)
{
    if (right != NULL) 
    { 
        right->rml(out); 
    }

    //Call put function
    put(out);

    if (left != NULL)
    { 
        left->rml(out); 
    }
}
/***********************************
 * mlr()
***********************************/
void node::mlr(ostream& out)
{
    //Call put function
    put(out);

    if (left != NULL) 
    {
        left->mlr(out); 
    }
    if (right != NULL) 
    {
        right->mlr(out);
    }
}


/****************************
 * put()
 ****************************/
void node::put(ostream& out)
{
    cout << value << endl;
}

/****************************
 * depth()
 ****************************/
int node::depth()
{
    //Variables
    int l = 0;
    int r = 0;

    if (left != NULL) 
    {
        l = left->depth(); 
    }
    if (right != NULL) 
    { 
        r = right->depth();
    }

    return max(l, r) + 1;
}

/***********************************
 * count()
***********************************/
int node::count()
{
    int c = 1;

    if (left != NULL) 
    {
        c += left->count(); 
    }
    if (right != NULL) 
    {
        c += right->count(); 
    }

    return c;
}
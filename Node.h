/**********************************************
 * Node.h
 * Written by Prabhleen Pawar
 **********************************************/

#include <string>

#define NODE_MAX 1024
#define NODE_ERR -1

class node
{
	friend class tree;
public:
	node(string arg);            //Constructor
	~node();                     //Deoconstructor
	void put(ostream& out);      //Put function
	void lmr(ostream& out);      //LMR function
	void rml(ostream& out);      //RML Function
	void mlr(ostream& out);		 //MLR Function
	int depth();				 //Tells the max length from root to the last root
	int count();				 //Counts the total #s of nodes

private:
	node* left, * right;
	string value;
	node* current;
	string* map;
};
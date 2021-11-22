/**********************************************
 * Tree.h
 * Written by Prabhleen Pawar
 **********************************************/

#include <string>

#define TREE_MAX 1024
#define TREE_ERR -1


#include "Node.h"

class tree
{
    friend class node;
public:
    tree();                                     // Constructor
    ~tree();                                    // Destructor
    void insert(string value);                  // Insert into tree
    void show(string, ostream& out);            // Display in order
    bool find(string value);                    // Finds value
    int count();                                // Counts the total #s of nodes
    int depth();                                // Tells the max length from root to the last root
    bool remove(string value);                  // Remove given value from tree
private:
    node* root;

};
/***********************************
 * Program 05
 * Written by Mark M Bowman
 ***********************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Tree.h"

/***********************************
 * Main
 * Test function - DO NOT CHANGE
 ***********************************/
void main()
{
    tree t;
    string fname, s, order;
    fstream infile;

    // Get file name

    cout << "Enter file name: ";
    cin >> fname;
    cout << endl;
    //fname = "People.txt";

    // Open file

    infile.open(fname, ios::in);

    // Loop through file

    while (!infile.eof())
    {
        infile >> s;

        // Process if okay

        if (infile.good())
            t.insert(s);
    };

    // Close

    infile.close();

    // Display order

    cout << "Order to display (LMR,MLR,RML): "; 
    cin >> order;

    //order = "LMR";

    // Display 

    cout << order << " Order\n--------------\n";
    t.show(order, cout);
    cout << endl;

    //Count display
    cout << "Count: " << t.count() << endl;

    //Depth Display
    cout << "Depth: " << t.depth() << endl;

    // Find node

    cout << endl;
    cout << "Enter value to find: ";
    cin >> s;

    cout << endl << "Find: ";
    if (t.find(s))
    {
        cout << s << " found!" << endl;
    }
    else
        cout << s << " not found" << endl;

    //Remove function
    cout << endl << "Remove:";
    if (t.remove(s))
    {
        cout << s << " removed" << endl;
    }
    else
    {
        cout << s << " not removed" << endl;
    }

    // Display 

    cout << "\n" << order << " Order\n--------------\n";
    t.show(order, cout);
    cout << endl;
    
    //Count display
    cout << "Count: " << t.count() << endl;

    //Depth Display
    cout << "Depth: " << t.depth() << endl;
}
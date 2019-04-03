#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <algorithm>
#include <string>


#include "Kth.h"


using namespace std;

int main()
{
    //Set up the maximum value for the list
    int val_max = 5800;


    Kth Ks;
    //I'm using a vector here because it makes memory management easier and...
    //...Avoids passing un-needed parameters
    //Ideally for optimization we'd use naked arrays, but this wrapper is better...
    //...To demonstrate proof of concept
    vector<int> unsorted_list;

    //For k'th smallest element
    int k;

    float select;
    //Two options, Read in from list, or random generated
    cout << "1: Read from List" << endl << "2: Randomly Generated" << endl;
    cin >> select;
    if(select == 1)
    {
    ifstream reader;
    reader.open("List.txt");
    if(reader.is_open())
    {
        int r_in;
        while(!reader.eof())
        {
            reader >> r_in;
            cout << r_in << endl;
            unsorted_list.push_back(r_in);
        }
        cout << "Enter the k for k-th smallest in the list" << endl;
        cin >> k;
    }
    }
    else
    {
        int val_max = 5800;
        int len;
        int seed;
        cout << "Enter Length of List: " << endl;
        cin >> len;
        cout << "Enter Seed" << endl;
        cin >> seed;
        cout << "Enter the k for k-th smallest in the list" << endl;
        cin >> k;

        //Set up the generator with the given seed
        minstd_rand rand_gen(seed);
        uniform_int_distribution<int> dist(0, val_max);


        //Generate the list of numbers
        for(int i = 0; i < len; i++)
        {
            unsorted_list.push_back( dist(rand_gen) );
        }
    }

    //Now that we have our initial list, either from file or from pseudorandom generation
    //We can pass it into the solver
    //We'll be calling this recursively, so the answer should be the value returned by this initial call
    int result;
    result = Ks.Small(unsorted_list, k);
    cout << result << endl;

    return 0;

}



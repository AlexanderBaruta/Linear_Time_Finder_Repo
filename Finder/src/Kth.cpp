#include "Kth.h"

Kth::Kth()
    {
    //ctor
    }

Kth::~Kth()
    {
    //dtor
    }

//This takes in the vector of ints, the k to find,
int Kth::Small(vector<int> unsorted_list, int k)
    {
    //Sanity Checking
    if(k > 0)
        {
        if(k <= unsorted_list.size())
            {
            //Create the vectors for the medians and the semi_sorted list
            vector<int> medians;
            vector<int> semi_sorted_list;


            //Build the lists of size 5
            int m = 0;
            int p = 0;
            for (m = 0; m < unsorted_list.size() / 5; m ++)
                {
                //Create the intermediate vector
                vector<int> med_get = {unsorted_list[0 + 5*m], unsorted_list[1 + 5*m],unsorted_list[2 + 5*m],unsorted_list[3 + 5*m], unsorted_list[4 + 5*m]};
                //Emplace the median and sort
                medians.emplace_back(Find_Median(med_get));
                //Append the results to the semi sorted list
                semi_sorted_list.insert(end(semi_sorted_list), begin(med_get), end(med_get));
                }
            //Handle the Last list of size < 5 if one exists
            p = m * 5;
            if(p < unsorted_list.size())
                {
                //Create the intermediate vector
                vector<int> med_get;
                //Go through and get the remaining elements in the unsorted_list
                for(p; p < unsorted_list.size(); p++)
                    {
                    med_get.emplace_back(unsorted_list[p]);
                    }
                //Add this median to the list of medians
                medians.emplace_back(Find_Median(med_get));
                //Add the values to the semi-sorted list
                semi_sorted_list.insert(end(semi_sorted_list), begin(med_get), end(med_get));
                }

            int M;
            //Find the median value among all medians
            if(medians.size() > 1)
                {
                M = Small(medians, medians.size() / 2);
                }
            else
                {
                M = medians[0];
                }

            //Get either the upper or lower part of the vector
            //Depending on where k falls
            vector<int>Partitioned = Part(semi_sorted_list, M, k);

            //If the median value is k
            if(Partitioned.size() == k)
                {
                cout << "Found K" << endl;
                //Return k
                return Partitioned[Partitioned.size() - 1];
                }
            //Otherwise if there are only 2 elements left
            //Find the smaller of the two and return that,
            //Since the other case is handled by the previous return
            //Safer to just use the min anyway
            else if(Partitioned.size()==2)
                {
                return min(Partitioned[0], Partitioned[1]);
                }
            //Otherwise we need to recur
            //Recurral part is determined by Partitioning
            else
                {
                return Small(Partitioned, k);
                }

            }
        else
            {
            return -2;
            }
        }
    return -1;
    }


//Find the median of a sorted vector
//Might as well use the general algorithm here
//This sorts the subarrays
//While also finding the median
int Kth::Find_Median(vector<int> &m)
    {
    sort(m.begin(), m.end());

    return m[m.size()/2];
    }





vector<int> Kth::Part(vector<int> v, int m, int &k)
    {
    //Partition the vector into two smaller vectors
    //One containing <= m, the other containing >m
    //Want to guarentee that m is the last element in lv

    //Construct the lower and upper vectors to store values
    vector<int> lv, uv;

    //For each element in v
    for(int i = 0; i < v.size(); i++)
        {
        //if the element is < m
        //Store it in the lower v
        if(v[i] < m)
            {
            lv.push_back(v[i]);
            }
        //Else if the element is > m
        //store it in the upper v
        if(v[i] > m)
            {
            uv.push_back(v[i]);
            }
        }

    //Append m to the list of lower values
    lv.push_back(m);

    //if k is in the lower list
    //return lv
    if(k <= lv.size())
        {
        return lv;
        }
    //Otherwise subtract the size of the lower list from k
    //And return the upper list
    else
        {
        k -= lv.size();
        return uv;
        }
    }

















#include "Kth.h"

Kth::Kth()
    {
    //ctor
    }

Kth::~Kth()
    {
    //dtor
    }

int Kth::Small(vector<int> unsorted_list, int k, const int v_max, bool med)
    {
        cout << "Recurred" << endl;
        cout << k << " " << unsorted_list.size() << " " << med << endl;
    //Sanity Checking
    if(k > 0)
        {
        if(k <= unsorted_list.size())
            {
                int useless;
                //cin >> useless;

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
                vector<int> med_get;
                for(p; p < unsorted_list.size(); p++)
                    {
                    med_get.emplace_back(unsorted_list[p]);
                    }
                medians.emplace_back(Find_Median(med_get));
                semi_sorted_list.insert(end(semi_sorted_list), begin(med_get), end(med_get));
                }

            int M;
            //Find the median value among all medians
            if(medians.size() > 1)
            {
                cout << "Getting Median of Medians" << endl;
                M = Small(medians, medians.size() / 2, v_max, 1);
            }
            else
            {
                M = medians[0];
            }

            vector<int>Partitioned = Part(semi_sorted_list, M, k);

            if(Partitioned.size() == k)
            {
                cout << "Found K" << endl;
                return Partitioned[Partitioned.size() - 1];
            }
            else if(Partitioned.size()==2)
            {
                cout << "Found K in Size of 2" << endl;
                return Partitioned[k-1];
            }
            else
            {
                cout << "Recurring on Partition" << endl;
                return Small(Partitioned, k, v_max, 0);
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
    vector<int> lv, uv;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] < m)
        {
            lv.push_back(v[i]);
        }
        if(v[i] > m)
        {
            uv.push_back(v[i]);
        }
    }
    lv.push_back(m);

    if(k <= lv.size())
    {
        return lv;
    }
    else
    {
        k -= lv.size();
        return uv;
    }
}

















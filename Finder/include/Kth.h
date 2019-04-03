#ifndef KTH_H
#define KTH_H
#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Kth
{
    public:
        Kth();
        virtual ~Kth();

        int Small(vector<int>, int k, const int v_max, bool med);
        int Find_Median(vector<int> &);

        vector<int> Part(vector<int>, int M, int &k);
        //int GetPart();

    protected:

    private:
        bool lg;
};

#endif // KTH_H

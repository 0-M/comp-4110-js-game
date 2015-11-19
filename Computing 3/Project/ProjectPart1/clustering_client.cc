#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include "clustering.h"
using namespace std;

int main(int argc, char* argv[])
{
    int numClusters = atoi(argv[1]);
    int numInputs = 4;
    cout << "Number of clusters: " << numClusters << endl;
    cout << "Number of inputs: " << numInputs << endl;
    vector<double> l1,l2,l3,l4,t1,t2;
        l1.push_back(10.1);
        l1.push_back(23.1);
        l1.push_back(4.9);
        l1.push_back(56.84);
        l2.push_back(1.2);
        l2.push_back(23.4);
        l2.push_back(4.2);
        l2.push_back(5.35);
        l3.push_back(2.5);
        l3.push_back(67.4);
        l3.push_back(5.6);
        l3.push_back(34.9);
        l4.push_back(11.32);
        l4.push_back(2.1);
        l4.push_back(4.12);
        l4.push_back(15.3);

}

//using std::vector;
//void pVector(vector<double> arg)
//{
//   unsigned int x = arg.size();
//   for(unsigned int i = 0;i < x;i++)
//   {
//       cout << "arg[" << i << "]: " << arg[i] << " ";
//   }
//   cout << endl;
//}
//
//double pDistance(vector<double> arg1,vector<double> arg2)
//{
//    double result = 0;
//    result = result + (arg1[0] - arg2[0]) * (arg1[0] - arg2[0]);
//    result = result + ((arg1[1] - arg2[1]) * (arg1[1] - arg2[1]));
//    result = result + ((arg1[2] - arg2[2]) * (arg1[2] - arg2[2]));
//    result = result + ((arg1[3] - arg2[3]) * (arg1[3] - arg2[3]));
//    return sqrt(result);
//}
//vector<double> centroid(vector<vector<double> > arg1)
//{
//    vector<double> result (4,0);
//    result[0] = (arg1[0][0] + arg1[1][0])/3;
//    result[1] = (arg1[0][1] + arg1[1][1])/3;
//    result[2] = (arg1[0][2] + arg1[1][2])/3;
//    result[3] = (arg1[0][3] + arg1[1][3])/3;
//    return result;
//}
//int main(int argc, char* argv[])
//{
//    vector<double> l1,l2,l3,l4,t1,t2;
//    vector<vector<double> > v;
//    l1.push_back(10.1);
//    l1.push_back(23.1);
//    l1.push_back(4.9);
//    l1.push_back(56.84);
//    l2.push_back(1.2);
//    l2.push_back(23.4);
//    l2.push_back(4.2);
//    l2.push_back(5.35);
//    l3.push_back(2.5);
//    l3.push_back(67.4);
//    l3.push_back(5.6);
//    l3.push_back(34.9);
//    l4.push_back(11.32);
//    l4.push_back(2.1);
//    l4.push_back(4.12);
//    l4.push_back(15.3);
//    //pVector(l1);
//    //pVector(l2);
//    //pVector(l3);
//    //pVector(l4);
//    cout << "l1,l2: " << pDistance(l1,l2) << endl;
//    cout << "l1,l3: " << pDistance(l1,l3) << endl;
//    cout << "l1,l4: " << pDistance(l1,l4) << endl;
//    cout << "l2,l3: " << pDistance(l2,l3) << endl;
//    cout << "l2,l4: " << pDistance(l2,l4) << endl;
//    cout << "l3,l4: " << pDistance(l3,l4) << endl;
//    v.push_back(l2);
//    v.push_back(l4);
//    t1 = centroid(v);
//    cout << "t1:";
//    pVector(t1);
//    cout << "t1,l1: " << pDistance(t1,l1) << endl;
//    cout << "t1,l3: " << pDistance(t1,l3) << endl;
//}


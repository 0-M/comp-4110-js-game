#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include "clustering.h"
using namespace std;
vector<double> strToVec(char arg[],unsigned int * arg2)
{
    vector<double> temp;
    char *token = strtok(arg," ");
    while(token != NULL)
    {
        *arg2 = *arg2 + 1;
        temp.push_back(atof(token));
        token = strtok(NULL," ");
    }
    return temp;
}

int main(int argc, char* argv[])
{
    char temp = 'a';
    string tempS;
    unsigned int numClusters,numInputs,numDimensions,flag = 0;
    vector<string> inputsS;
    for(unsigned int i = 0;*(argv[1]+ i) != '\0';i++)
    {
        if (*(argv[1] + i) >= 57 || *(argv[1] + i) <= 48)
        {
            flag = 1;
        }
    }
    if(flag == 1)
    {
        cout << "Command-line argument is not an integer" << endl;
        return 0;
    }
    while(getline)




}



//int main(int argc, char* argv[])
//{
//    char t1[] = "10.1 23.1 4.9 56.84"; //going to need to get input through a getline loop
//    char t2[] = "1.2 23.4 4.2 5.35";
//    char t3[] = "2.5 67.4 5.6 34.9";
//    char t4[] = "11.32 2.1 3.12 15.3";
//    // GOING TO NEED TO ADD A CHECK TO MAKE SURE COMMAND LINE ARGUMENT IS AN INTEGER
//    // GOING TO NEED TO ADD A CHECK TO MAKE SURE INPUTS ARE ALL SAME NUMBER OF DIMENSIONS -- if they are it needs to be saved
//    unsigned int numClusters = atoi(argv[1]),numInputs = 4,numDimensions = 0; // NUM INPUTS IS GOING TO NEED TO BE CALCULATED IN THE LOOPS
//    vector<vector<double> > clusters;
//    vector<double> l1,l2,l3,l4;
//    vector<string> inputs;
//    ClusterHolder hold;
//
//    inputs.push_back(t1); //gonna need to make this part into a loop until input is over
//    inputs.push_back(t2);
//    inputs.push_back(t3);
//    inputs.push_back(t4);
//    l1 = strToVec(t1,&numDimensions); //gonna need to make this part into a loop until input is over
//    l2 = strToVec(t2,&numDimensions); //gonna need to use this to make sure each input is the same length
//    l3 = strToVec(t3,&numDimensions);
//    l4 = strToVec(t4,&numDimensions);
//    clusters.push_back(l1); // going to need to make this part into a loop until input is over
//    clusters.push_back(l2);
//    clusters.push_back(l3);
//    clusters.push_back(l4);
//    //cout << "Number of clusters: " << numClusters << endl;
//    //cout << "Number of inputs: " << numInputs << endl;
//    for(unsigned int i = 0; i < numInputs; i++)
//    {
//
//        Cluster temp(4); //4 is the number of dimensions of the inputs, needs to be calcualted
//        temp.addVect(clusters[i]);
//        hold.addCluster(temp);
//    }
////    hold.printHolder();
////    Cluster temp(4);
////    temp.addVect(l2);
////    temp.addVect(l4);
////    temp.addVect(l1);
////    temp.printCluster();
////    double test;
////    vector<Cluster> test2 = hold.getHolder();
////    test = hold.findDist(test2[0],test2[1],4);
////    cout << test << endl;
//    while(hold.getSize() != numClusters)
//    {
//        hold.mergeClosest();
//        //hold.printHolder();
//    }
//    hold.printHolder();
//
//
//
//}

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


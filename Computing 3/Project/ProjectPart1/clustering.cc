#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include "clustering.h"
using namespace std;









// Cluster

Cluster::Cluster(unsigned int arg)
{
    dimensions = arg;
}
vector<vector<double> > Cluster::getCluster() //getter
{
    return vect;
}
void Cluster::printCluster()
{
    for(unsigned int i = 0; i < vect.size(); i++)
    {
        // cout << i + 1 << ": ";
        for(unsigned int j = 0; j < dimensions; j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // printCentroid();
    //  printRunningSum();
}
void Cluster::addVect(vector<double> arg)
{
    vect.push_back(arg);
    if(vect.size() == 1)
    {
        runningSum = arg;
        centroid = arg;
    }
    else
    {
        findCentroid();
    }
}
void Cluster::findCentroid()
{
    //vector<double> temp;
    for(unsigned int i = 0; i < dimensions; i++)
    {
//        double sum = 0;
//        for(unsigned int j = 0;j < vect.size();j++)
//        {
//            sum = sum + vect[j][i];
//        }
//        temp.push_back(sum);
        runningSum[i] = runningSum[i] + vect.back()[i];
    }
    //runningSum = temp;
    for(unsigned int i = 0; i < runningSum.size(); i++)
    {
        centroid.at(i) = (runningSum[i]/vect.size());
    }
}

void Cluster::printCentroid()
{
    cout << "Centroid: ";
    for(unsigned int i = 0; i < centroid.size(); i++)
    {
        cout << centroid[i] << " ";
    }
    cout << endl;
}
void Cluster::printRunningSum()
{
    cout << "Running sum: ";
    for(unsigned int i = 0; i < runningSum.size(); i++)
    {
        cout << runningSum[i] << " ";
    }
    cout << endl << endl;
}
vector<double> Cluster::getCentroid()
{
    return centroid;
}

unsigned int Cluster::getDimensions()
{
    return dimensions;
}
unsigned int Cluster::getNumVec()
{
    return vect.size();
}

// Cluster Holder
void ClusterHolder::printHolder()
{
    for(unsigned int i = 0; i < holder.size(); i++)
    {
        cout << "cluster #" << i + 1 << ": " << endl;
        holder[i].printCluster();
    }
}
void ClusterHolder::addCluster(Cluster arg)
{
    holder.push_back(arg);
}
double ClusterHolder::findDist(Cluster arg,Cluster arg2,unsigned int dim)
{
    double temp = 0;
    for(unsigned int i = 0; i < dim; i++)
    {
        temp = temp + pow(((arg.getCentroid())[i] - (arg2.getCentroid())[i]),2);
    }
    return sqrt(temp);
}

void ClusterHolder::mergeClosest()
{
    vector<vector<double> > forMerge;
    unsigned int arr[2] = {0,0},temp;
    double dist = -1,lowestDist = -1;
    temp = holder[0].getDimensions();
    for(unsigned int i = 0; i < holder.size() - 1; i++)
    {
        for(unsigned int j = i + 1; j < holder.size(); j++)
        {
            dist = findDist(holder[i],holder[j],temp);
            if(lowestDist < 0) //first one
            {
                lowestDist = dist;
                arr[0] = i;
                arr[1] = j;
            }
            else if(dist < lowestDist) //if the new distance is lower
            {
                lowestDist = dist;
                arr[0] = i;
                arr[1] = j;
            }
        }
    }
    // cout << "arr[0]: " << "l" << arr[0] + 1 << endl;
    // cout << "arr[1]: " << "l" << arr[1] + 1 << endl;
    if(holder[arr[0]].getNumVec() < holder[arr[1]].getNumVec()) //put offset of the bigger cluster in arr[0]
    {
//       toMerge = arr[0];
        swap(arr[0],arr[1]);
    }
//    else
//    {
//        toMerge = arr[1];
//    }
    // cout << "toMerge: " << toMerge + 1 << endl;
    forMerge = holder[arr[1]].getCluster();
    for(unsigned int t = 0; t < forMerge.size(); t++) //for each entry in the smaller cluster
    {
        holder[arr[0]].addVect(forMerge[t]);
    }
    holder.erase(holder.begin() + arr[1]);


}

vector<Cluster> ClusterHolder::getHolder()
{
    return holder;
}

unsigned int ClusterHolder::getSize()
{
    return holder.size();
}


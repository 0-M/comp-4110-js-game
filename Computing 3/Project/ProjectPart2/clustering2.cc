#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include "clustering2.h"
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
    cout << "[";
    for(unsigned int i = 0; i < vect.size(); i++)
    {
        cout << "[";
        for(unsigned int j = 0; j < dimensions; j++)
        {
            cout << vect[i][j];
            if(j != dimensions - 1)
            {
                cout << " ";
            }
        }
        cout << "]";
        if(i != vect.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";
    cout << endl << endl;
}
void Cluster::addVect(vector<double> arg)
{
    vect.push_back(arg);
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
    cout << "Resulting clusters:" << endl;
    for(unsigned int i = 0; i < holder.size(); i++)
    {
        cout << "cluster: ";
        holder[i].printCluster();
    }
}
void ClusterHolder::addCluster(Cluster arg)
{
    holder.push_back(arg);
}
double ClusterHolder::findDist(Cluster arg,Cluster arg2)
{
    double temp = 0;
    int counter = 0;
    vector<vector<double> > t1,t2;
    for(unsigned int i = 0; i < arg.getNumVec(); i++)
    {
        for(unsigned int j = 0; j < arg2.getNumVec(); j++)
        {
            temp = temp + eucDist(arg.getCluster()[i],arg2.getCluster()[j],arg.getDimensions());
            counter = counter + 1;
        }
    }
    temp = temp/counter;
    return temp;
}
double ClusterHolder::eucDist(vector<double> arg,vector<double> arg2,unsigned int dim)
{
    double temp = 0 ;
    for(unsigned int i = 0; i < dim; i++)
    {
        for(unsigned int j = 0; j < dim; j++)
        {
            temp = temp + pow((arg[i] - arg2[j]),2);
        }
    }
    return sqrt(temp);
}

void ClusterHolder::mergeClosest(unsigned int desiredClusters)
{
    vector<vector<double> > forMerge;
    vector<Distances> dists,twoLowest;
    unsigned int newLoc = 0;
    while(holder.size() != desiredClusters)
    {
        genDists(&dists,newLoc);
        cout << endl << endl;
        twoLowest = findTwoLowest(&dists);
        if(holder[twoLowest[0].getArr()[0]].getNumVec() < holder[twoLowest[0].getArr()[1]].getNumVec()) //put offset of the bigger cluster in arr[0]
        {
            swap(twoLowest[0].getArr()[0],twoLowest[0].getArr()[1]);
        }
        newLoc = twoLowest[0].getArr()[0];
        if(newLoc > twoLowest[0].getArr()[1])
        {
            newLoc = newLoc - 1;
        }
        cout << "Merging: cluster: ";
        holder[twoLowest[0].getArr()[0]].printCluster();
        cout << "         cluster: ";
        holder[twoLowest[0].getArr()[1]].printCluster();
        forMerge = holder[twoLowest[0].getArr()[1]].getCluster();
        for(unsigned int t = 0; t < forMerge.size(); t++) //for each entry in the smaller cluster
        {
            holder[twoLowest[0].getArr()[0]].addVect(forMerge[t]);
        }
        holder.erase(holder.begin() + twoLowest[0].getArr()[1]);
    }


}


vector<Cluster> ClusterHolder::getHolder()
{
    return holder;
}

unsigned int ClusterHolder::getSize()
{
    return holder.size();
}

void ClusterHolder::genDists(vector<Distances> * arg,unsigned int compLoc)
{
    if(arg->size() == 0)
    {
        for(unsigned int i = 0; i < holder.size(); i++)
        {
            for(unsigned int j = i + 1; j < holder.size(); j++)
            {
                Distances temp;
                temp.setArr(i,j);
                temp.setDist(findDist(holder[i],holder[j]));
                arg->push_back(temp);
            }
        }
    }
    else
    {
        Cluster temp = holder[compLoc];
        for(unsigned int i = 0; i < holder.size(); i++)
        {
            cout << "comp loc: " << compLoc << endl;
            cout << "i: " << i << endl;
            if(i != compLoc)
            {
                Distances temp;
                temp.setArr(compLoc,i);
                temp.setDist(findDist(holder[compLoc],holder[i]));
                arg->push_back(temp);
            }
            else
            {
               i = i + 1;
            }
        }
    }


}
void ClusterHolder::printDists(vector<Distances> arg)
{
    for(unsigned int i = 0; i < arg.size(); i++)
    {
        arg[i].printDistances();
    }
}
vector<Distances> ClusterHolder::findTwoLowest(vector<Distances> * arg)
{
    vector<Distances> temp;
    unsigned int l1,l2;
    Distances t1,t2;
    t1.setDist(-1);
    for(unsigned int i = 0; i < arg->size(); i++)
    {
        if(t1.getDist() < 0)
        {
            t1 = (*arg)[i];
        }
        else if((*arg)[i].getDist() < t1.getDist())
        {
            t1 = (*arg)[i];
        }
    }
    l1 = t1.getArr()[0];
    l2 = t1.getArr()[1];
    for(unsigned int i = 0; i < (*arg).size(); i++)
    {
        unsigned int temp2[2];
        unsigned int * tempPoint = (*arg)[i].getArr();
        temp2[0] = tempPoint[0];
        temp2[1] = tempPoint[1];
        if(t2.getDist() < 0 && temp2[0] !=  l1 && temp2[0] != l2 && temp2[1] !=  l1 && temp2[1] != l2)
        {
            t2 = (*arg)[i];
        }
        else
        {
            arg->erase(arg->begin() + i);
            i = i - 1;
        }
    }
    temp.push_back(t1);
    temp.push_back(t2);
    return temp;
}

// Class Distances
void Distances::setDist(double arg)
{
    dist = arg;
}
void Distances::setArr(unsigned int arg1,unsigned int arg2)
{
    arr[0] = arg1;
    arr[1] = arg2;
}
unsigned int * Distances::getArr()
{
    return arr;
}
double Distances::getDist()
{
    return dist;
}
void Distances::printDistances()
{
    cout << "[i]: " << arr[0] << endl;
    cout << "[j]: " << arr[1] << endl;
    cout << "dist: " << dist << endl;
}

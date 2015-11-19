#ifndef CLUSTERING_H_INCLUDED
#define CLUSTERING_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Cluster
{
protected:
vector<vector<double> > vect;

public:
Cluster(); //constructor
vector<vector<double> > * getClusterLoc(); //getter
void setClusterLoc(); //setter



};

class ClusterHolder
{
protected:
vector<vector<vector<double> > > clusterHold;

public:
ClusterHolder(); // constructor
vector<vector<vector<double> > > * getHolderLoc(); //getter
void setHolderLoc(); //setter


};





#endif // CLUSTERING_H_INCLUDED

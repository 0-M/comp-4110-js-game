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
private:
    vector<vector<double> > vect;
    vector<double> centroid;
    vector<double> runningSum; //running sum of each coordinate in the cluster
    unsigned int dimensions; //size of each vector, number of dimensions
public:
    Cluster(unsigned int arg);
    vector<vector<double> > getCluster(); //getter
    void printCluster();
    void addVect(vector<double> arg);
    void findCentroid();
    vector<double> getCentroid();
    void printCentroid();
    void printRunningSum();
    unsigned int getDimensions();
    unsigned int getNumVec();


};

class ClusterHolder
{
private:
    vector<Cluster> holder;

public:
    void printHolder();
    void addCluster(Cluster arg);
    double findDist(Cluster arg,Cluster arg2,unsigned int dim);
    void mergeClosest();
    vector<Cluster> getHolder();
    unsigned int getSize();


};





#endif // CLUSTERING_H_INCLUDED

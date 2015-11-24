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
    unsigned int getDimensions();
    unsigned int getNumVec();


};
class Distances
{
private:
    unsigned int arr[2];
    double dist;
public:
    void setDist(double arg);
    void setArr(unsigned int arg1,unsigned int arg2);
    unsigned int * getArr();
    double getDist();
    void printDistances();
};



class ClusterHolder
{
private:
    vector<Cluster> holder;
    Distances secondLowest;
public:
    void printHolder();
    void addCluster(Cluster arg);
    double findDist(Cluster arg,Cluster arg2);
    void mergeClosest(unsigned int desiredClusters);
    void genDists(vector<Distances> * arg,unsigned int compLoc);
    void printDists(vector<Distances> arg);
    vector<Distances> findTwoLowest(vector<Distances> * arg); //finds the lowest and the second lowest distance
    vector<Cluster> getHolder();
    unsigned int getSize();
    double eucDist(vector<double> arg,vector<double> arg2,unsigned int dim);


};





#endif // CLUSTERING_H_INCLUDED

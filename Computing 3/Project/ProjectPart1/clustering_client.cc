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

vector<double> strToVec(char arg[])
{
    vector<double> temp;
    char *token = strtok(arg," ");
    while(token != NULL)
    {
        temp.push_back(atof(token));
        token = strtok(NULL," ");
    }
    return temp;
}

int main(int argc, char* argv[])
{
    string tempS;
    unsigned int numClusters,numInputs = 0,numDimensions,flag = 0;
    vector<string> inputsS;
    vector<vector<double> > clusters;
    ClusterHolder hold;
    for(unsigned int i = 0; *(argv[1]+ i) != '\0'; i++)
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
    numClusters = atof(argv[1]);
    while(getline(cin,tempS))
    {
        numInputs = numInputs + 1;
        inputsS.push_back(tempS);
    }
    for(unsigned int i = 0; i < inputsS.size(); i++)
    {
        clusters.push_back(strToVec(&inputsS[i][0]));
    }

    numDimensions = clusters[0].size();
    for(unsigned int i = 1; i < clusters.size(); i++)
    {
        if(clusters[i].size() != numDimensions)
        {
            cout << "The number of dimensions varies across the inputs" << endl;
            return 0;
        }
    }
    for(unsigned int i = 0; i < numInputs; i++)
    {
        Cluster temp(numDimensions);
        temp.addVect(clusters[i]);
        hold.addCluster(temp);
    }

    while(hold.getSize() != numClusters)
    {
        hold.mergeClosest();
    }
    hold.printHolder();


}

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using  std::cout;
using  std::cin;
using  std::endl;
using  std::vector;
using  std::string;
using  std::iter_swap;

void calcPerms(unsigned int pStart,vector<string> src,vector<string> *res)
{
    string temp = "";


    if(pStart == src.size())
    {
        for(unsigned int j = 0; j < src.size(); j++)
        {
            temp += src.at(j);
            if(j != src.size() - 1)
            {
                temp += " ";
            }
        }
        (*res).push_back(temp);
        temp = "";
    }

    for(unsigned int i = pStart; i < src.size(); i++)
    {
        swap(src.at(pStart),src.at(i));
        calcPerms(pStart+1,src,res);
        swap(src.at(pStart),src.at(i));
    }
}

void removeExtra(vector<string> *res) //removes duplicates
{
    for(unsigned int i = 0; i < res->size(); i++)
    {
        string temp = res->at(i);
        for(unsigned int j = i+1; j < res->size(); j++)
        {
            if(temp.compare(res->at(j)) == 0)
            {
                res->erase(res->begin() + j);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    string temp;
    vector<string> input,results;
    std::ifstream getInputs("input.txt");
    if (getInputs.is_open())
    {
        while(getline(getInputs,temp))
        {
            input.push_back(temp);
        }
        getInputs.close();
    }
    cout << "Permutations of: ";
    for(unsigned int i = 0;i < input.size();i++)
    {
        cout << input.at(i) << " ";
    }
    cout << endl << endl;
    calcPerms(0,input,&results);
    removeExtra(&results);
    for(unsigned int i = 0; i < results.size(); i++)
    {
        cout << i+1 << ". " << results.at(i) << endl;
    }
}








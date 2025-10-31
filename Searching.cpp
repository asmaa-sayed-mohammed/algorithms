#include "Searching.h"
#include <iostream>
using namespace std;
#include <vector>


Searching::Searching(int v, vector<int> arr)
{
    value = v;
    this->arr = arr;
}

int Searching::Recursive_Sequental_Search(int index)
{
    if(index >= arr.size())
    {
        cout<<"Value not found"<<endl;
        return -1;
    }
    if(arr[index] == value)
        return index;

    return Recursive_Sequental_Search(++index);

}




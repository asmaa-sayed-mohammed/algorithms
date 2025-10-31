//
// Created by compu city on 10/28/2025.
//

#ifndef SEARCHING_H
#define SEARCHING_H
#include <vector>
using namespace std;


class Searching {
    vector<int> arr;
    int value;
public:
    Searching(int v, vector<int> arr);
    int Recursive_Sequental_Search(int index = 0);

};



#endif //SEARCHING_H

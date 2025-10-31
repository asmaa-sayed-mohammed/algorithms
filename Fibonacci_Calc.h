#ifndef FIBONACCI_CALC_H
#define FIBONACCI_CALC_H
#include <vector>
using namespace std;

class Fibonacci_Calc
{
private:
    int num;

public:
    Fibonacci_Calc(int n);
    vector<vector<int>> Matrices_Multiplication(vector<vector<int>> &M1, vector<vector<int>> &M2);
    vector<vector<int>> Exponentiation(vector<vector<int>> M, int exp);
    int Fibonacci_byMatrix();

};
#endif //FIBONACCI_CALC_H

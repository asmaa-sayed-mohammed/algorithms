#include "Fibonacci_Calc.h"
#include <vector>
using namespace std;
#include <iostream>

Fibonacci_Calc :: Fibonacci_Calc(int n) : num(n) {}

vector<vector<int>> Fibonacci_Calc::Matrices_Multiplication(vector<vector<int>> &M1, vector<vector<int>> &M2)
{
    vector<vector<int>> Result(2, vector<int>(2));
    Result[0][0] = (M1[0][0] * M2[0][0]) + (M1[0][1] * M2[1][0]);
    Result[0][1] = (M1[0][0] * M2[0][1]) + (M1[0][1] * M2[1][1]);
    Result[1][0] = (M1[1][0] * M2[0][0]) + (M1[1][1] * M2[1][0]);
    Result[1][1] = (M1[1][0] * M2[0][1]) + (M1[1][1] * M2[1][1]);
    return Result;
}

vector<vector<int>> Fibonacci_Calc::Exponentiation(vector<vector<int>> M, int exp)
{
    vector<vector<int>> result(2,vector<int>(2));
    if(exp == 0) return {{1,0}, {0,1}};
    else if(exp == 1) return M;

    vector<vector<int>> halfPower = Exponentiation(M, exp/2);
    result = Matrices_Multiplication(halfPower, halfPower);

    if(exp % 2 == 1)
    {
        result = Matrices_Multiplication(result, M);
    }
    return result;
}

int Fibonacci_Calc::Fibonacci_byMatrix()
{
    if(num == 0) return 0;
    if(num == 1) return 1;
    vector<vector<int>> M = {{1,1}, {1,0}};
    vector<vector<int>> result = Exponentiation(M, num);
    return result[0][1];
}


#include <vector>
using namespace std;
#include <iostream>
class Fibonacci_Calc
{
public:

    vector<vector<int>> Matrices_Multiplication(vector<vector<int>> &M1, vector<vector<int>> &M2)
    {
        vector<vector<int>> Result(2, vector<int>(2));
        Result[0][0] = (M1[0][0] * M2[0][0]) + (M1[0][1] * M2[1][0]);
        Result[0][1] = (M1[0][0] * M2[0][1]) + (M1[0][1] * M2[1][1]);
        Result[1][0] = (M1[1][0] * M2[0][0]) + (M1[1][1] * M2[1][0]);
        Result[1][1] = (M1[1][0] * M2[0][1]) + (M1[1][1] * M2[1][1]);
        return Result;
    }

    vector<vector<int>> Exponentiation(vector<vector<int>> M, int exp)
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

    int Fibonacci_byMatrix(int num)
    {
        if(num == 0) return 0;
        if(num == 1) return 1;
        vector<vector<int>> M = {{1,1}, {1,0}};
        vector<vector<int>> result = Exponentiation(M, num);
        return result[0][1];
    }

    int Recursive_Fibonacci(int item){
        if(item==0||item==1){
            return item;
        }else {
            return Recursive_Fibonacci(item-1)+Recursive_Fibonacci(item-2);
        }
    }

    int dynamic_programming(int n){
        int arr[n] ;
        arr[0] = 0;
        arr[1] = 1;

        if (n == 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }
        else {
            for(int i = 2 ; i <= n ; i++){
                arr[n] = dynamic_programming(n-1)+ dynamic_programming(n-2);
            }
            return arr[n];
        }
    }
};


int main()
{
    while(true)
    {
        cout<<"Hello in Fibonacci Calculator\n1) Calculate Fibonacci number\n2) Exit\nChoose an option: ";
        int choice;
        cin>>choice;
        if(choice == 2)
            break;
        else if(choice == 1)
        {
            cout<<"\nWhich method do you want to use?\n1) Recursive Method\n2) Matrix Exponentiation Method\n3) Dynamic Programming Method\nChoose an option: ";
            int method;
            cin>>method;
            int n;
            cout << "Enter a number to find its Fibonacci: ";
            cin >> n;
            Fibonacci_Calc fibCalc;

            int fibNumber;
            if(method == 1)
            {
                fibNumber = fibCalc.Recursive_Fibonacci(n);
            }
            else if(method == 2)
            {
                fibNumber = fibCalc.Fibonacci_byMatrix(n);
            }
            else if (method == 3)
            {
                fibNumber = fibCalc.dynamic_programming(n);
            }

            else
            {
                cout<<"Invalid method option. Please try again.\n";
                continue;
            }
            cout << "Fibonacci number F(" << n << ") is: " << fibNumber << endl;
        }
        else
            cout<<"Invalid option. Please try again.\n";
    }

return 0;

}

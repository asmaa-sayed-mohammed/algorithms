#include <iostream>
#include <vector>
using namespace std;
class Fibonacci{
  public:
    int fibonacci(int item){
      if(item==0||item==1){
        return item;
      }else {
        return fibonacci(item-1)+fibonacci(item-2);
      }
    };
};

int main(){
  Fibonacci fibonacciElement = Fibonacci();
  cout << "insert the element";
  int item;
  cin >> item;
  int result = fibonacciElement.fibonacci(item);
  cout << result << endl;
}
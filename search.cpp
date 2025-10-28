#include <iostream>
#include <vector>
using namespace std;
class Search {
  public:
    vector<int> elements;
    Search(int size) {
      int element;

      for(int i = 0; i < size; i++) {
        cin >> element;
        elements.push_back(element);
      }
    };

    int sequentialSearch(int element) {
      int result;
      for (int i = 0; i < elements.size(); i++) {
        if (elements[i] == element) {
          return i;
        }
      }
      return -1;

    }
};


int main() {
  cout << "insert the size of elemnts" << endl;
  int size;
  cin >> size;
  cout << "insert the elements" << endl;
  Search search = Search(size);
  int element;
  cout << "insert the element to search" << endl;
  cin >> element;

  int result  = search.sequentialSearch(element);
  if(result == -1) {
    cout << "Element not found" << endl;
  }else{
    cout << "Element found at index " << result << endl;
  }
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
class Search {
  public:
    vector<int> elements;
    Search(){}

    void insertArray(int size) {
      int element;

      for (int i = 0; i < size; i++) {
        cin >> element;
        elements.push_back(element);
      }
    }

    int sequentialSearch(int element) {
      for (int i = 0; i < elements.size(); i++) {
        if (elements[i] == element) {
          return i;
        }
      }
      return -1;
    }

    int recursiveSequentialSearch(int element, int index = 0) {
        if (index >= elements.size()) {
          return -1;
        }
        if (elements[index] == element) {
          return index;
        }
        return recursiveSequentialSearch(element, ++index);
    }

    int recursiveBinarySearch(int target, vector<int> arr, int low, int high){
       sort(arr.begin(), arr.end());
       int midIndex = (low + high) / 2;
       int middle = arr[midIndex];
       if (low > high) {
         return -1;
       }
       if (middle == target) {
         return midIndex;
       }else if (target > middle) {
         return recursiveBinarySearch(target, arr, midIndex + 1, high);
       }else if (target < middle) {
         return recursiveBinarySearch(target, arr, low, midIndex - 1);
       }else {
         return -1;
       }
    }

  int binarySearch(vector<int> vec , int value){
      int low = 0;
      int height = vec.size()-1;
      while(low <= height){
        int middle = height - low;
        if (vec[middle] == value){
          return middle;
        }
        else if(vec[middle] < value){
          low = middle +1;
        }
        else{
          height = middle -1;
        }
      }
      return -1;
    }

  void implementSearch() {
      cout << "insert the size of elemnts" << endl;
      int size;
      cin >> size;
      cout << "insert the elements" << endl;
      Search search = Search();
      search.insertArray(size);
      int element;
      cout << "insert the element to search" << endl;
      cin >> element;

      cout << "Choose the type of search.\n";
      cout << " 1 - sequential search.\n";
      cout << " 2 - recursive sequential search\n";
      cout << " 3 - binary search.\n";
      cout << " 4 - recursive binary search.\n";
      cout << " 5 - exit\n";

      string input;
      while (true) {
        cin >> input;
        if (input == "1") {
          int result = search.sequentialSearch(element);
          if (result == -1) {
            cout << "No such element found" << endl;
          }else {
            cout << "The result is " << result << endl;
          }
          break;
        }
        else if (input == "2") {
            int result = search.recursiveSequentialSearch(element);
            if (result == -1) {
                cout << "Element not found" << endl;
            } else {
                cout << "Element found at index " << result << endl;
            }
            break;

        }
        else if (input == "3") {
          int result = search.binarySearch(search.elements, element);
          if(result == -1) {
            cout << "Element not found" << endl;
          }else {
            cout << "Element found at index " << result << endl;
          }
          break;
        }
        else if (input == "4") {
            int result  = search.recursiveBinarySearch(element, search.elements, 0, search.elements.size());
            if(result == -1) {
                cout << "Element not found" << endl;
            }else{
                cout << "Element found at index " << result << " after sorting "<< endl;
            }
            break;
        }
        else if (input == "5") {
          exit(0);
        }
        else {
          cout << "wrong input" << endl;
        }
      }
    }
};

int main() {
  Search search;
  search.implementSearch();
}



#include <iostream>
#include <vector>
using namespace std;
class heap{
public:
    vector<int> heapElements;
    //take elements to build the heap
    heap(){}
    void insertArray(int size) {
        int element;
        for (int i = 0; i < size; i++) {
            cin >> element;
            heapElements.push_back(element);
        }
    }

    //return the index of parent for an element
    static int parent(int i) {
        return (i - 1) / 2;
    }

    //return the index of left child for an element
    static int left(int i) {
        return 2 * i + 1;
    }

    //return the index of right child for an element
    static int right(int i) {
        return 2 * i + 2;
    }

    void maxHeapify(int index, int size) {
        int largest = index;
        int l = left(index);
        int r = right(index);

        if (l<size && heapElements[l] > heapElements[largest]) {
            largest = l;
        }
        if (r<size && heapElements[r] > heapElements[largest]) {
            largest = r;
        }
        if (largest != index) {
            swap(heapElements[index], heapElements[largest]);
            maxHeapify(largest, size);
        }
    }

    void buildMaxHeap() {
        //compute the size
        int size = heapElements.size();

        for (int i = (size / 2); i > 0 -1; i--) {
            maxHeapify(i, size);
        }
    }

    // get the largest element in the array then delete it
    int extractHeapMaximum() {
        int arrSize = heapElements.size();
        if (arrSize == 0) {
            cout<<"empty heap"<<endl;
            return -1;
        }else {
            int max = heapElements[0]; // get the largest number of heap
            swap(heapElements[0], heapElements[arrSize - 1]); // let it be the last node to delete it
            heapElements.pop_back(); // delete the max element
            arrSize = heapElements.size(); // update the size after deleting, or you can paa arrsize - 2 in maxHeapify
            maxHeapify(0, arrSize); // reheapify the array to be a valid heap
            return max; // return the max element
        }
    }

    // increase item in the heap and heapify it
    void heapIncreaseKey(int i, int key) {
        if (key < heapElements[i]) {
            cout<<"key is smaller than the old value"<<endl;
        }else {
            heapElements[i] = key;
            int parentIndex = parent(i);
            while (i > 0 && heapElements[parentIndex] < heapElements[i]) {
                swap(heapElements[i], heapElements[parentIndex]);
                i = parentIndex;
            }
        }
    }

    // add new value to the heap and confirm that it is agreed with heap's conditions
    void insert(int newValue) {
        heapElements.push_back(INT_MIN); // let the new element = - infinity then increase it to the new value
        int arrSize = heapElements.size();
        heapIncreaseKey(arrSize - 1, newValue);
        buildMaxHeap();
    }

    int extractHeapMinimum() {
        int arrSize = heapElements.size();
        if (arrSize == 0) {
            cout << "empty heap" << endl;
            return -1;
        }

        // search for the min item
        int minIndex = 0;
        for (int i = 1; i < arrSize; i++) {
            if (heapElements[i] < heapElements[minIndex]) {
                minIndex = i;
            }
        }

        int minValue = heapElements[minIndex];
        // swap with the last one and then delete it
        swap(heapElements[minIndex], heapElements[arrSize - 1]);
        heapElements.pop_back();

        // rebuild the heap
        buildMaxHeap();

        return minValue;
    }
    void heapSort(vector<int> &arr){
        buildMaxHeap();
        for(int i = arr.size()-1 ; i > 0 ;i--){
            swap(arr[0] , arr[i]);
            maxHeapify(0,i);
        }
    }
    void print(){
        for(int i = 0 ; i < heapElements.size() ; i++){
            cout << heapElements[i] << " ";
        }
        cout << endl << endl;
    }

};

// int main(){
//     heap h(7);
//     cout << "--- Initial Array/Heap Check ---" << endl;
//     h.buildMaxHeap();
//     cout << "After buildMaxHeap: ";
//     h.print();
//     h.heapSort(h.heapElements);
//     cout << "--- Heap Sort Test ---" << endl;
//     cout << "Sorted Array: ";
//     h.print();
//     h.insert(25);
//     cout << "After inserting 25: ";
//     h.print();
//     int maxVal = h.extractHeapMaximum();
//     cout << "Extracted Max: " << maxVal << endl;
//     cout << "Heap after ExtractMax: ";
//     h.print();
//
//     return 0;
// }
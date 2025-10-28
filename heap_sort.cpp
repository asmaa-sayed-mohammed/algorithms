#include <iostream>
#include <vector>
using namespace std;
class heap{
    vector<int> heapElements;
    //take elements to build the heap
    heap(int size) {
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

        for (int i = 0; i < (size / 2) -1; i++) {
            maxHeapify(i, size);
        }
    }

    // get the largest element in the array then delete it
    int extractHeapMaximum() {
        int arrSize = heapElements.size();
        if (arrSize == 0) {
            cout<<"empty heap"<<endl;
            return false;
        }else {
            int max = heapElements[0]; // get the largest number of heap
            swap(heapElements[0], heapElements[arrSize - 1]); // let it be the last node to delete it
            heapElements.pop_back(); // delete the max element
            arrSize = heapElements.size(); // update the size after deleting, or you can paa arrsize - 2 in maxHeapify
            maxHeapify(0, arrSize - 1); // reheapify the array to be a valid heap
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
            while (i > 0 && heapElements[parentIndex] > heapElements[i]) {
                swap(heapElements[i], heapElements[parentIndex]);
                i = parentIndex;
            }
        }
    }

    // add new value to the heap and confirm that it is agreed with heap's conditions
    void insert(int newValue) {
        heapElements.push_back(-1e9); // let the new element = - infinity then increase it to the new value
        int arrSize = heapElements.size();
        heapIncreaseKey(arrSize - 1, newValue);
    }

    int extractHeapMinimum() {
        int arrSize = heapElements.size();
        if (arrSize == 0) {
            cout << "empty heap" << endl;
            return false;
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


};

int main(){

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;


int bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int counter = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            counter++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return counter;
}


int selectionSort(vector<int>& arr) {
    int n = arr.size();
    int counter = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            counter++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    return counter;
}


void compareSorts(vector<int>& arr) {

    vector<int> arr1 = arr;
    vector<int> arr2 = arr;

    auto start = high_resolution_clock::now();
    int bubbleOps = bubbleSort(arr1);
    auto stop = high_resolution_clock::now();
    auto bubbleTime = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    int selectionOps = selectionSort(arr2);
    stop = high_resolution_clock::now();
    auto selectionTime = duration_cast<microseconds>(stop - start);

    cout << "Bubble Sort Time: " << bubbleTime.count() << " microseconds, Operations: " << bubbleOps << endl;
    cout << "Selection Sort Time: " << selectionTime.count() << " microseconds, Operations: " << selectionOps << endl;
}

int main() {
    
    int array_size = 1000;  // Change this size for larger or smaller tests
    vector<int> random_array(array_size);

    
    generate(random_array.begin(), random_array.end(), []() {
        return rand() % 10000;
    });

   
    compareSorts(random_array);

    return 0;
}

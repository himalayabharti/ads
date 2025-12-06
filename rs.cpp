//Randomizes select
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

int randomizedSelect(int arr[], int low, int high, int i) {
    if (low == high) {
        return arr[low];
    }
    
    int pi = randomizedPartition(arr, low, high);
    int k = pi - low + 1;
    
    if (i == k) {
        return arr[pi];
    } else if (i < k) {
        return randomizedSelect(arr, low, pi - 1, i);
    } else {
        return randomizedSelect(arr, pi + 1, high, i - k);
    }
}

int main() {
    srand(time(0));
    
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int i;
    cout << "Enter the value of i (1 to " << n << "): ";
    cin >> i;
    
    if (i < 1 || i > n) {
        cout << "Invalid value of i!" << endl;
        delete[] arr;
        return 1;
    }
    
    int result = randomizedSelect(arr, 0, n - 1, i);
    cout << "The " << i << "th smallest element is: " << result << endl;
    
    delete[] arr;
    return 0;
}

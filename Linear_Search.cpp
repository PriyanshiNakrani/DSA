#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;  
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int target = 9;

    int result = linearSearch(arr, arrSize, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {          
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) {         
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {24, 25, 47, 95, 14, 35};
    int n = sizeof(arr) / sizeof(arr[0]); 

    BubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

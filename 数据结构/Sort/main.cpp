#include <iostream>
#include <vector>
using namespace std;
//分区函数
int partition(vector<int>& arr, int low, int high) {
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
// 快速排序递归函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotPos = partition(arr, low, high);
        quickSort(arr, low, pivotPos - 1); 
        quickSort(arr, pivotPos + 1, high);
    }
}
// 堆排序：调整堆（大顶堆）
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;   
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
//堆排序主函数
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  
        heapify(arr, i, 0);    
    }
}
// 打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
int main() {
    vector<int> arr1 = { 3, 1, 4, 1, 5, 9, 2, 6 };
    vector<int> arr2 = arr1;
    cout << "原数组：";
    printArray(arr1);
    quickSort(arr1, 0, arr1.size() - 1);
    cout << "快速排序后：";
    printArray(arr1);
    heapSort(arr2);
    cout << "堆排序后：";
    printArray(arr2);
    return 0;
}
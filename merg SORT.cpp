//#include <iostream>
//using namespace std;
//
//void merge(int arr[], int start, int mid, int end) {
//	int a = mid - start + 1;
//	int b = end - mid;
//	int* startArr = new int[a];
//	int* endArr = new int[b];
//
//	for (int i = 0; i < a; i++) {
//		startArr[i] = arr[start + i];
//	}
//	for (int i = 0; i < b; i++) {
//		endArr[i] = arr[mid + 1 + i];
//	}
//	int i = 0, j = 0, k = start;
//
//	while (i < a && j < b) {
//		if (startArr[i] <= endArr[j]) {
//			arr[k] = startArr[i];
//			i++;
//		}
//		else {
//			arr[k] = endArr[j];
//			j++;
//		}
//		k++;
//	}
//
//	while (i < a) {
//		arr[k] = startArr[i];
//		i++;
//		k++;
//	}
//
//	while (j < b) {
//		arr[k] = endArr[j];
//		j++;
//		k++;
//	}
//
//	delete[] startArr;
//	delete[] endArr;
//}
//
//void mergeSort(int arr[], int start, int end)
//{
//	if (start >= end)
//		return;
//
//	int mid = start + (end - start) / 2;
//	mergeSort(arr, start, mid);
//	mergeSort(arr, mid + 1, end);
//	merge(arr, start, mid, end);
//}
//
//int main() {
//	const int size = 5;
//	int arr[size];
//	cout << "Enter the data in the array: ";
//	for (int i = 0; i < size; i++) {
//		cin >> arr[i];
//	}
//
//	mergeSort(arr, 0, size - 1);
//
//	cout << "Sorted array: ";
//	for (int i = 0; i < size; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
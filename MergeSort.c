#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {

  int n1 = mid - low + 1;
  int n2 = high - mid;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[low + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[mid + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = low;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  printf("Sorted array: \n");
  printArray(arr, size);
}

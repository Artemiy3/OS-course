#include <stdio.h>

void bubble_sort(int arr[], int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = i; j < length - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {3, 2, 9, 7, 5, 10, 4};
    bubble_sort(arr, 7);
    for(int i = 0; i < 7; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

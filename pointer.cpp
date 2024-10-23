#include <stdio.h>

int main () {
    int arr[5] = { 1, 2, 3, 4, 5};
    int *ptr = arr; //pointer points to the first element of the array

    //Accessing each element of the array using pointer arithmetic
    for (int i = 0; i < 5; ++i) {
        printf("Element %d: %d\n", i + 1, *(ptr + i));
    }
    return 0;
}
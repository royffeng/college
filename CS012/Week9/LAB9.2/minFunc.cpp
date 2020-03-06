#include "minFunc.h"
const int * min(const int arr[], int arrSize) {    
    //base cases
    if(arrSize < 1) {
        return 0;
    }else if(arrSize == 1) {
        return arr;
    }else if(arr[arrSize - 1] < *arr) {
        return min(arr + 1, arrSize -= 1);
    }else {
        return min(arr, arrSize -= 1);
    }
}


/*similar structure in a loop:

int smallestIndex = 0;
(int i = 0; i < arrSize - 1; i++) {
    if(arr[i] > arr[i + 1]){
        smallestIndex = i + 1;
    }
}

*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int n = numsSize - 1;
    while(i <= n)
    {
        if(*(nums+i) == val){
            *(nums+i) = *(nums+n);

            n--;
        } else{
            i++;
        }
    }

    return n + 1;
}

int main() {
    printf("LeetCode In C99!!!\n");
    printf("Problem 27: Remove Element In Place\n");

    int numbersArray[] = {3, 2, 2, 3};
    int value = 3;

    int k = removeElement((int *) &numbersArray, sizeof numbersArray / sizeof numbersArray[0], value);

    printf("[ ");
    for(int iter = 0; iter < sizeof numbersArray / sizeof numbersArray[0] ;iter++){
        printf("%d, ",numbersArray[iter]);
    }
    printf(" ]\n");

    printf("%d", k);

    return 0;
}

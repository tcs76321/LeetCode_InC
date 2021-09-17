#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0){return 0;}
    if(numsSize == 1){return 1;}
    int insertIndex = 1;
    int duplicateIndex = 1;
    while(duplicateIndex < numsSize){
        if(nums[duplicateIndex] != nums[duplicateIndex-1]){
            nums[insertIndex] = nums[duplicateIndex];
            insertIndex++;
        }
        duplicateIndex++;
    }
    return insertIndex;
}

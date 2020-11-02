
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    //Accepted	64 ms	6.6 MB	c
    
    int * resultArray = malloc(2*sizeof(int));
    
    int aims[numsSize];
    int i,j;
    
    aims[0] = target - nums[0];
    
    for(i = 1; i < numsSize ;i++){
        aims[i] = target-nums[i];
        for(j = i-1; j >= 0 ;j--){
            if(aims[j] == nums[i]){
                * returnSize = 2;
                resultArray[0] = i;
                resultArray[1] = j;
                return resultArray;
                }
            
        }
    }
    
    
    
    //Accepted	60 ms	6.8 MB	c
    
    //     int * resultArray = malloc(2*sizeof(int));

    //     int aims[numsSize];
    //     int i,j;

    //     for(i = 0; i < numsSize ;i++){
    //         aims[i] = target-nums[i];
    //         if(i != 0){
    //             for(j = i-1; j >= 0 ;j--){
    //                 if(aims[j] == nums[i]){
    //                     * returnSize = 2;
    //                     resultArray[0] = i;
    //                     resultArray[1] = j;
    //                     return resultArray;
    //                 }
    //             }
    //         }
    //     }
    
    * returnSize = 0;
    return 0;
    
    
    //BruteForce:
    //
    //Accepted	136 ms	6.6 MB	c
    //
    //     int * resultArray = malloc(2*sizeof(int));
    //     int i,j;
    //     resultArray[0] = 0;
    //     resultArray[1] = 1;
    //     for(i = 0; i < numsSize-1 ;i++){
    //         for(j = i+1; j < numsSize ;j++){
    //             if((nums[i] + nums[j]) == target){
    //                 resultArray[0] = i;
    //                 resultArray[1] = j;
    //                 * returnSize = 2;
    //                 return resultArray;
    //             }
    //         }
    //     }
    //     * returnSize = 0;
    //     return 0;
}

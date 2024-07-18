#include <stdlib.h>
#include <stdio.h>

/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++){
        for (int j = i + 1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    result[0] = 0;
    result[1] = 1;
    return result;

}


int main() {
    int nums[] = {2,7,11,15};
    printf("\nSize of nums: %d\n", (int) sizeof(*nums));
    printf("nums: ");
    for (int i = 0; i < (int) sizeof(*nums); i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    int target = 9;
    printf("Target: %d\n", target);
    int returnSize;
    int* result = twoSum(nums, (int) sizeof(nums), target, &returnSize);
    printf("Return size: %d\n", returnSize);
    printf("Result:");
    for (int i = 0; i < returnSize; i++){
        printf("%d ", result[i]);
    }
    printf("\n\n");
    free( result );
    return 0;
}
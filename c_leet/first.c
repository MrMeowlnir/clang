#include <stdlib.h>
#include <stdio.h>

struct hashTable {
    int key;
    int value;
    UT_hash_handle hh;
};

/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable* hashTable = NULL;
    struct hashTable* result = NULL;
    int* array = NULL;

    for (int i = 0; i < numsSize; i++){
        int x = target - nums[i];

        HASH_FIND_INT(hashTable, &x, result);
        if (result != NULL){
            array = malloc(sizeof(int) * 2);
            array[0] = result->value;
            array[1] = i;
            *returnSize = 2;
            return array;
        }

        struct hashTable* item = malloc(sizeof(struct hashTable));
        item->key = nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item)
    }

    *returnSize = 0;
    return NULL;
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
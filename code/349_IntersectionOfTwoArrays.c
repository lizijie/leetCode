#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define HASH_BUCKET 8

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if (nums1Size <= 0 || nums2Size <= 0)
    {
        return NULL;
    }

    int tableSize = (nums1Size + nums2Size) * 8 * sizeof(int);
    int* table = (int*) malloc(tableSize);
    memset(table, 0, tableSize);

    int flagSize = (nums1Size + nums2Size) * 8;
    bool* flag = (bool*) malloc(flagSize * sizeof(bool));
    for (int i = 0; i < flagSize; ++i)
    {
        flag[i] = false;
    }

    bool isNum1Zero = false;

    for (int i = 0; i < nums1Size; ++i)
    {
        int value = nums1[i];
        int bucket_idx = value % HASH_BUCKET;

        if (value == 0)
        {
            isNum1Zero = true;
            continue;
        }

        while (table[bucket_idx] != 0 && table[bucket_idx] != value)
        {
            ++bucket_idx; 
        }

        if (table[bucket_idx] != value)
        {

            table[bucket_idx] = value;
        }
    }

    bool isNum2Zero = false;
    for (int i = 0; i < nums2Size; ++i)
    {
        int value = nums2[i];
        int bucket_idx = value % HASH_BUCKET;

        if (value == 0)
        {
            isNum2Zero  = true;
            continue;
        }

        while (table[bucket_idx] != 0 && table[bucket_idx] != value)
        {
            ++bucket_idx; 
        }

        if (table[bucket_idx] == value)
        {
            flag[bucket_idx] = true;
        }
    }

    *(returnSize) = 0;
    for (int i = 0; i < flagSize; ++i)
    {
        if (flag[i] == true)
        {
            ++*(returnSize);
        }
    }

    if (isNum1Zero && isNum2Zero)
    {
        ++*(returnSize);
    }

    if ((*returnSize) <= 0)
    {
        free(table);
        free(flag);
        return NULL;
    }

    int* returnTable = (int*)malloc(*(returnSize) * sizeof(int));
    for (int i = 0, j = 0; i < flagSize; ++i)
    {
        if (flag[i] == true)
        {
            returnTable[j] = table[i];
            ++j;
        }
    }

    if (isNum1Zero && isNum2Zero)
    {
        returnTable[(*returnSize) - 1] = 0;
    }

    free(table);
    free(flag);

    return returnTable;
            
}

int main()
{
#define N1_SIZE 6
#define N2_SIZE 9

    int n1[N1_SIZE] = {4,7,9,7,6,7};
    int n2[N2_SIZE] = {5,0,0,6,1,6,2,2,4};

    int size = 0;
    int* tb = intersection(n1, N1_SIZE, n2, N2_SIZE, &size);

    printf("\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d,", tb[i]);
    }
    printf("\n");
    return 0;
}

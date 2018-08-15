#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int mid = numsSize / 2;
    int result = nums[mid];

    for (int i = 0, j = numsSize - 1; i < j; ++i, --j)
    {
       result ^= nums[i] ^ nums[j];
    }

    return result;
}

int main()
{
#define SIZE 5
    int ary[SIZE] = {4,1,2,1,2};
    printf("%d\n", singleNumber(ary, SIZE));
    return 0;
}

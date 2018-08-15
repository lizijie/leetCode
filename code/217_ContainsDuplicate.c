#include <stdio.h>


bool containsDuplicate(int* nums, int numsSize) {
   for (int i = 1; i < numsSize; ++i)
   {
       int guide = nums[i];
        
       int left = 0;
       int right = i - 1;
       while (left <= right)
       {
           int mid = (int)((left + right) / 2);
          if (nums[mid] == guide) 
          {
              return true;
          }
          else if (guide < nums[mid])
          {
              right = mid - 1;
          }
          else if (guide > nums[mid])
          {
              left = mid + 1;
          }
       }

       for (int j = i; j > left; --j)
       {
          nums[j] = nums[j-1];
       }

       nums[left] = guide;
   }      

   return false;
}

int main()
{
#define  size 4
    int ary[size] = {3,2,1, 1};
    printf("%d\n", containsDuplicate(ary, size));
    return 0;
}


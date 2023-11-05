#include <stdio.h>

void quick(int *nums, int left, int right) {
    if (left > right){
        return;
    }

    int tmp = nums[left];
    int i = left;
    int j = right;

    while (i != j) {
        while(nums[j] >= tmp && j > i) {
            j--;
        }

        while(nums[i] <= tmp && j > i) {
            i++;
        }

        if (j > i) {
            int t = nums[j];
            nums[j] = nums[i];
            nums[i] = t;
        }
    }

    nums[left] = nums[i];
    nums[i] = tmp;

    quick(nums, left, i - 1);
    quick(nums, i + 1, right);

}

int bsearch(int *nums, int n, int target)
{

}

int main()
{
    int nums[] = {2,4,6,4,3,7,8,9,10};
    int len = sizeof(nums) / sizeof(int);

    quick(nums, 0, len -1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("%d\n", bsearch(nums, len, 9));

    return 0;

}
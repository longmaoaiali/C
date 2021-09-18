int partition(int* nums, int startIndex, int endIndex) {
    int value = nums[startIndex];

    while (startIndex < endIndex) {

        while (startIndex < endIndex && nums[endIndex] >= value)
            endIndex--;

        nums[startIndex] = nums[endIndex];

        while (startIndex < endIndex && nums[startIndex] <= value)
            startIndex++;

        nums[endIndex] = nums[startIndex];
    }

    nums[startIndex] = value;
    return startIndex;

}

void quickSort(int* nums, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int position = partition(nums, startIndex, endIndex);
        quickSort(nums, startIndex, position - 1);
        quickSort(nums, position + 1, endIndex);
    }

}

int min(int a, int b) {
    return a < b ? a : b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    //快排两个数组
    if (nums1 == NULL || nums2 == NULL || nums1Size == 0 || nums2Size == 0)
        return NULL;

    quickSort(nums1, 0, nums1Size - 1);

    quickSort(nums2, 0, nums2Size - 1);

    *returnSize = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    int* array = (int *)malloc(sizeof(int) * min(nums1Size, nums2Size));

    while (i<nums1Size && j<nums2Size) {
        if (nums1[i] == nums2[j]) {
            array[count] = nums1[i];
            count++;

            i++;
            j++;

        }
        else {
            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
    }
    *returnSize = count;

    return array;

}
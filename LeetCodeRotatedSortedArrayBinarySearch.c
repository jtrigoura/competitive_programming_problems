//
// Created by jorge on 12/16/2023.
//
#include <stdio.h>

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (nums[mid] == target){
            return mid;
        }
        // Handle duplicates
        while (left < mid && nums[left] == nums[mid]){
            left++;
        }if (nums[left] <= nums[mid]){
            // Left half is sorted
            if (nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }else{
            // Right half is sorted
            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
    return -1;
}
/*int main(){
    int nums[7]={5, 6, 0, 1, 2, 3, 4};
    printf("%d",search(nums,7,0));
}*/
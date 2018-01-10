//
//  main.cpp
//  LeetCode33_SearchInRotateArray
//
//  Created by Rui on 1/9/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            if(target == nums[mid])
                return mid;
            if(nums[mid] < nums[right]) // if the right part is in order
            {
                if(target > nums[mid] && target <= nums[right]) //check if the target is in the right part
                    left = mid + 1;//if in , let the left is the first number in the right
                else
                    right = mid - 1;//if not, let the right is the last number in the left
            }else{//if the left part is in order
                if(target < nums[mid] && target >= nums[left]) //check if the target is in the left part
                    right = mid - 1;//if in,let the right is the last number in the left
                else
                    left = mid + 1;//if not, let the left is the first number in the right
            }
        }
        
        return -1;
    }
    
};

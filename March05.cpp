// key concept of binary search
// IDENTIFY THE HALF THAT YOU ARE SURE TO ELIMINATE

// Search element in rotated sorted array-1
// 2 STEPS
// 1. Identify the sorted half.
// 2. Check if target can lie in that half. If not then go to the unsorted half.

class Solution {
public:
    int search(vector<int>& nums, int x) {
        int n = nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==x) return mid;
            //if left half is sorted
            if(nums[mid]>=nums[low]){
                if(x>=nums[low] && x<=nums[mid]){
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
            //if right half is sorted
            else{
                if(x>=nums[mid] && x<=nums[high]){
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};


// Search element in rotated sorted array-2
// With duplicates
// an edge case should be handled where we can't figure out which half is sorted or not

class Solution {
public:
    bool search(vector<int>& nums, int x) {
        int n = nums.size();
        int low=0, high=n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==x) return true;
            
            //EDGE CASE
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            
            if(nums[mid]>=nums[low]){
                if(x>=nums[low] && x<=nums[mid]){
                    high=mid-1;
                } else {
                    low=mid+1;
                }
            } else {
                if(x>=nums[mid] && x<=nums[high]){
                    low=mid+1;
                } else {
                    high=mid-1;
                }
            }
        }
        return false;
    }
};

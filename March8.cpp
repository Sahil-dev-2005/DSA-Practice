// Finding single element in a sorted array

// Steps
// 1. starting with low=1 and high=n-2 to avoid writing too many conditions inside the loop. Instead checking it before itself and return the value.
// 2. For figuring out which half to eliminate, we have used an Observation-
//    (even,odd) => unique element lies on right.
//    (odd,even) => unique element lies on left.
// This means if you (mid) are at even index and the number next to you is same as you => you haven't crossed unique element and it's on your right.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=1, high=n-2;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            } else {
                if(mid%2==0){
                    if(nums[mid]==nums[mid+1]){
                        low=mid+1;
                    } else {
                        high=mid-1;
                    }
                } else {
                    if(nums[mid]==nums[mid-1]){
                        low=mid+1;
                    } else {
                        high=mid-1;
                    }
                }
            }
        }
        return -1;
    }
};

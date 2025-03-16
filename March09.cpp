// Finding Peak element in a sorted array

// STEPS
// 1. starting with low=1 and high=n-2. Add relevant conditions and return.
// 2. Figuring out if element you are on by comparision with adjacent elements, lies at climbing edge or falling edge helps you 
//    figure out on which side peak might be and hence gives you the half which can be removed.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low=1, high=n-2;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid-1]){
                if(nums[mid]>nums[mid+1]){
                    return mid;
                }
                low=mid+1;
            } else{
                high=mid-1;
            }
        }
        return -1;
    }
};

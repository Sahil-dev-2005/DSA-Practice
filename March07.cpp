// FIND NUMBER OF TIMES THE ARRAY HAS BEEN ROTATED USING BINARY SEARCH

// Just find the minimum element. the index of minimum element gives you how many times array has been rotated.

class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        int low=0, high=n-1;
        int ans= INT_MAX;
        int indx = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[low]<=nums[mid]){
                if(nums[low]<ans){
                    ans = nums[low];
                    indx=low;
                }
                low = mid+1;
            } else {
                if(nums[mid]<ans){
                    ans = nums[mid];
                    indx=mid;
                }
                high = mid-1;
            }
        }
        return indx;
    }
};

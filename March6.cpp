// FIND MINIMUM IN A ROTATED SORTED ARRAY
// 1. identify sorted half.
// 2. consider first element of sorted half as answer.
// 3. go to other half.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0, high=n-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=nums[low]){
                ans=min(nums[low],ans);
                low=mid+1;
            } else {
                ans=min(nums[mid],ans);
                high=mid-1;
            }
        }
        return ans;
    }
};

// Finding First and last occurence of a number in a sorted array
// USING SIMPLE BINARY SEARCH

class Solution {
public:
    int First(vector<int>& a, int n, int x){
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(a[mid]==x){
                ans=mid;
                high=mid-1;
            } else if(a[mid]>x){
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
    int Last(vector<int>& a, int n, int x){
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(a[mid]==x){
                ans=mid;
                low=mid+1;
            } else if(a[mid]>x){
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int a = First(nums,n,target);
        int b = Last(nums,n,target);
        return {a,b};
    }
};

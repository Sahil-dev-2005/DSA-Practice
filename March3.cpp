//Finding first and last occurence of a given number in sorted array

//Solution using concept of lower and upperBound
class Solution {
public:
    int lowerBound(vector<int>& a, int x){
        int n = a.size();
        int low=0, high=n-1;
        int ans=n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(a[mid]>=x){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if(ans==n || a[ans]!=x) return -1;
        else return ans;
    }
    int upperBound(vector<int>& a, int x){
        int n = a.size();
        int low=0, high=n-1;
        int ans=n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(a[mid]>x){
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        if(ans==0 || a[ans-1]!=x) return -1;
        else return ans-1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(lowerBound(nums,target));
        res.push_back(upperBound(nums,target));
        return res;
    }
};

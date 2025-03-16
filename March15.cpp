// Find Kth missing positive integer

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=0,n=arr.size(); i<n; i++){
            if(arr[i]>k){
                break;
            } else {
                k++;
            }
        }
        return k;
    }
};

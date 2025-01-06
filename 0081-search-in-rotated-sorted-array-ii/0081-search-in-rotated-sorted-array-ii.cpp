class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==target){
                return true;
            }
            if(arr[l]==arr[mid] && arr[mid]==arr[r] && l<=r){
                l++;
                r--;
            }
            else if(arr[l]<=arr[mid]){
                if(arr[l]<=target && target<=arr[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(arr[mid]<=target && target<=arr[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return false;

    }
};
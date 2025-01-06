class Solution {
public:
    int search(vector<int>& arr, int target) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=arr.size(),i=0,j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[i]<=arr[mid]){
                if(arr[i]<=target && target<=arr[mid]){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
            else{
                if(arr[mid]<=target && target<=arr[j]){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
        }
        return -1;
    }
};
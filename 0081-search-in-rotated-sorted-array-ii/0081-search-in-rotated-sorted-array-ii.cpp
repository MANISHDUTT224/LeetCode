class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==target){
                return true;
            }
            if(arr[i]==arr[mid] && arr[j]==arr[mid]){
                i++;
                j--;
            }
            else if(arr[i]<=arr[mid]){
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
        return false;
    }
};
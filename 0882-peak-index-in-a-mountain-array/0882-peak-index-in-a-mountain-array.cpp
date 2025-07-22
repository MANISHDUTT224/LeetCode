class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int ans=n;
        int i=0,j=n-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(arr[mid]>arr[mid+1]){
                ans=mid;
                j=mid;
            }
            else{
              
                i=mid+1;
            }
        }
        return ans;

    }
};
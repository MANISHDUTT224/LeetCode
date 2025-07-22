class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int target=2*arr[i];
            int j=0,k=arr.size()-1;
            while(j<=k){
                int mid=j+(k-j)/2;
                if(arr[mid]==target){
                if(mid!=i){
                    return true;
                }
                else{
                    break;
                }
                }
                else if(arr[mid]<target){
                    j=mid+1;
                }
                else{
                    k=mid-1;
                }
            }
        }
        return false;
    }
};
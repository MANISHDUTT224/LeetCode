/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int i=0,j=mountainArr.length()-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        int peakindex=i;
        int low=0,high=peakindex;
       
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)>target){
                high=mid-1;
            }
            else if(target>mountainArr.get(mid)){
                low=mid+1;
            }
            else{
                return mid;
            }
        }
        low=peakindex+1,high=mountainArr.length()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(mountainArr.get(mid)<target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};
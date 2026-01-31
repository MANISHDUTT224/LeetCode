class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(letters[mid]<=target){
                i=mid+1;
            }
            else{
                ans=mid;
                j=mid-1;
            }
        }
        return letters[ans];
    }
};
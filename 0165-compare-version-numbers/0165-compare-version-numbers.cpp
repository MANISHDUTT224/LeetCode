class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,n=version1.size(),j=0,m=version2.size();
        while(1){
           long long num1=0,num2=0;
           while(i<n && version1[i]!='.'){
            num1=num1*10+version1[i]-'0';
            i++;
           }
           while(j<m && version2[j]!='.'){
            num2=num2*10+version2[j]-'0';
            j++;
           }
           if(num1>num2){
            return 1;
           }
           else if(num2>num1){
            return -1;
           }
           if(i>=n && j>=m){
            return 0;
           }
           i++;
           j++;
        }

        return 0;
    }
};
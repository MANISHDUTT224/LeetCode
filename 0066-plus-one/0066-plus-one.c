/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int size=1;
    for(int i=digitsSize-1;i>=0;i--){
        size+=digits[i];
        size/=10;
    }
    int *arr=malloc((digitsSize+size)*sizeof(int));
    *returnSize=digitsSize+size;
    int sum=0;
    int r=1;
    int j=*returnSize-1;
    for(int i=digitsSize-1;i>=0;i--){
        sum=r+digits[i];
        r=sum/10;
        sum%=10;
        arr[j--]=sum;
    }
    if(r==1){
        arr[0]=r;
    }
    return arr;
}
class Solution {
    public String multiply(String num1, String num2) {
        boolean negative=false;
        if(num1.charAt(0)=='-' && num2.charAt(0)!='-'){
            num1=num1.substring(1);
            negative=true;
        }
        else if(num2.charAt(0)=='-' && num1.charAt(0)!='-'){
            num2=num2.substring(1);
            negative=true;
        }
        else if(num1.charAt(0)=='-' && num2.charAt(0)=='-'){
            
            num1=num1.substring(1);
            num2=num2.substring(1);
        }

        if(num1.charAt(0)=='0' || num2.charAt(0)=='0'){
            return "0";
        }
        int n=num1.length(),m=num2.length();
        int res[]=new int[n+m];
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mul=(num1.charAt(i)-'0')*(num2.charAt(j)-'0');
                int sum=mul+res[i+j+1];
               res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
            }
        }
        int i=0;
        StringBuilder sb=new StringBuilder();
        while(i<res.length && res[i]==0){
            i++;
        }
        for(;i<res.length;i++){
            sb.append(res[i]);
        }
        return sb.toString();
        
    }
}
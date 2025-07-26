class Solution {
    public String decodeString(String s) {
        Stack<Integer>digitsSet=new Stack<>();
        Stack<String>resultSet=new Stack<>();
        char []strs=s.toCharArray();
        String curr="";
        int index=0;
        while(index<s.length()){
            if(Character.isDigit(strs[index])){
                int num=0;
                while(Character.isDigit(strs[index])){
                    num=num*10+(strs[index]-'0');
                    index++;
                }
                digitsSet.push(num);
            }
            else if(strs[index]=='['){
                resultSet.push(curr);
                curr="";
                index++;
            }
            else if(strs[index]==']'){
                int digit=digitsSet.pop();
                StringBuilder sb=new StringBuilder(resultSet.pop());
                for(int i=0;i<digit;i++){
                    sb.append(curr);
                }
                curr=sb.toString();
                index++;
            }
            else{
                curr+=strs[index];
                index++;
            }
        }
        return curr;

    }
}
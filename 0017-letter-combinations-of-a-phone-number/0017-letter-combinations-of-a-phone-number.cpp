class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>op;
        vector<string>phone_map={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty()){
            return {};
        }
        backtrack("",digits,phone_map,op);
        return op;
    }
    void backtrack(string comb,string digits,vector<string>phone_map,vector<string>&op){
        if(digits.empty()){
            op.push_back(comb);
        }
        else{
            string letters=phone_map[digits[0]-'2'];
            for(char letter:letters){
            backtrack(comb+letter,digits.substr(1),phone_map,op);
            }
        }
    }
};
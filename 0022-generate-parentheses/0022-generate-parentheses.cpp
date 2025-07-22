class Solution {
private:
void generate(int open,int close,vector<string> &result,string &current){
    if(open==0 && close==0){
        result.push_back(current);
        return;
    }

    if(open>0){
        current.push_back('(');
        generate(open-1,close,result,current);
        current.pop_back();
    }

    if(close>open){
        current.push_back(')');
        generate(open,close-1,result,current);
        current.pop_back();
    }
}
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate(n,n,result,current);
        return result;
    }
};
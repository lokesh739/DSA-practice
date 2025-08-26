class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int opencount=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                opencount++;
                maxi=max(maxi,opencount);
            }
            else if(s[i]==')'){
                opencount--;
            }
        }
        return maxi;
    }
};
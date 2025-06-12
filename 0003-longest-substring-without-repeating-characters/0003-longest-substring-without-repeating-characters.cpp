class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        int maxlength=0;
        int left=0;
        int right=0;
        int hash[256]={-1};
        while(right<n){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left){
                    left=hash[s[right]]+1;
                }
            }
            int length=right-left+1;
            hash[s[right]]=right;
            maxlength=max(maxlength,length);
            right++;
        }
        return maxlength;
    }
};
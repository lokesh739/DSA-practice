class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();

        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int count=n;
        for(int i=0;i<n;i++){
            if(mp.find(t[i])!=mp.end() && mp[t[i]]>0) {
                mp[t[i]]--;
                count--;
            }
        }
        if(count==0) return true;
        return false;
    }
};
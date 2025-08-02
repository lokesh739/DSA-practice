class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n==0) return 0;

        int aheadnotbuy,aheadbuy,currnotbuy,currbuy;
        aheadnotbuy=aheadbuy=0;

        for(int i=n-1;i>=0;i--){
            currbuy=max(-prices[i]-fee+aheadnotbuy,aheadbuy);
            currnotbuy=max(prices[i]+aheadbuy,aheadnotbuy);

            aheadnotbuy=currnotbuy;
            aheadbuy=currbuy;
        }
        return aheadbuy;
    }
};
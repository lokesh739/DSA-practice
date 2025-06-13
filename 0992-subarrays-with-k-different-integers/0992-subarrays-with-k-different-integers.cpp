class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        int l = 0;
        int r = 0;
        unordered_map<int, int> freq;
        while (r < n) {
            freq[nums[r]]++;
            while (freq.size() > goal) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l = l + 1;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    int atMostKDistinctMinusOne(vector<int>& nums, int goal) {
        if (goal <= 0) return 0;
        int n = nums.size();
        int count = 0;
        int l = 0;
        int r = 0;
        unordered_map<int, int> freq;
        while (r < n) {
            freq[nums[r]]++;
            while (freq.size() > goal - 1) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l = l + 1;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinctMinusOne(nums, k);
    }
};

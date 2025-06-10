class Solution {
public:
    vector<int> nextsmaller(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> previoussmallerequal(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long sum = 0;

        vector<int> nse = nextsmaller(arr);
        vector<int> psee = previoussmallerequal(arr);

        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            sum = (sum + (1LL * left * right % mod) * arr[i] % mod) % mod;
        }

        return sum;
    }

    vector<int> nextGreater(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> previousGreaterEqual(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> pge(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long sum = 0;

        vector<int> nge = nextGreater(arr);
        vector<int> pge = previousGreaterEqual(arr);

        for (int i = 0; i < n; i++) {
            int left = i - pge[i];
            int right = nge[i] - i;
            sum = (sum + (1LL * left * right % mod) * arr[i] % mod) % mod;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        // ⚠️ Do NOT apply modulo on the final result
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

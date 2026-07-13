/*class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;          // stores indices
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            // First window is ready
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k)
            return {};
        vector<int> ans;
        // Maximum of the first window
        int max1 = nums[0];
        for (int i = 1; i < k; i++)
            max1 = max(max1, nums[i]);
        ans.push_back(max1);
        // Process remaining windows
        for (int i = k; i < nums.size(); i++) {
            // If the outgoing element was the maximum,
            // recompute the maximum of the new window.
            if (nums[i - k] == max1) {
                max1 = nums[i - k + 1];
                for (int j = i - k + 1; j <= i; j++)
                    max1 = max(max1, nums[j]);
            }
            else {
                // Otherwise only compare with the new element.
                max1 = max(max1, nums[i]);
            }
            ans.push_back(max1);
        }
        return ans;
    }
};
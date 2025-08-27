class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            pq.push({arr[i], i});

            if (i >= k - 1) {

                while (pq.top().second <= i - k) {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};

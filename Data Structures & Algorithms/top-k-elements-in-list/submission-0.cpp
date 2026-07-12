class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*method 1: take a max heap, put everything in it, 
        pop out the top k.
        method 2: take a min heap of size k. put in first k ele,
        then pop the min, add next till all are done. top k left
        */
        unordered_map<int,int> freq;//(ele,freq)
        for(int x: nums) freq[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &p: freq){
            pq.push({p.second, p.first});//freq,ele
            if(pq.size()>k) pq.pop(); 
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }   
        return ans;          
    }
};

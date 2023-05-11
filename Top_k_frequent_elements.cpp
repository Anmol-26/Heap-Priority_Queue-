class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>hash;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        vector<int>ans;
        for(int i: nums)
        {
            hash[i]++;
        }
        for(auto j : hash)
        {
            minh.push({j.second, j.first});
            if (minh.size()>k)
            {
                minh.pop();
            }
        }
        while(k--)
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};

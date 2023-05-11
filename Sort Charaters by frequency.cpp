class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,int>>maxh;
        map<int,int>hash;
        string ans;
        for(auto i: s)
        {
            hash[i]++;
        }
        for(auto j: hash)
        {
            maxh.push({j.second,j.first});
        }
        while(maxh.size()!=0)
        {
            int freq=maxh.top().first;
            int key=maxh.top().second;
            for(int i=0;i<freq;i++)
            {
                ans.push_back(key);
            }
            maxh.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>maxh;
        vector<vector<int>>ans;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int s=nums1[i]+nums2[j];
                if(maxh.size()<k)
                {
                    maxh.push({s,{nums1[i],nums2[j]}});
                }
                else if(s<maxh.top().first)
                {
                    maxh.pop();
                    maxh.push({s,{nums1[i],nums2[j]}});
                }
                else
                {
                    break;
                }
            }
        }
        while(maxh.size()!=0)
        {
            ans.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        map<int,int> m;
        m[INT_MIN]=0;
        for(int i=0;i<n;i++){
            auto it=m.upper_bound(nums[i]);
            int curr=1;
            if(it!=m.begin()){
                it--;
                if(it->first <nums[i]){
                    curr=curr+it->second;
                }
            }
            m[nums[i]]=max(m[nums[i]],curr);
            ans=max(ans,m[nums[i]]);
            it=m.upper_bound(nums[i]);
            while(it!=m.end() && it->second<=m[nums[i]]){
                m.erase(it++);
            }

        }
        return ans;
    }
};

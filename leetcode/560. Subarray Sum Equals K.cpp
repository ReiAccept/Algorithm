class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,sum=0;
        map<int,int> m; m[0]=1;
        for(auto x : nums)
        {
            sum+=x;
            ans+=m[sum-k]; //计算从第0个元素到当前元素的和
            //如果m[sum-k]存在,则意味着在前面有m[sum-k]个连续数组可以减掉等于k
            //其实也类似前缀和,的存在,将遍历前缀和那一遍变成了有几个前缀的值,也就是前缀和做法里面的内重循环所做的
            m[sum]++; //用哈希表保存出现过的累积和sum的次数(有负数,会减小)
        }
        return ans;
        // int pre[20003]; pre[0]=nums[0]; int ans=0;
        // for(int i=1;i<nums.size();i++)
        // {
        //     pre[i]=pre[i-1]+nums[i];
        // }
        // for(int i=nums.size()-1;i>=0;i--)
        // {
        //     if(pre[i]==k) ans++;
        //     for(int j=i-1;j>=0;j--)
        //     {
        //         if(pre[i]-pre[j] == k) ans++;
        //     }
        // }
        // return ans;
    }
};

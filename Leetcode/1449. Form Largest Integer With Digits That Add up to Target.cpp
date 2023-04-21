class Solution {
public:
    string largestNumber(vector<int> &cost, int target) {
        vector<int> f(target+1,INT_MIN); f[0]=0;
        for(auto c : cost) {
            for(int i=c;i<=target;i++) {
                f[i]=max(f[i],f[i-c]+1);
            }
        }
        if(f[target]<0) {
            return "0";
        }
        string ans;
        for(int i=8;i>=0;i--) {
            for(int c=cost[i];target>=c && f[target]==f[target-c]+1;target-=c) {
                ans+=to_string(i+1);
            }
        }
        return ans;
    }
};

class Solution {
public:
  int lowbit(int x) { return x & (-x); }
  vector<int> minBitwiseArray(vector<int> &nums) {
    vector<int> ans;
    for (auto &x : nums) {
      ans.push_back(x == 2 ? -1 : x ^ (lowbit(~x) >> 1));
    }
    return ans;
  }
};


// x=0b111     x|(x+1)=0b111    | 0b1000   = 0b1111    lowbit(x) = 0b1   ~x=-0b1000     lowbit(~x)=0b1000
// x=0b100111  x|(x+1)=0b100111 | 0b101000 = 0b101111  lowbit(x) = 0b1   ~x=-0b101000   lowbit(~x)=0b1000
// x=0b101010  x|(x+1)=0b101010 | 0b101011 = 0b101011  lowbit(x) = 0b10  ~x=-0b101011   lowbit(~x)=0b1
// x 的二进制表示中, 最低位的 0 在第 k 位, 则 x+1 就是将后 k-1 位的 1 变成 0, 然后将 k 位变为 1
// 接着 x|(x+1), 结果也就是将 x 的最低位 0 变成 1
// 那么我们要求最小, 显然应该选择 末尾连续 1 串中最高位的 1
// 首先我们对 x 取反 ~x
// lowbit(~x)>>1 即可得到末尾连续 1 串中最高位的 1
// 那我们接着对其和 x 做异或运算即可（除了要消除的那位以外, 其他位全都不一样）
// ans=x^(lowbit(~x)>>1)

// 讨论无解的情况
// x|(x+1) 的最低位一定是 1, 所以一定是奇数
// 题目保证了素数, 所以我们知道只有素数里只有 2 是偶数, 无解

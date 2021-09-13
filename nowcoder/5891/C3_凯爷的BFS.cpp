#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int N = 1e6+7;

template <int _MOD> struct Mint {
  int v = 0;
  Mint() {}
  Mint(int _v) : v((_v%_MOD+_MOD)%_MOD) {}
  Mint(long long _v) : v(static_cast<int>((_v%_MOD+_MOD)%_MOD)) {}
  Mint operator = (const int &_v) { return *this = Mint(_v); }
  Mint operator + (const Mint &b) const { return Mint(v+b.v); }
  Mint operator * (const Mint &b) const { return Mint(1ll*v*b.v); }
  Mint& operator += (const Mint &b) { return *this = *this+b; }
  Mint& operator *= (const Mint &b) { return *this = *this*b; }
  Mint pow(int p) const {
    Mint res(1), x(*this);
    while (p) {
      if (p&1) res = res*x;
      x *= x;
      p >>= 1;
    }
    return res;
  }
  Mint inv() const { return pow(_MOD-2); }
  friend ostream& operator << (ostream &os, const Mint &mt) { return os << mt.v; }
};
using mint = Mint<MOD>;

int n, m;
int d[N];
vector<int> e[N];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    if (n <= 1) return 0;
    mint res = 0;
    memset(d+1, -1, sizeof(int)*n);
    d[1] = 0;
    q.push(1);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (const int &v : e[u])
        {
            if (d[v] != -1) continue;
            d[v] = d[u]+1;
            q.push(v);
            res += mint(2).pow(d[v]);
        }
    }
    cout<<res<<endl;
    return 0;
}

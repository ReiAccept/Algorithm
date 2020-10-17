#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n;
int a[100003], y[100003];
vector<pii> res;
vector<int> vec;

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",a+i);
    int cnt = n;
    for (int i = n; i>=1; i--)
    {
        if (a[i] == 1)
        {
            y[i] = cnt--;
            res.emplace_back(y[i], i);
            vec.push_back(i);
        }
        else if (a[i] == 2)
        {
            if (vec.empty())
            {
                printf("-1\n");
                return 0;
            }
            y[i] = y[vec.back()];
            vec.pop_back();
            res.emplace_back(y[i], i);
        }
    }
    for (int i = 1; i <= n; i++) if (a[i] == 2) vec.push_back(i);
    sort(vec.begin(), vec.end());
    for (int i = n; i>=1; i--) 
        if (a[i] == 3)
        {
            if (vec.empty() || vec.back() < i)
            {
                printf("-1\n");
                return 0;
            }
            res.emplace_back(cnt, i);
            res.emplace_back(cnt, vec.back());
            cnt--;
            vec.pop_back();
            vec.push_back(i);
        }
    printf("%ld\n",res.size());
    for (auto &p : res) printf("%d %d\n",p.first,p.second);
    return 0;
}


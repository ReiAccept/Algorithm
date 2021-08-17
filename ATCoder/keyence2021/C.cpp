#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 5e3+10;

template <typename T>
T inverse(T a, T m)
{
    T u = 0, v = 1;
    while (a != 0)
    {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}
template <typename T>
class Modular
{
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U& x)
    {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U& x)
    {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type& operator()() const
    {
        return value;
    }
    template <typename U>
    explicit operator U() const
    {
        return static_cast<U>(value);
    }
    constexpr static Type mod()
    {
        return T::value;
    }

    Modular& operator+=(const Modular& other)
    {
        if ((value += other.value) >= mod()) value -= mod();
        return *this;
    }
    Modular& operator-=(const Modular& other)
    {
        if ((value -= other.value) < 0) value += mod();
        return *this;
    }
    template <typename U> Modular& operator+=(const U& other)
    {
        return *this += Modular(other);
    }
    template <typename U> Modular& operator-=(const U& other)
    {
        return *this -= Modular(other);
    }
    Modular operator-() const
    {
        return Modular(-value);
    }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs)
    {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs)
    {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs)
    {
        value = normalize(value * rhs.value);
        return *this;
    }  
    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

private:
    Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return lhs.value == rhs.value;
}
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs)
{
    return lhs == Modular<T>(rhs);
}
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) == rhs;
}

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return lhs.value < rhs.value;
}

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs)
{
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) += rhs;
}

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs)
{
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) -= rhs;
}

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs)
{
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) *= rhs;
}
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b)
{
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0)
    {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number)
{
    return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number)
{
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD)
{
    long long res = 1, x = a;
    for (H i = p; i; i >>= 1, x = x*x%mo)
        if (i&1) res = res*x%mo;
    return static_cast<T>(res);
}

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n, m, k;
char a[N][N];
Mint dp[N][N];

inline void solve()
{
    n=read();m=read();k=read();
    for (int i = 1, x, y; i <= k; ++i)
    {
        x=read();y=read();
        cin>>a[x][y];
    }
    dp[1][1]=1;
    int inv3 = inverse(3, MOD);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 'D') dp[i+1][j] += dp[i][j];
            else if (a[i][j] == 'R') dp[i][j+1] += dp[i][j];
            else if (a[i][j] == 'X')
            {
                dp[i+1][j] += dp[i][j];
                dp[i][j+1] += dp[i][j];
            }
            else
            {
                dp[i+1][j] += dp[i][j]*2*inv3;
                dp[i][j+1] += dp[i][j]*2*inv3;
            }
        }
    }
    cout << dp[n][m]*qpow(3, n*m-k) << endl;
}

signed main()
{
    int T = 1;
    for (int t = 1; t <= T; ++t)
    {
        solve();
    }
    return 0;
}


#include<bits/stdc++.h>

const int START=1,FINAL=20;
const std::string NAME=""; //problem name

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T rd(T l, T r) {
    std::uniform_int_distribution<T> u(l, r);
    return u(rng);
}
template <> 
double rd<double>(double l, double r) {
    std::uniform_real_distribution<double> u(l, r);
    return u(rng);
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

int number_of_divisors(int number) {
    int result = 1;
    for (int i = 2; i * i < number; i++) {
        int power = 0;
        while (number % i == 0) {
            number /= i;
            power++;
        }
        if (power != 0) {
            result *= (power + 1);
        }
    }
    if (result == 1) {
        return 2;
    }
    return result * 2;
}

signed main() {
    int number = 1;
    while (number++) {
        int triangle_number = number * (number + 1) / 2;
        if (number_of_divisors(triangle_number) > 500) {
            printf("%ld\n", triangle_number);
            return 0;
        }
    }
}
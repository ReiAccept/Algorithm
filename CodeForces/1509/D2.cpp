#include <bits/stdc++.h>
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read() {
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
const int N = 5e5 + 1009;
int n;
int a[3][N];
string build(int x, int y) {
	string tmp1 = "";
	string tmp2 = "";
	int ptr = 1;
	for(int i = 1; i <= 2 * n; i++) {
		if(a[y][i] == 0) {
			while(ptr <= 2 * n && a[x][ptr] != a[y][i]) 
				tmp1 += a[x][ptr++] ? "1" : "0";
			tmp1 += a[y][i] ? "1" : "0";
			ptr++;
		} else 
			tmp1 += a[y][i] ? "1" : "0";
	}
	while(ptr <= 2 * n) tmp1 += a[x][ptr++] ? "1" : "0";
	ptr = 1;
	for(int i = 1; i <= 2 * n; i++) {
		if(a[y][i] == 1) {
			while(ptr <= 2 * n && a[x][ptr] != a[y][i]) 
				tmp2 += a[x][ptr++] ? "1" : "0";
			tmp2 += a[y][i] ? "1" : "0";
			ptr++;
		} else 
			tmp2 += a[y][i] ? "1" : "0";
	}
	while(ptr <= 2 * n) tmp2 += a[x][ptr++] ? "1" : "0";
	if(tmp1.size() < tmp2.size()) return tmp1;
	else return tmp2;
}
void work() {
	n = read();
	for(int j = 0; j < 3; j++) 
		for(int i = 1; i <= 2 * n; i++) 
			scanf("%1d", &a[j][i]);
	string t1 = build(0, 1);
	string t2 = build(0, 2);
	string t3 = build(1, 2);
	if(t3.size() < t2.size()) swap(t3, t2);
	if(t2.size() < t1.size()) swap(t2, t1);
	cout << t1 << endl;
}
signed main()
{
	int Case = read();
	while(Case--) work();
	return 0;
}

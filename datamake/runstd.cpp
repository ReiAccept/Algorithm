#include<bits/stdc++.h>
#include"datamake.h"

using namespace std;

int main() {
	int n=30;
	for(int i=START;i<=FINAL;i++) {
		string s="std < " + NAME + to_string(i) +".in > " + NAME + to_string(i) + ".out";
		system(s.c_str());
		cout<<"Ok,"<<i<<endl;
	}
}

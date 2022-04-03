#include<bits/stdc++.h>
#include"datamake.h"

using namespace std;

void INIT() {
	srand(time(NULL));
}

bool work(int DATA_NUM) { //rd(x,y)
	
	return true;
}

int main()
{
	INIT();
	for(int DATA_NUM=START;DATA_NUM<=FINAL;DATA_NUM++) {
		const string DATA_FILE_NAME=NAME+to_string(DATA_NUM)+".in";
		freopen(DATA_FILE_NAME.c_str(),"w",stdout);
		if(work(DATA_NUM)) {
			fprintf(stderr, "OK, = %d \n", DATA_NUM);
		} else {
			fprintf(stderr, "FAILD, = %d \n", DATA_NUM);
		}
		fclose(stdout);
	}
	return 0;
}
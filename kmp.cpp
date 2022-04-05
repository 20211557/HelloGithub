#include "kmp.h"

void KMP::fail(const string& pat){
	failure = new int[pat.size()];
	failure[0] = -1;

	int i, j;
	for(i = 1;i<pat.size();i++){
		j = failure[i-1];
		while(j>=0 && pat[i] != pat[j+1])
			j = failure[j];
		if(pat[i] == pat[j+1])
			failure[i] = j+1;
		else failure[i] = -1;
	}
}

bool KMP::Find(const string& str, const string& pat){
	int lens = str.size();
	int lenp = pat.size();
	int i = 0, j = 0;

	while(i<lens && j<lenp){
		if(str[i] == pat[j]){
			i++;
			j++;
		}
		else if(j == 0) i++;
		else j = failure[j-1]+1;
	}
	delete[] failure;
	return j == lenp;
}

#include<stdio.h>
#include<string.h>

#define MAX 1000
int main() {
	char s[MAX];
	gets(s);
	int n = strlen(s);
	int charNum = 0, wordNum = 0;
	bool flag = false;
	for(int i = 0; i < n; i++) {
		if(s[i] != ' ' && s[i] != ',') {
			charNum++;
			flag = true;
		} else if(flag) {
			wordNum++;
			flag = false;
		}
	}
	if(s[n - 1] != ' ' && s[n - 1] != ',') wordNum++;
	printf("×Ö·ûÊý: %d\nµ¥´ÊÊý: %d", charNum, wordNum);
}

#include<stdio.h>
#include<string.h>

#define MAXTITLE 100
#define MAXTEXT 1000


int main() {
	
	char con[3];
	char fileName[MAXTITLE];
	
	scanf(" %s", con);
	scanf(" %s", fileName);
	
	FILE* pf = fopen(fileName, "r");
	if(pf == NULL) {
		printf("文件名输入有误");
		return 0; 
	}
	
	char s[MAXTEXT];
	fread(s, 1, MAXTEXT, pf);
	
	int n = strlen(s);
	int wordNum = 0;
	bool flag = false;
	for(int i = 0; i < n; i++) {
		if(s[i] != ' ' && s[i] != ',') {
			flag = true;
		} else if(flag) {
			wordNum++;
			flag = false;
		}
	}
	if(s[n - 1] != ' ' && s[n - 1] != ',') wordNum++;
	
	if(stricmp(con,"-c") == 0)
		printf("%s中的字符数为：%d", fileName, n);
	else if(stricmp(con, "-w") == 0)
		printf("%s中的单词数为：%d", fileName, wordNum);
	else printf("控制参数输入有误");
}

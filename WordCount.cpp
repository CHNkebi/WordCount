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
		printf("�ļ�����������");
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
		printf("%s�е��ַ���Ϊ��%d", fileName, n);
	else if(stricmp(con, "-w") == 0)
		printf("%s�еĵ�����Ϊ��%d", fileName, wordNum);
	else printf("���Ʋ�����������");
}

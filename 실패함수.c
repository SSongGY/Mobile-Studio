#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void failureFunc(char p[], int size) {
	int j = 0, count[100] = { 0 };
	for (int i = 1; i < size; i++) {
		while(j>0 && p[j] != p[i]) {
			j = count[j - 1];
		}
		if(p[j] == p[i]){
			count[i] = ++j;
		}
	}
	for (int k = 0; k < size; k++)
		printf("%d ", count[k]);
}

int main() {
	char p[100];
	int length;

	scanf("%d", &length);
	scanf("%s", p);

	failureFunc(p, length);

	return 0;
}
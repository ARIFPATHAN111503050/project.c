#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000

char * main() {
	char a[MAX];
	char b[MAX];
	int i, j, k=0;
	scanf("%s",a);
	i = strlen(a)-1;
	j=0;
	int u=0;
		while(a[i-j] == '0') {
			k++;
			j++;
		}
		if (k>=1){
			while(k!=0) {
				a[i]='9';
				k--;
				i--;
			}
			a[i]=a[i]-1;
			if(a[0]=='0' && a[1]!='0'){
				u=strlen(a);
				k=0;
				while(k < u) {
					a[k]=a[k+1];
					k++;
				}
			}
		}
		else {
			i = strlen(a) -1;
			a[i]=a[i]-1;
		}
		printf("%s ",a);
		u++;
	
}

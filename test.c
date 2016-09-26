#include<stdio.h>
#include<string.h>
#include "arim.h"
#define MAX 1000000
int main() {
	char a[MAX];
	char b[MAX];
	char *c;
	long bb;
	int aa;
	printf("multiply ");
	
	scanf("%s%s",a,b);
	c= decimalmul(a,b);
	printf("%s",c);
	printf("divide");
	scanf("%s%s",a,b);
	c= power(a,b);
	//printf("%s\n",c);
	printf("please enter the accuracy you needed and the format of division needed\n");
	//scanf("%s%ld",a,&bb); please pass the specific argunment for the function
	div1(a,bb);
	printf("factorial\n");
	scanf("%s",a);
	fac(a);
}

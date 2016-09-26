#define max 10000
#define MAX 10000
#define pi 3.14159265
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double div1();
int main() {
	div1();
}
double div1(){
	char a[max];
	long int b;
	while(scanf("%s%ld",a,&b)){
		//only for integers ...remainder is in display
		long int remainder;
		static char quotient[MAX];
		long temp=0;
		int i=0,j=0;
		i=0;
	//	if(b==0){
	//		goto infinity;
	//	}
		while(a[i]){
			if(a[i] < 48 || a[i]> 57){
				printf("Invalid positive integer: %s",a);
				return 1;
			}
			i++;
		}
		while(a[i]){
			temp = temp*10 + (a[i] -48);
			if(temp<b){
				quotient[j++] = 48;
			}
			else{
				quotient[j++] = (temp / b) + 48;;
				temp = temp % b;
			}
			i++;
		}
		quotient[j] = '\0';
		remainder = temp;
		printf("Quotient: %s / %ld  =  %s",a,b,quotient);
		printf ("\nRemainder: %ld",remainder);
		infinity:
			printf("the answer is infinity or not define\n");
		

	}
}


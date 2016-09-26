#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000
char * multiply( char [], char []);
char * multiply(char a[],char b[]){
	static char mul[MAX];
	char c[MAX];
	char temp[MAX];
	int la, lb;
	int i, j, k=0, x=0, y;
	long int r=0;
	long sum = 0;
	la = strlen(a) - 1;
	lb = strlen(b) - 1;
	
	for( i = 0 ; i <= la ; i++ ){
		a[i] = a[i] - 48;
	}
	
	for( i = 0 ; i <= lb ; i++ ) {
		b[i] = b[i] - 48;
	}
	
	for( i = lb ; i >= 0 ; i-- ){
		r = 0;
		for( j = la ; j >= 0 ; j-- ){
				temp[k++] = (b[i]*a[j] + r) %10;
				r = (b[i]*a[j]+r) / 10;
		}
		temp[k++] = r;
		x++;
		for(y = 0; y < x ; y++ ) {
			temp[k++] = 0;
		}
	}
	
	k=0;
	r=0;
	for( i = 0 ; i < la + lb + 2 ; i++){
		sum =0;
		y=0;
		for(j = 1;j <= lb + 1;j++ ){
			if(i <= la+j){
				sum = sum + temp[y+i];
			}
			y += j + la + 1;
		}
		c[k++] = (sum+r) %10;
		r = (sum+r)/10;
	}
	c[k] = r;
	j=0;
	for(i=k-1;i>=0;i--){
		mul[j++]=c[i] + 48;
	}
	mul[j]='\0';
	return mul;
}
char * strminusone(char []);
char * strminusone(char a[]){
 	int i, j, k=0;
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
		u++;
	
}
char * fac() {
	char a[MAX], b[MAX];
	char d[MAX];
	char cc[MAX];
	char *c;
	int i=0,j,k;
	while(scanf("%s",a)){
		if( a[0] == '0' && a[1]=='\0'){
			a[0]='1';
			return a;
			
		}
		else{
			strcpy(b,a);
			strminusone(b);
			strcpy(d,b);
			while(b[0]!='0'){
				c=multiply(a,b);
		
				i=0;
				k=0;
				/*while(c[i]=='0') {
						//by increasing the time complexity to n'square ..we prevented the memory wastage 	
						///created by multiply function generating zero at the begining ..
							///useful to counter the error of 	STACK SMASHING OR over flow of memory..	....
								///not exactly n square cause it does not detect zero in some cases....
					k++;
					i++;
				}
				i=0;
				j=strlen(c);
				if(k>0){
					while(j>0) {
						c[i]=c[k];
						j--;
						i++;
						k++;
					}
				}*/	
	
				strcpy(b,d);
				strcpy(a,c);
				strminusone(b);
				strcpy(d,b);
		
				i=0;
				k=0;
				while(c[i]=='0') {
					k++;
					i++;
				}
				i=0;
				j=strlen(c);
				while(j>0) {
					c[i]=c[k];
					j--;
					i++;
					k++;
				}
			}
				
		}
		strcpy(a,c);
			
	}
}

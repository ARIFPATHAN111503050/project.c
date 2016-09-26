#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100000
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
int main () {
	//so;lving by taltor expression using add and mul function,,,,
	char a[MAX];
	char b[MAX];
	printf("log of ");
	scanf("%s",a);
	//continuous case of zeroos sholu be handled please
	int i;
	i=strlen(a);
	a[i-1]=a[i-1]-1;
	i=20;
	while( i>0 ){
		// we need a power function of course;
		
		i--;
	} 
}

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

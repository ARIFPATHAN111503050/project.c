#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long int remainder1;
#define MAX 1000000
char * multiply( char [], char []);
char * division(char[],long);
char * stringminusone( char [] );
int div1(char a,long int  bb);

int validate(char [] );

char * fac( char []);
char * fac(char a[]) {
	char  b[MAX];
	char d[MAX];
	char *c;
	int i=0,j,k;
	while(scanf("%s",a)){
		if( a[0] == '0' && a[1]=='\0'){
			a[0]='1';
			return a;
			
		}
		else{
			strcpy(b,a);
			stringminusone(b);
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
				stringminusone(b);
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
		return a;			
	}
}
int validate(char num[]){
	int i=0;
	while(num[i]){
		if(num[i] < 48 || num[i]> 57){
			printf("Invalid positive integer: %s",num);
			return 1;
		}
		i++;
	}
	return 0;
}
char * division(char div[],long divir){
	static char q[MAX];
	long temp=0;
	int i=0,j=0;
	while(div[i]){
		temp = temp*10 + (div[i] -48);
		if(temp<divir){
			q[j++] = 48;
		}
		else{
			q[j++] = (temp / divir) + 48;;
			temp = temp % divir;
		}
		i++;
	}
	q[j] = '\0';
	remainder1 = temp;
	return q;
}
int div1(char a[],long  bb){
	char *q;
	if(validate(a))
		return 0;
	q = division(a,bb);
	while(*q)
		if(*q ==48)
	q++;
	else
		break;
	printf("quotient: %s / %ld  =  %s",a,bb,q);
	printf ("\nRemainder: %ld",remainder1);
	return 0;
}
char * power(char a[],char b[]) {
	char d[MAX];
	char cc[MAX];
	char *c;
	int i=0,j,k;
		printf("hi");
		i=strlen(a);
		j=strlen(b);
		k=0;
		j=strlen(b)-1;
		j=strlen(b);
		strcpy(d,a);
		strcpy(cc,a);
		stringminusone(b);
		while(b[0]!='0') {
			strcpy(a,d);
			c=multiply(cc,a);
			strcpy(cc,c);
			stringminusone(b);
		}
		i=0;
		k=0;
		while(cc[i]=='0') {
			k++;
			i++;
		}
		i=0;
		j=strlen(cc);
		while(j>0) {
			cc[i]=c[k];
			j--;
			i++;
			k++;
		}
		strcpy(a,cc);
		return a;
	
}
char * stringminusone(char a[]) {
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
		return a;
		u++;
	
}
char * decimalmul (char a[],char b[]) {
	//char a[MAX];
	//char b[MAX];
	char cc[MAX];
	char *c;
	int flag, flag1, x, y;
	int i , j, j1;
	x = strlen(a);
	y = strlen(b);
	i = 0;
	while( i < x ) {
		if ( a[i] == '.') {
			flag = 1;
			break;
		}
		i++;
	}
	i = 0;
	while( i < y ){
		if ( b[i] == '.'){
			flag1 = 1;
			break;
		}
		i++;
		
	}
	if ( flag == 1 && flag1 == 0 ){
		i = 0;
		int k;
		//char tmp;
		x = strlen(a);
		while ( i < x ){
			if ( a[i] == '.' ){
				break;
			}
			i++;
		}
		j = ( strlen(a) - i )-1;//decimal point from back.......set three as a reference please
		while( i < x ){
			
			a[i] = a[i+1];
			i++;
		}
		c = multiply(a,b);
		j = (strlen(c)-j);
		//tmp=c[j];
		k = strlen(c);
		while ( k >= j ) {
			c[k+1] = c[k];
			k--;
		}
		c[j] = '.';///////////////////////////////hello.
		return c;
	}
	else if( flag==0 && flag1==1 ){
		i = 0;
		int k;
		//char tmp;
		x = strlen(b);
		while( i < x ){
			if ( b[i] == '.' ){
				break;
			}
			i++;
		}
		j = ( strlen(b) - i )-1;//decimal point from back.......set three as a reference please
		while( i < x ){
			
			b[i] = b[i+1];
			i++;
		}
		c = multiply(a,b);
		j = (strlen(c)-j);
		//tmp=c[j];
		k = strlen(c);
		
		while( k >= j){
			c[k+1] = c[k];
			k--;
		}
		c[j] = '.';///////////////////////////////hello./
		return c;
	}
	else if(flag==0 && flag1==0){
		c = multiply(a,b);
		return c;
	}
	else if( flag==1 && flag1==1 ) {
		
		//a part to calculate the position of the decimal point.
		i = 0;
		int k;
		//char tmp;
		x = strlen(a);
		while(i < x){
			if(a[i] == '.'){
				break;
			}
			i++;
		}
		j = ( strlen(a) - i )-1;//decimal point from back.......set three as a reference please
		while(i < x){
			a[i] = a[i+1];
			i++;
		}
		//b part to calculate the position of the decimal point.;.;;;...;..;...;.;.;.;;;
		i = 0;
		x = strlen(b);
		while( i < x ){
			if(b[i] == '.'){
				break;
			}
			i++;
		}
		j1 = ( strlen(b) - i )-1;//decimal point from back.......set three as a reference please
		while(i < x){
			b[i] = b[i+1];
			i++;
		}
		c=multiply(a,b); 
		j = j + j1;
		k = strlen(c);
		while(k >= j){
			c[k+1] = c[k];
			k--;
		}
		c[j] = '.';//////////////////////////hello....
		return c;
	}
}

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

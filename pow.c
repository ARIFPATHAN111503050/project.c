#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000
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
char * main() {
	char a[MAX], b[MAX];
	char d[MAX];
	char cc[MAX];
	char *c,*dd;
	int u=1,kk=0,flag=0,i=0,j,k;
	// now handlng the case of decimal but of only base number. please
		while(scanf("%s%s",a,b)){
	
		k=0;
		j=0;
		///condition of real numbers...............
		while(a[j]!='.' ) {
			if(a[j+1]=='.')
				flag=1;
			j++;
		}
		j++;
		if(flag==1){
			i=strlen (a);
			
			kk=j;
			kk = strlen(a)-kk;
			j=j-1;
			while(j < i) {
				a[j]=a[j+1];
				j++;
			}
		}
		k=0;
		i=strlen(a);
		j=strlen(b);
		strcpy(d,a);
		strcpy(cc,a);
		strminusone(b);
		while(b[0]!='0') {
			u++;
			strcpy(a,d);
			c=multiply(cc,a);
			strcpy(cc,c);
			strminusone(b);
		}
	
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
			/////////////////////////////////////////////////////decimal part
			
		
		u=(u)*kk;
		if (flag == 1) {
        		u=strlen(cc)-u;
        		k=strlen(cc);
        		while ( k >= u ) {
				cc[k+1] = cc[k];
				k--;
			}
			cc[k+1] = '.';///////////////////////////////hello.
			printf("position of decimal point if you are searching %d\n",k+1);
		}
		i=0;
		k=strlen(cc);;
		while(c[i]=='0'){
			i++;
			
		}
		kk=0;
		while(k>0) {
			cc[kk]=cc[kk+1];
			kk++;
			k--;
		}
		printf("%s\n",cc);
	}
}

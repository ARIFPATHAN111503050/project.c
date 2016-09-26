#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 100000
void reverse(char *, char * ); 
int call_minus(char *,char *,char *);

void reverse(char *from, char *to ) {
	int len=strlen(from);
	int l;
	for(l=0;l<len;l++)
	to[l]=from[len-l-1];
	to[len]='\0';
}
int call_minus(char *large, char *small, char *result) {
	char L[MAX], S[MAX];
	int l,s,n,h,diff;
	l=strlen( large );
	s=strlen(small);
	int sign = 0;
	if(l<s){
		strcpy(result,large);
		strcpy(large,small);
		strcpy(small,result);
		n=l; l=s; s=n;
		sign = 1;
	}//return 0;


	if(l==s){
		if(strcmp(large, small)<0){
			strcpy(result,large);
			strcpy(large,small);
			strcpy(small,result);
			n=l; l=s; s=n;
			sign =1;
		}//to check which is greater for this case.if other possibility is greater then swaping the number......
	}
	reverse(large,L);
	reverse(small,S);
	for(;s<l;s++)
		S[s]='0';
		S[s]='\0';
		for(n=0,h=0;n<l;n++){
			diff=L[n]-(S[n]+h);
			if(diff<0){
				h=1;
				result[n]=10+diff+'0';
			}
			else{
				result[n]=diff+'0';
				h=0;
			}
		}
		for(n=l-1;n>0;n--){
			if(result[n]!='0')
				break;
		}
		result[n+1]='\0';
		reverse(result,L);
		strcpy(result,L);
///return 1;
		return sign;
}
int main(){
	char fir[MAX],sec[MAX],res[MAX];
	while(scanf("%s%s",fir,sec)==2) {
		int flag, flag1, j, a, min, i, b;
		a = strlen(fir);
		b = strlen(sec);
		while(a!=0){
			if(fir[a]=='.'){
				flag=1;
				break;
			}
			a--;
		}
		i=a;
		while(b!=0){
			if(sec[b]=='.'){
				flag1=1;
				break;
			}
			b--;
		}
		if(flag == 1 && flag1 == 0) {
			a = strlen(fir);
			j = strlen(fir) -i-1;
			b = strlen(sec);
			while(j != 0){
				sec[b]='0';
				j--;
				b++;
			}
			sec[b]='\0';
			printf("%s",sec);
			a = strlen(fir);
			int k=i+1;
			while(i<=a){
				fir[i] = fir[i+1];
				i++;
			}
			min=call_minus(fir,sec,res);
			int len = strlen(res);
			res[len]='\0';
			a=strlen(res);
			if(a == 1){
				char c;
				c=res[0];
				res[0]='0';
				res[1]='.';
				res[2]=c;
				res[3]='\0';
				printf("\n%s \n",res);
				continue;
			}
			a=strlen(res);
			printf(" \n hi %d %d \n",k,a);
			while(a>=k){
				res[a+1]=res[a];
				a--;
			}
			printf("%s \n",res);
		}
		if(flag == 0 && flag == 0 ) {
		
		
		
		
			if(call_minus(fir,sec,res)==1)
				printf("-");
			int len = strlen(res);
			res[len]='\0';
			printf("%s\n",res);
		}
	}
	return 0;
}

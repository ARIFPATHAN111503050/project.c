#include<stdio.h>
#include<string.h>
char  * add(char *,char *);
char  *add(char *x,char *y){
		int i,j,k,sum,carry,l,a,b,c,d;
	
		a=strlen(x);
		b=strlen(y);
		int str3[110]={0};
		k=0;
		carry=0;
		sum=0;
		if(a==1&&b==1){
			sum=a+b;
			printf("sum is %d",(x[0]-'0')+(y[0]-'0'));

		}
		else {
			for(i=a-1,j=b-1;;i--,j--)
			{
				if(x[i]=='.'){
					i--;
				}
				if(y[j]=='.'){
					j--;
				}
				c=x[i]-'0';
				d=y[j]-'0';
				if(j<0)
				{
					d=0;
				}
				if(i<0)
				{
					c=0;
				}
				if(i<0&&j<0)
				{
					break;
				}
				sum=c+d+carry;
				str3[k]=sum%10;
				carry=sum/10;
				k++;
			}
			for(l=k-1,i=0;l>=0,i<=k-1;l--,i++) {
				x[i]=str3[l]+'0';
			}
			x[i]='\0';
			return x;
		}
	
}
int main() {
	char x[1024];
	char y[1024],z[1024],w[1024],*xx,*yy,*cc;
	int i,j,k,sum,carry,l=0,a,b,c,d,flag=0,flag1=0;
	printf("enter two numbers but space in between\n");
	k=0;
	carry=0;
	sum=0;
	while(scanf("%s %s",x,y)!=EOF) {
		a=strlen(x);
		l=a;
		b=strlen(y);
		while(a!=0){
			if(x[a]=='.'){
				flag=1;
				break;
			}
			a--;
		}
		while(b!=0){
			if(y[b]=='.'){
				flag1=1;
				break;
			}
			b--;
		}
		
		if(flag==1){
			i=0;
			l=strlen(x);
			while(i<l){
				if(x[i]=='.'){
					break;
				}
				i++;
			}
			i=i+1;
			l=0;
			a=strlen(x);
			while(i<a){
				z[l]=x[i];///z stores the value of the after decimal value of x .....
				i++;l++;
			}
			z[l]='\0';
			l=strlen(x);
			i=0;
			while(i<l){
				if(x[i]=='.'){
					break;
					
				}
				i++;
			}
			
			x[i+1]='\0';
		}
		
		if(flag1==1){
			i=0;
			l=strlen(y);
			while(i<l){
				if(y[i]=='.'){
					break;
				}
				i++;
			}
			i=i+1;
			l=0;
			a=strlen(y);
			while(i<a){
				w[l]=y[i];///w stores the value of the after decimal value of y .....
				i++;l++;
			}
			w[l]='\0';
			l=strlen(y);
			i=0;
			while(i<l){
				if(y[i]=='.'){
					break;
					
				}
				i++;
			}
			
			y[i+1]='\0';
		}
		if(flag==0 && flag1==0){
			if(a==1 && b==1){
				xx=add(x,y);
				continue;
			}
			else{
				a=strlen(x);
				b=strlen(y);
				if(b>a){
					xx=add(y,x);
				}
				else{
					xx=add(x,y);
				}
				printf("%s",xx);	
			}
		}
		else if(flag==1 && flag1 == 0){
			xx=add(x,y);
			a=strlen (xx);
			xx[a]='.';
			xx[a+1]='\0';
			strcat(xx,z);
			printf(" %s ",xx);
		}
		else if(flag==0 && flag1 == 1){
			xx=add(x,y);
			a=strlen (xx);
			xx[a]='.';
			xx[a+1]='\0';
			strcat(xx,w);
			printf("%s\n",xx);
		}
		else if(flag==1 && flag==1) {
			xx=add(x,y);
			a=strlen(xx);
			xx[a]='.';
			xx[a+1]='\0';
			a=strlen(z);
			b=strlen(w);
			if(a>b){
				a=a-b;
				while(a!=0){
					w[b]='0';
					b++;
					a--;
				}
				w[b+1]='\0';
				yy=add(z,w);
				a=strlen(yy);
				b=strlen(z);
				if(a>b){
					cc[0]=yy[0];
					cc[1]='\0';
					xx=add(xx,cc);
				}
				strcat(xx,yy);
				printf("%s",xx);
			}
			else if(b>a){
				b=b-a;
				while(b!=0){
					z[a]='0';
					a++;
					b--;
				}
				z[a+1]='\0';
				yy=add(z,w);
				a=strlen(yy);
				b=strlen(z);
				if(b>a){
					cc[0]=yy[0];
					cc[1]='\0';
					xx=add(xx,cc);
				}
				strcat(xx,yy);
				printf("%s",xx);
			}
			else if(a==b){
				yy=add(z,w);
				a=strlen(yy);
				b=strlen(z);
				if(a>b){
					cc[0]=yy[0];
					cc[1]='\0';
					xx=add(xx,cc);
				}
				strcat(xx,yy);				
			}
		}
	}
	
	
}

///determine determinant....
//factorial........................
//square ........
// cube function........

#define max 10000
#define MAX 10000
#define pi 3.14159265
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double mul();
double cubic();
double sub();
int date();
double outflow();
double add();
double mix();
double radioactivedecay();
double power(double,int);
int fact(int);
double exp(double);
int quadratic();
int nroot();
int checkvariable();
int ndegreeNHODE();
int poly_differentiation();
double cool();
double div1();
int matrix();
float det(float[][100],float);
void inverse();
void cofact(float [][100],float k);
void transpose(float [][100],float [][100],float);
double square();
char * multiply(char [],char[]);
double square(){
	char a[5000],b[10000];
	scanf("%s",a);
	//mul();                                                     later manupilation  please
}
void transpose(float n[100][100],float fac[100][100],float k){
	int i,j;
	float b[100][100],inverse[100][100],d;
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			b[i][j]=fac[j][i];
		}
	}
	d=det(n,k);
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			inverse[i][j]=b[i][j]/d;
		}
	}
	printf("the inverse of the matrix is\n");
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			printf("%f   ",inverse[i][j]);
		}
		printf("\n");
	}
}

void cofact(float num[100][100],float k){
	float b[100][100],fac[100][100];
	int p,q,m,n,i,j;
	for(q=0;q<k;q++){
		for(p=0;p<k;p++){
			m=0;
			n=0;
			for(i=0;i<k;i++){
				for(j=0;j<k;j++){
					if(i!=q && j!=p){
						b[m][n]=num[i][j];
						if(n<(k-2))
							n++;
						else {
							n=0;
							m++;
						}
					}
				}
			}
			fac[q][p]=pow((-1),q+p)*det(b,k-1);
		}
	}
	transpose(num,fac,k);
}

void inverse(){
	float a[100][100],k,result;
	int i, j;
	printf("enter the order of matrix and enter the entries of the matrix\n");
	scanf("%f",&k);
	for(i=0;i<k;i++){
			for(j=0;j<k;j++){
				printf("Enter a%d%d=",i,j);
				scanf("%f",&a[i][j]);
				
			}
		}
	
	result=det(a,k);
	printf("%f",result);
	if(result==0)
		printf("the inverse of the given matrix is not possible");
	else
		cofact(a,k);
}

float det(float a[100][100],float k){
	float s=1,dete=0,r[100][100];
	int i,j,m,n,c;
	if(k==1){
		return a[0][0];
	}
	else {
		dete =0 ;
		for(c=0;c<k;c++){
			m=0;n=0;
			for(i=0;i<k;i++){
				for(j=0;j<k;j++){
					r[i][j]=0;
					if(i!=0&&j!=c){
						r[m][n]=a[i][j];
						if(n<(k-2))
							n++;
						else{
							n=0;
							m++;
						}
					}
				}
			}
			dete=dete+s*(a[0][c]*det(r,k-1));
			s=(-1)*s;
		}
	}
	return (dete);
}
int matrix(){
	int a[100][100],b[100][100],c[100][100];
	int r,c2,r1,c1,i,j,k,n,sum=0;
	char aa;
	printf("enter the order of the matrixes A and the mode ie(+-*)\n");
	printf("for inverse enter 'i'\n");
	scanf("%d %c",&n,&aa);
	//chose the mode....
	
	
	if(aa=='+'){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("Enter a%d%d=",i,j);
				scanf("%d",&a[i][j]);
				
			}
		}
	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("Enter b%d%d=",i,j);
				scanf("%d",&b[i][j]);
							}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				c[i][j]=a[i][j]+b[i][j];
			}
		}
	
	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d    ",c[i][j]);
			}
			printf("\n");
		}
	}
	if(aa=='-'){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("Enter a%d%d=",i,j);
				scanf("%d",&a[i][j]);
				
			}
		}
	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("Enter b%d%d=",i,j);
				scanf("%d",&b[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				c[i][j]=a[i][j]-b[i][j];
			}
		}
	
	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d    ",c[i][j]);
			}
			printf("\n");
		}
	}
	if(aa=='*'){

		//in multiplication of matrix rows and column may differ...
		printf("for multiplication rows and columns can differ hence\n");
		printf("enter the rows and column of both the matrixes\n");
		scanf("%d%d%d%d",&r,&c2,&r1,&c1);
		for(i=0;i<r;i++){
			for(j=0;j<c2;j++){
				printf("Enter a%d%d=",i,j);
				scanf("%d",&a[i][j]);
				
			}
		}
	
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				printf("Enter b%d%d=",i,j);
				scanf("%d",&b[i][j]);
							}
		}
		for(i=0;i<r;i++){
			for(j=0;j<c1;j++){
				for(k=0;k<r1;k++){
					sum = sum + a[i][k]*b[k][j];
				}
			c[i][j]=sum;
			sum=0;
			}
		}
		
		for(i=0;i<r;i++){
			for(j=0;j<c2;j++){
				printf("%d    ",c[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
	
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
		if(b==0){
			goto infinity;
		}
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
	return 0;
}




char * multiply(char a[],char b[]){
	static char mul[MAX];
	char c[MAX];
	char temp[MAX];
	int la,lb;
	int i,j,k=0,x=0,y;
	long int r=0;
	long sum = 0;
	la=strlen(a)-1;
	lb=strlen(b)-1;
	for(i=0;i<=la;i++){
		a[i] = a[i] - 48;
	}
	for(i=0;i<=lb;i++){
		b[i] = b[i] - 48;
	}
	for(i=lb;i>=0;i--){
		r=0;
		for(j=la;j>=0;j--){
			temp[k++] = (b[i]*a[j] + r)%10;
			r = (b[i]*a[j]+r)/10;
		}
		temp[k++] = r;
		x++;
		for(y = 0;y<x;y++){
			temp[k++] = 0;
		}
	}
	k=0;
	r=0;
	for(i=0;i<la+lb+2;i++){
		sum =0;
		y=0;
		for(j=1;j<=lb+1;j++){
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

double cubic(){
	int i;
	double a,b,c,d;
	printf("enter the cofficient of cubic equation in the form of a b c d \n");
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	if(a!=0&&a!=1.0){
		a=1;
		b=b/a;
		c=c/a;
		d=d/a;
	}
	else
		quadratic();//the cubic cofficient of the equation is zero..... 
	double z1,z2,z3;//solution of the cubic equation,,,......
	double s,r,q,t,r1;//intermediate solution....
	r=(9*b*c+27*d-2*b*b*b)/54;
	q=(3*c-b*b)/9;
	d=q*q*q+r*r*r;
	r1=r;
	r1=r-sqrt(d);
	r=r+sqrt(d);
	s=pow(r,1/3);
	t=pow(r1,1/3);
	printf("the solution is %lf",z1=(-1)*(1/3)*b+s+t);
	printf("the second solution is %lf + %lf*i ",(-1)*(1/3)*b-1/2*(s+t),1/2*(s-t));
	printf("the third solution is  %lf - %lf*i ",(-1)*(1/3)*b-1/2*(s+t),1/2*(s-t));

}




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
	l=strlen(large);
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
//return 1;
		return sign;
}




double sub(){
	char fir[MAX],sec[MAX],res[MAX];
	while(scanf("%s%s",fir,sec)==2) {
		if(call_minus(fir,sec,res)==1)
			printf("-");
		int len = strlen(res);
		for(int i=0;i<len;i++)
			printf("%c",res[i]);
			printf("\n");
	}
	return 0;

}
int date(){
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );

  return 0;
}

double add() {
		
	char x[1024];
	char y[1024];
	int i,j,k,sum,carry,l,a,b,c,d;
	printf("enter two numbers but space in between\n");
	while(scanf("%s %s",x,y)!=EOF)
		{
		a=strlen(x);
		b=strlen(y);
		
		long int str3[110]={0};
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
		printf("sum = ");
		for(l=k-1;l>=0;l--)
		{
			printf("%ld",str3[l]);
		}
		printf("\n");
		}
	}
	return 0;
}










double outflow() {
	printf("Enter the radius of the cylindrical tank and the small hole at the bottom of the tank in the same unit .\n");
	double R,r,A,a,c,h,t;
	scanf("%lf%lf",&R,&r);
	a=pi*r*r;
	A=pi*R*R;
	A=13.28*(a/A);
	printf("The general solution of the equation of the height is h(t) = (c - %lf*t)^2 ",A);
	//particular solution for the value of c in short.....
	printf("Enter the initial condition at h (0)\n");
	scanf("%lf",&h);
	c=sqrt(h);
	printf("the time at which no water is left  %lf  hours\n",c/A/(60*60));
	printf("now the height at particular time .so enter the time");
	scanf("%lf",&t);
	t=(c-A*t)*(c-A*t);
	printf("therefore height is %lf \n ",t);
}



double cool() {
//for this law we need to know about the average temperature ,initial condition temperature and at known time t and temperature at that time t
	double k,t1,t2,t3,c,t,t4;
	printf("Enter the average temperature and   initial condition(temperature) at t=0");
	scanf("%lf%lf",&t1,&t2);
	c=t2-t1;
	printf("enter the temperature at time t and the time t also");
	scanf("%lf%lf",&t3,&t);
	k=log((t3-t1)/c)/t;
	printf("The general equation is  T(t)=%lf + %lfe^(%lf*t)",t1,c,k);
	printf("Enter the time t at which you want to find temperature through newtons law of cooling");
	while(scanf("%lf",&t4)){
		printf("T(%lf)=%lf\n",t4,t1+c*exp(k*t4));
	}
}







double mix() {
	double store,c,inrate,incontent,outrate,k,y,t;
	//pending work use gnu to demonstrate the example.if possible....
	printf("Enter the no of gallons that the tank contains and also the outflow \n");
	scanf("%lf%lf",&store,&outrate);
	printf("Enter the rate of gallon the solution is added to the water and as enter the given salt per gallon\n");
	scanf("%lf%lf",&inrate,&incontent);
	k=outrate/store;
	printf("Enter the initial condition:y(0)..\n"); 
	scanf("%lf",&y);
	//constant generated while integrating...
	c=((inrate*incontent)/k)-y;
	printf("the general equation is  y(t)= (%lf * %lf)/ %lf - %lf*e^(- %lf*t)\n now find the amount of solute at any time t.just enter the value of t ",inrate,incontent,k,c,k);
	while(scanf("%lf",&t)) {
	k=inrate*incontent/k - c*exp(-outrate/store*t);
	printf("the amount of salt at time %lf is %lf ",t,k);
	}
	return 0;
}



double radioactivedecay() {
	double y,inp,c,t,k,t1;
	printf("please enter the initial condition     y(0) = ""initial value of decay\n");
	//if the initial condition is not expected please handle the case of non initial condition through if
	//here also if the initial condition is not handled then please handle that condition through if
	scanf("%lf",&inp);
	c=inp;
	printf("enter the specific condition at a particular time and value of the function at that time interval\n");
	scanf("%lf%lf",&t,&y);
	k=(-1)*1/t*log(y/c);
	printf("the equation of radioactivity is y(t)=%lf*e^(%lf * t) \n",c,k);
	printf("now find the decayed amount by entering the time ");
	while(scanf("%lf",&t1)) {
		t1=c*exp(k*t1);
		printf("%lf\n",t1);
	}
}



double power(double x,int n) {
	double val=1;
	int i;
		for(i=1;i<=n;i++) {
		val=val*x;
	
	}
	return val;
}


int fact(int num) {
	int c;
	if(num==0||num==1)
		return (1);
	double fact=1;
	for(c=1;c<=num;c++) {
		fact=fact*c;
	}
	return fact;	
}


int poly_differentiation() {
	//fo polynomials
	int a[50],i,n=0,d[50],power;
	float in[10];
	printf("enter the order of the polynomial\n");
	scanf("%d",&n);
	for(i=n;i>=0;i--){
		printf("enter the cofficient of x^%d  ",i);
		scanf("%d",&a[i]);
	}
	printf("the given polynomial is \n");
	for(i=n;i>=0;i--) {
		if (a[i]>0) {
			if(i!=n) {
				printf("+");
			}
		}
		else if (a[i]<0)
			printf(" - ");
		else 
			printf("  ");
		printf("%dx^%d",a[i],i);
	}
	//differentiate

		
		printf("\n derivative of the givemn polynomial is %d\n",n);
		for(i=n;i>=1;i--) {
			if(a[i]<0)
				printf(" - ");
			else if(a[i]>0)
				printf(" + ");
			else
				printf("  ");
			printf(" %dx^%d",a[i]*i,i-1);
		}
	
	
}
	


int nroot() {
	return 0;
}

int ndegreeNHODE() {
	
	
}
int quadratic() {
	int i;
	double a,b,c,d;
	printf("enter the cofficient of quadratic equation in the form of a b c  ");
	scanf("%lf%lf%lf",&a,&b,&c);
	d=sqrt(b*b-4*a*c);
	if((b*b-4*a*c)==0)
		printf("\nthe solution is %lf",(double)(-1)*b/2*a);
	else if((b*b-4*a*c) < 0){
		d=sqrt((-1)*(b*b-4*a*c));
		printf("\nthe solution is x1 = %lf + %lfi  x2 = %lf + %lfi\n",((-1)*b)/(2*a),d/(2*a),((-1)*b)/(2*a),d/(2*a));
		}
	else 
		printf("\nthe solution is x1= %lf  and x2 =%lf\n",(-1)*b/2*a+d/2,(-1)*b/2*a-d/(2*a));
}
int main() {
	int i,n;
	
	double q,ret,val,facto,p,expo;
	quadratic();
	poly_differentiation();
	nroot();
	printf("the exponential function of %lf  is %lf ",p,exp(p));	
	scanf("%d",&n);
	facto=fact(n);
	//TRIGNOMETRY FUNCTION. and please arrange the condition according to the user.
	scanf("%lf",&q);
	val=pi/180;
	ret=sin(q*val);
	printf(" the sine of %lf is %lf",q,ret);
	ret=tan(q*val);
	printf("the tan of %lf is %lf ",q,ret);
	ret=cos(q*val);
	ret=1/sin(q*val);
	ret=1/cos(q*val);
	ret=1/tan(q*val);
	//end of trignometry function.
	//radioactivity :exponential decay....
	radioactivedecay();
	/*mixing problem....to tell the total concentration of solute example(salt)
	the overall concept is , there is solute in a tank .there is a tap which is open .simultaneously there is an inlet on top gives salt .to find the total concentration of salt in the tank at time t..facinating.the work of calculating is done on paper the final formulas are written in mix function.
	*/
	mix();
	//Newton's law of cooling...
	cool();
	
	//problems related to the level (hieght of water level) at a given time t...when there is a hole in the cylindrical tank.....
	outflow();
	add();
	sub();
	date();
	cubic();
	//multiply();      argunment are requiredd thats why
	div1();
	matrix();
	//det();           argunment are required.........
	inverse();
	square();
	return 0;

}

#include<stdio.h> // (-O 40/1500 + 60/1500)
#include<stdlib.h> 
#include"c.h"
#define O printf

//ackermann
I a(I x,I y){R x?a(x-1,y?a(x,y-1):1):y+1;}

//binarysearch
I b(I*x,I y){I h=x[-1],i,l=0;W(h>l)y>x[i=l+h>>1]?l=i+1:(h=i);R l;}

//fannkuch
I f(I x,I*y,I*z){I j,k,m=0;$(--x,N(x+1,j=*y;N(x,y[i]=y[i+1])y[x]=j;m=MX(m,f(x,y,z)))){N(y[-1],z[i]=y[i])W(j=*z){I i=0;++m;W(i<j)k=z[i],z[i++]=z[j],z[j--]=k;}}R m;}

//trees
J*t(I n,I m){J*p=malloc(24);*p=n,p[1]=m?(J)t(2*n-1,m-1):0,p[2]=m?(J)t(2*n,m-1):0;R p;}
V u(J*p){if(p[1])u((J*)p[1]),u((J*)p[2]);free(p);}
I c(J*p){R p[1]?*p+c((J*)p[1])-c((J*)p[2]):*p;}

//mandelbrot
I m(I x){I k=0;N(x,F r=-1.5+i*2./x;N(x,F s=-1+i*2./x,p,q,t,u;p=q=0;I m=50;W(m*(4>(t=p*p)+(u=q*q)))--m,q=s+2*p*q,p=r+t-u;k+=!m))R k;}

//timer
F ms(){J a,d;asm volatile("rdtsc":"=a"(a),"=d"(d));R((d<<32)+a)*.58e-6;}

//enm
V*malloc(),free();I*enm(I n){I*r=malloc(4+4*n);N(*r++=n,r[i]=i)R r;}
#define MS(n,e) {F _t=ms();I s=0;N(n,s+=e)O("%d %d\n",(I)(ms()-_t),s);}
I main(){J*p;I*x=enm(1000),*y=enm(8),*z=enm(8);
MS(2000,a(3,4))
MS(1000000,b(x,1023&i))
MS(20,f(8,y,z))
MS(100,(p=t(0,13),c(p),u(p),1))
MS(30,m(100))
R 0;}

//tree
//I t(I n){I d=4;J*p=a(n+1,0),*q;c(p),b(p),q=a(n,0);for(;d<=n;d+=2){I j=0,m=1;N(n-d+4,m*=2)N(m,j+=c(p=a(d,i+1)),b(p),j+=c(p=a(d,-i-1)),b(p))}R d=c(q),b(q),d;}//O("%d %d\n",2*m,j);


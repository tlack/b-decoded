typedef unsigned char C,*S,*K;typedef int I;typedef long J;typedef double F;typedef void V;V*memcpy();J strlen(const char*);

#define R return
#define P(b,a...)   if(b)return(a);
#define N(n,a...)   {I i=0,_n=(n);while(i<_n){a;++i;}}
#define W(b...)     while((b))              //while
#define $(b,a...)   if(b){a;}else           //cond
#define C(i,a...)   case i:{a;}break;       //case
#define S(i,c,a...) switch(i){c default:a;} //switch

#define MN(a,b)    ({typeof(a)_a=(a);typeof(a)_b=(b);_a<_b?_a:_b;})
#define MX(a,b)    ({typeof(a)_a=(a);typeof(a)_b=(b);_a>_b?_a:_b;})

#define ZI static I
#define ZC static C
#define ZS static S
#define ZJ static J
#define ZF static F
#define ZK static K
#define ZV static V

#define _ static inline
#define AB(s)       (os(s),exit(1),(V*)0L) //abort string


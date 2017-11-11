#include"c.h"
#define NX nt[xt] // chijefs
#define KC 1L
#define KI 3L
#define KF 6L
#define KS 7L

#define NL (K)(X1<<48)
#define X1 11L
#define X2 12L
#define X3 13L
#define QQ 15L
extern J nt[],ip();extern K G[],r1(),tn(),j2(),k0(),sS(),enm(),o();V exit(),w2(),r0();S pi(),pf(),px();F fp();_ K X(K*k,K y){R r0(*k),*k=y,NL;}
_ I oc(I i){R w2((S)&i),i;}_ V nl(){w2("\n");}_ S os(S s){R w2(s),nl(),s;}_ J oi(J j){R os(pi(j)),j;}_ F of(F f){R os(pf(f)),f;}_ J ox(J j){R os(px(j)),j;}
_ S sc(S s,I c){W(*s-c)P(!*s++,0)R s;}_ I scn(S s,I c,I n){N(n,P(c==s[i],i))R n;}//_ K P1(J x){R(K)(X1<<48|x);}_ K P2(J x){R(K)(X2<<48|x);}_ K P3(J x){R(K)(X3<<48|x);}
_ K kK(I n){R tn(0,n);}_ K kC(I n){R tn(KC,n);}_ K kI(I n){R tn(KI,n);}_ K kS(I n){R tn(KS,n);}_ K pn(S s,I n){R memcpy(kC(n),s,n);}_ K kp(S s){R pn(s,strlen(s));}
_ K kc(J x){R(K)(KC<<48|x);}_ K ki(unsigned x){R(K)(KI<<48|(J)x);}_ K kf(F f){R*(K*)&f;}_ K ks(J x){R(K)(KS<<48|x);} _ K qs(S s){R(K)(QQ<<48|(J)s);}
_ K c0(){R kC(0);}_ K c1(C x){K r=kC(1);R*r=x,r;}_ K c2(C x,C y){K r=kC(2);R*r=x,r[1]=y,r;}_ K c3(C x,C y,C z){K r=kC(3);R*r=x,r[1]=y,r[2]=z,r;}_ K jc(K x,C c){R j2(x,kc(c));}

#define A(x) ({J _j=(J)(x);!_j||_j>>52?KF:15&_j>>48;})
#define I(x) (I)(J)(x) //(-1UL>>16&(J)(x))
#define Q(x)        P(QQ==A(x),x) //#define Q(c,i)      P(c,qi(i))  //error index(nyi,rank,length,type,..)
#define Qs(c,s)     P(c,qs(s))  //error string
#define N1(n,a...)  {I i=0,_n=(n);do{a;}while(++i<_n);}

// access x y z r
#define Ax A(x)
#define xi I(x)
#define xf *(F*)&x
#define xm x[-8] //mem
#define xr x[-7] //ref
#define xu x[-6]
#define xt x[-5]
#define xn xI[-1]
#define xx xK[0]
#define xy xK[1]
#define xz xK[2]
#define xI ((I*)x)
#define xF ((F*)x)
#define xK ((K*)x)
#define Xc  x[i]
#define Xi xI[i]
#define Xx xK[i]
#define X0(e)  ({typeof(e)_e=(e);r0(x);_e;})
#define Ay A(y)
#define yi I(y)
#define yu y[-6]
#define yt y[-5]
#define yn yI[-1]
#define yx yK[0]
#define yy yK[1]
#define yI ((I*)y)
#define yK ((K*)y)
#define Yc  y[i]
#define Yi yI[i]
#define Yx yK[i]
#define Y0(e)  ({typeof(e)_e=(e);r0(y);_e;})
#define Az A(z)
#define zi I(z)
#define zu z[-6]
#define zt z[-5]
#define zn zI[-1]
#define zx zK[0]
#define zy zK[1]
#define zI ((I*)z)
#define zF ((F*)z)
#define zK ((K*)z)
#define Zc  z[i]
#define Zi zI[i]
#define Zx zK[i]
#define Z0(e)  ({typeof(e)_e=(e);r0(z);_e;})
#define Ar T(r)
#define ri I(r)
#define rr r[-7]
#define rt r[-5]
#define rn rI[-1]
#define rI ((I*)r)
#define rK ((K*)r)
#define rx rK[0]
#define ry rK[1]
#define rz rK[2]
#define Rc r[i]
#define Ri rI[i]
#define Rx rK[i]
#define R0(e)  ({typeof(e)_e=(e);r0(r);_e;})

#define xJ ((J*)x)
#define zJ ((J*)z)

#define ZV1(f) ZV f(K x)
#define ZS1(f) ZK f(S s)
#define ZK1(f) ZK f(K x)
#define ZK2(f) ZK f(K x,K y)
#define ZK3(f) ZK f(K x,K y,K z)
#define V1(f)   V f(K x)
#define I1(f)   I f(K x)
#define K1(f)   K f(K x)
#define K2(f)   K f(K x,K y)
#define K3(f)   K f(K x,K y,K z)
_ K1(k1){K r=kK(1);R rx=x,r;}_ K2(k2){K r=kK(2);R rx=x,ry=y,r;}_ K3(k3){K r=kK(3);R rx=x,ry=y,rz=z,r;}_ K3(j3){R j2(j2(x,y),z);}_ K2(jk){R j2(x,k1(y));}_ K cj(C c,K y){R j2(c1(c),y);}


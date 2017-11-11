#include"a.h"// read/write mmap/munmap printf/scanf malloc/free
J read(),write();I open(),close(),fstat(),munmap();S mmap();
V exit();

ZF ms(){ // time in milleseconds 
	J a,d;
	asm volatile("rdtsc":"=a"(a),"=d"(d));R((d<<32)+a)*.58e-6;}

V w2(S s){ // write c string s to stderr
	write(2,s,strlen(s)); }

ZS r2(S s){ // read a string of up to 256 bytes from the keyboard (fd 0 aka stdin)
	ZC b[256];
	R w2(s),b[read(0,b,256)-1]=0,b;}

ZI rand(){ // how could this possibly work
	ZJ j0=-314159;
	R j0=4294957665L*j0+(j0>>32); }

ZS ma(I d,J n){ // mmap; d is file descriptor or zero for anonymous; n is size (long / J)
	ZJ p=0x700000;
	p+=d?0:n;
	R mmap(d?0:p-n,n,0x7,d?2:0x22,d?d:-1,0); }

ZS mf(S s,J*n){ //mmap a file (in s); return size in n
	J b[18];
	I d=open(s,0);
	Qs(0>d,s) // crash if open returns < 0
	// below i think we're checking size and making it bigger w/ mmap? weird
	R fstat(d,b),s=(*n=b[6]) ? ma(d,*n):s,close(d),s;}

// printf scanf 
ZC b[24]; // scratch buffer for outputting formatted numbers

ZS ng(S s){ // sets the char preceding s to minus, then returns s
	R *--s='-',s; }

ZS pu(S s,J i){
	J j;
	do*--s='0'+i-10*(j=i/10);
	W(i=j);
	R s;}

ZF x(I n){ // returns 1 to the n'th power
	F e=1;
	N(n,e*=10)
	R e; }

S pi(J i){
	R 0>i?ng(pi(-i)):pu(b+23,i);
} //P(NI==f||0>(j|k),nf)

S pf(F f){ // float (F) to C string (S)
	P(0>f,ng(pf(-f)))
	P(!f,"0.0")
	I n=6;
	W(f<1e6)--n,f*=10;
	W(f>=1e7)++n,f/=10;
	S p=n?p=pi(n),*--p='e',p:b+23;
	n=f+.5;
	W(99<n&&!(n%10))n/=10;
	R p=pu(p,n),p[-1]=*p,*p--='.',p;}

J ip(S p,I n){ // parse a long (J) out of a string (p; S means char*); max len n
	P('-'==*p,-ip(p+1,n-1)) // if starts with negative, recurse and negate result
	J j=0;
	// for each character, increase j by the ascii value minus the ascii value of 0.. so '7' (37) = 7; accumulate in j
	N(n,j=10*j+p[i]-'0')    
	R j;}

ZS hh(S s,C c){
	N(2,C a=i ? c&15 : c>>4; s[i]="0W"[9<a]+a)
	R s;}

S px(J j){
	S s=b+23;
	unsigned long k=j;
	do hh(s-=2,k);
	W(k>>=8);
	R s;}

F fp(S p,I n){
	// fp: parse float, string -> F (float)
	// first, check if we're starting with a minus; if so, call this function
	// again, starting from the right of the minus, and with a length one shorter
	// (to account for the lost -); return that value.
	P('-'==*p, -fp(p+1,n-1))
	// now, scan the string for an e, as in -1.2e, and store in l
	I l=scn(p,'e',n),
	  // now, scan the string again for a ., which must be before the 'e' if any 
	  m=scn(p,'.',l),
		// f stores the fractional part. 
		// - if there is an 'e' (l < n), f becomes everything before the 'e' but
		//   after the '.'
		// - otherwise, 0.
		f=l<n ? ip(p+l+1,n-l-1) : 0,
		// j stores the decimal part
		j=ip(p,m),
		k;
	m+=m<l, 
	k=ip(p+m,MN(9,l-=m));
	k+=j*x(l), f-=l;
	R 0>f ? k/x(-f) : k*x(f);} 

// malloc free:  mturnnnn list join (k[cifs] k[CIFS])
ZK M[31]; // M is 31 pointers to memory regions
ZK m1(J n){
	K x,r;
	I i=60-__builtin_clzl(n+7),j; // what does the count of leading zeroes have to do with this
	P(x=M[i],M[i]=xx,x)
	j=i;
	W(!(x=++j<31?M[j]:8+ma(0,16L<<(j=MX(18,i)))));
	xm=i,M[j]=xx,r=x;
	W(i<j) x+=16L<<xm,M[*(J*)(x-8)=i++]=x,xx=0;
	R r;}

J nt[]={8,1,2,4,8,4,8,4}; // nt is the size in bytes of each of the types
ZJ W=-32;                 // avail size of workspace

ZV l0();

V1(r0){ // decref
	if(Ax||!x)R; // what is Ax? if X isnt valid, just return - no need to decref
	if(8==xt){l0(x);R;} // what is type 8?
	if(xr){--xr;R;} // if x has a ref count > 0, decrease it, and return.
	if(!xt||KS<xt) // if x is a linked list (xt==0), or a type less than 7L (KS)..
		N1(xn,r0(Xx)) // call r0 on all of them.. Xx means (K*)x[i], and i is set in N1 (while loop)
	W-=16L<<xm, // add back 16L << xm (amount of memory x uses) to the workspace W
	xx=M[xm], // ??
	M[xm]=x;} // ??
	
K1(r1){
	P(Ax,x)
	R++xr?x:AB("r1");}

K tn(I t,I n){ // create a value of type t size n
	K x=m1(MX(1,n) * nt[KS<t?0:t]);
	R W += 16L<<xm, xu=0, xt=t, xn=n, x;}

ZK xiy(K x,I i,K y){ // this seems to copy items from y into x, but incref y as well
	memcpy(x+NX*i,y,NX*yn);
	if(!yt) N(yn,r1(Yx))
	R Y0(x);}

K2(j2){ // join two values i think
	I m=xn,n=m+(Ay?1:yn);
	P(!m&&!xt,X0(y))
	$(xr || 8+NX*n > 16L<<xm, x=xiy(tn(xt,n),0,x))
	xu=0,xn=n;
	Ay ? memcpy(x+NX*m,&y,NX) : xiy(x,m,y);
	R x;}

// struct/fixedarray experiment
ZK1(l2){R kp("[]");}
ZV1(l0){
	if((J)xy)l0(xy),l0(xz);
	xx=M[xm],
	M[xm]=x;}
K3(l1){ // return a list containing x, y, and z.
	K r=m1(24);
	R rt=8,rn=3,rx=x,ry=y,rz=z,r;}

// REPL \ltwvf DAZ FTZ
// G are the globals
K G[26],ev(),ps();
ZK es();
ZK K0;
K k0(){R r1(K0);}

ZK vf(I f){
	K r=kS(0);
	N(26,K x=G[i]; if(NL-x)if(f^(Ax||xt))r=j2(r,ks(i))) // what?
	R r;}

ZK Li(K x,I i){ // Li (list item) gets item i from x
	R !xt || KS<xt ? Xx : // return list item (K*x)[i] OR waterfall type check to return right type
		( KC==xt ? kc(Xc) : KI==xt ? ki(Xi) : ks(Xi));} 

ZK e1(K(*f)(),K x){ // e1 (each one) - call f(x) and return each item in x; use f=0 for general list
	K r=kK(xn);       // create general list r
	N1(rn,            // for each item in r..
		Rx=f?f(Li(x,i)):Li(x,i)) // if f is a function, set R[i] = f(x), else just pull out the item
	R r;}

K sS(I c,K x){
	I n=c?xn:0;
	N(xn,K y=Xx;n+=yn)
	K r=kC(n);
	if(c)--rn;
	S s=r;
	N(xn, K y=Xx;s=memcpy(s,y,yn)+yn;if(c)*s++=c)
	R X0(r);}

ZK1(se){
 K1(c){
	 N(xn,if(94u<Xc-32){K r=kC(2*xn);N(xn,hh(r+2*i,Xc))R j2(c2('0'+xu,'x'),r);})
	 R cj('"',jc(r1(x),'"'));}
 P(Ax,KS==Ax ? c2('`','a'+xi) : (KC==Ax ? X0(c(x=c1(xi))) : (kp(KI==Ax?pi(xi):KF==Ax?pf(xf):(S)"+"+!xi)) ) )
 P(8==xt,l2(x))
 P(1==xn,cj(',',se(Li(x,0))))
 I t=KS<xt?0:xt;
 P(KC==t,c(x))
 P(!xn,c2("!("[!t],")  0   `"[t]))
 x=sS(";      "[t],e1(se,x));
 R !t?cj('(',jc(x,')')):x;}

K1(o){
	K y=QQ-Ax?se(x):j2(kp("ERROR: "),kp((S)(-1UL>>16&(J)x)));
	R Y0(write(2,y,yn)),nl(),x;}
	
ZK1(pr){if(NL-x)r0(o(x));R x;}

ZS1(ld){ // i believe this loads stuff with mmap?
	J n;
	Q(s=mf(s,&n))
	S t=s,u;
	I a,d=0;
	W(t<s+n&&d>=0){
		u=sc(t,10), // find newline
		*u++=0,     // make it null terminator (tokenize)
		a=t[1]?0:(*t=='/')-(*t=='\\');
		if(!d&&!a&&'/'-*t)
			Q(pr(es(t)))
		d+=a,t=u;
	}
	if(n)munmap(s,n);
	R NL;}

ZS1(tm){
	S t=sc(s,' ');
	Qs(!t,s)*t=0;
	I n=':'-*s++?1:10u>*s-'0'?ip(s,t-s):(J)es(s);
	K x='\\'-*++t?ps(t):0,r;
	F a=ms();
	N(n,Q(r=x?ev(x):ld(t+3))r0(r)) // load or run
	if(x)r0(x);
	R ki(ms()-a);}

ZS1(es){
	K x;
	P('\\'-*s,!*s?NL:(x=ps(s))&&NL-x?X0(ev(x)):x)
	if(!*++s||'\\'==*s)exit(0);
	R !s[1]?'w'==*s?ki(W):sc("vf",*s)?vf('f'==*s):qs(s):'t'==*s?tm(s+1):'l'==*s?ld(s+2):qs(s);}

V km(S*a){ // repl loop
	N(26,G[i]=NL) // clear globals
	*(K*)(K0=kK(0))=c0();
	if(*++a) pr(ld(*a)); // arg named on command line? evaluate it and print result
	W(1)pr(es(r2(" ")));} // read input with r2, evaluate with 'es' (eval string), print, loop forever

V _start(){asm("movl $0x9fc0,-4(%rsp);ldmxcsr -4(%rsp);lea 8(%rsp),%rdi;jmp km");}

K1(enm){ // enumerator the integer numbers 0 .. x
	K r=kI(xi); // create r, an integer (I) vector with with x items
	N(rn,Ri=i) // set each item of R[i] to i, the counter set by N
	R r;}

//K qi(I i){R qs((S[]){"nyi","rank","length","type","domain","value"}[i]);}
//ZK1(rd1){QC(x)x=jc(x,0);I d=open(x,0);Qs(0>d,x)J b[16];fstat(d,b);R x=X0(511+ma(0,0,0,b[6]+4096)),xm=-1,xt=KC,ma(0,d,x,xn=b[6]),W+=xn,x;}(W-=xn,mu(x-511,xn+4096))
//ZK2(wr1){QC(x)x=jc(x,0);QC(y)unlink(x);I d=open(x,0102,0666);Qs(0>d,x)ftruncate(d,yn);R x=X0(ma(1,d,0,yn)),dsn(x,y,yn),mu(x,yn),Y0(NL);}
//K1(rd0){R Ss(0,rd1(x));} //{-1_'(0,1+&x=y)_y} K2(wr0){R wr1(x,sS(0,y));} //{,/x,'y}          


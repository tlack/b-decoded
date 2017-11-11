b Demistified, Volume 1, Abridged
=================================

This is my attempt at understanding how `b` works.

`b` is a programming language by Arthur Whitney, the creator of K, Q, and Kdb.

He has released it and sporadic updates at http://kparc.com/b/

From his README:

```
fast c compiler (called b: isomorphic to c)

computer language benchmarks: t.b and t.c

         run  compile(ms) runsize
     b   230     .06       1K
gcc-O1   320   60.00       3K
gcc-O2   230   90.00       3K
gcc-O9   230  200.00       8K

b generated code is fast. already matches the fastest gcc/llvm.
b is fast. 1000 times faster than gcc/llvm/visualc. game changer.
b is interactive. much better error reporting and development potential.
b code is smaller(shrug?) and uses much less stack(shrug?).

b parses and compiles a language isomorphic to c. 
same types. same ops. same control. more compact. (no precedence)

b : +-*%^&|<> =  /  \   $[c;t;f]
c = +-*/^&|<> == << >>  if(c)t;else f;

argtypes(for x,y,z) declared. 
result and local types are automatic.

e.g. binary search

b: b[Ii]{h:#x;l:0;while(h>l)$[y>x[i:/l+h];l:i+1;h:i];l}
c: I b(I*x,I y){I h=x[-1],i,l=0;while(h>l)if(y>x[i=l+h>>1])l=i+1;else h=i;R l;}

todo: 

align, inline, unroll (we win)
arm, llvm, ..
c89, c99, .. (not interesting right now since i already prefer b and there is no c code we care about)

notes:
A.S kernel interface (map unmap ..)
a.c replaces libc (fp and pf need more work)
b.c compiles b code
 
p() parse(this would change for c89 etc.  minor. the rest is the same.)
d() to register, constant or global
e() to register
f() force
..


for arm, llvm, etc. just need to replace:
jmp tst cmp o2
ret cll psh pop
```

This repo
---------

Here I have reworked parts of the code to be easier to understand by a
programmer of the traditional school of code formatting.

Note that `b` doesn't actually compile for me right now, so I'm flyin blind.

Legal
-----

I do not claim copyright on this code. I have uploaded this to GitHub for
educational purposes only. If you have a question about this code's license or
you want to use it in any way, contact Arthur Whitney directly.

Notes
-----

Misc notes, no particular order:

* An elements length is stored as an int in the item *before* the pointer, so:
* `xn` calls `xI[-1]` which is:
* `xI` basically does (int*)x 
* There are other, related functions (implemented as macros in `a.h`):
  * `xm` accesses x[-8], which is the memory allocated to the value
	* `xr` accesses x[-7], which is the ref count
	* `xu` accesses x[-6], which I think are the attributes 
	* `xt` accesses x[-5], which is the type
* `x` generally is a locally-defined variable that contains the argument we are operating on
* Likewise, these same functions are defined for `y`, `r`, and `z`.
* `j2` joins two items into a list.
* `nt` is the size in bytes of each of the types


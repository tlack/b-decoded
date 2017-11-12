b Demistified, Volume 1, Abridged
=================================

This is my attempt at understanding how the `b` programming language interpreter works.

`b` is a systems-level programming language by Arthur Whitney, the creator of K, Q, and Kdb.

He has informally released it and sporadically updates the code at http://kparc.com/b/

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

Arthur Style
---------

Here's an example of two lines of the `b` source code (from a.c, written in pretty much plain old C):

```
J read(),write();I open(),close(),fstat(),munmap();S mmap();V exit();ZF ms(){J a,d;asm volatile("rdtsc":"=a"(a),"=d"(d));R((d<<32)+a)*.58e-6;}
V w2(S s){write(2,s,strlen(s));}ZS r2(S s){ZC b[256];R w2(s),b[read(0,b,256)-1]=0,b;}ZI rand(){ZJ j0=-314159;R j0=4294957665L*j0+(j0>>32);}
```

Arthur is famous for his very dense programming style. Most C programmers would
scream when seeing this code.

In his view (and others in the terse scene), it is much better to have
everything in your application readable on the screen at once than to have
great names for things or a lot of white space to comfort the first timer
reader. 

To them, once you've sufficiently studied that screen or two of code, you can
understand all of it at the same time. If it's spread out over thousands of
files, it's very difficult to understand all of it, which leads to bugs,
unnecessary abstraction, and the need for advanced tooling just to work with
your own project's code.

He wants to see the code "all at once" so he can understand all of its behavior without paging around
and shifting his focus to another tab, window, etc. To get there he makes a lot of tradeoffs in terms 
of the code formatting and naming conventions. He also, in `b`, creates a dense set of interlocking
macros and abstractions that can make the code very hard to follow.

Critics and the uninitiated say that his code is like old school modem line
noise: random punctuation intermixed with bits of understandable code. I would
suggest that he's actually quite careful with the abstractions he chooses and
they are actually not always the most dense, highly compressed code structures
available to him. He chooses wisely and his code rewards deep study.

Arthur, by the way, says his code is like woodgrain, a more romantic view. 

About this repo
------

Here I have reworked parts of the code so they are easier to understand by a
programmer of the traditional school of code formatting, including comments
explaining my presumption of the intent of a bit of code.

For what it's worth, I don't pretend to truly understand `b`. 

I've also gone through and added some comments here and there to help the reader
understand how it works.

I am just sorta exploding all the parts here and reworking them for easier
understanding. I've erred on the side of too much white space and commenting in
my adaptation (as presented here) because I think the "guts" of it are so
interesting and complex they deserve to be presented all alone.

Note that `b` doesn't actually compile for me right now, so I'm flyin blind.
This is more for study and curiosity, and perhaps a window into how Arthur's
mind works, than to compile and use. Check out the Kparc master repo which
might be closer to being usable.

I do not track changes from the `b` master repo in this repo.

Legal
-----

I do not claim copyright on this code. I have uploaded this to GitHub for
educational purposes only. If you have a question about this code's license or
you want to use it in any way, contact Arthur Whitney directly.

Notes
-----

To understand the code, you must understand the macros in `a.h` first. These are critical in higher
level portions of the code, especially that in `b.c`.

Misc notes, no particular order:

* General conventions:
	* Types are abbreviated to single letters:
	  * `f` float
		* `i` int
		* `j` long
		* `c` byte
		* `s` string 
		* `k` internal b value (name probably comes from Q's k.h)
  * `x` generally is a locally-defined variable that contains the argument we are operating on
  * Likewise, these same functions are defined for `y`, `r`, and `z`.
* Values:
	* An elements length is stored as an int in the item *before* the pointer, so:
	* `xn` calls `xI[-1]` where:
		* `xI` basically does `(int*)x`
		* `xJ`, `xF`, 
	* There are other, related functions (implemented as macros in `a.h`):
		* `xm` accesses x[-8], which is the memory allocated to the value
		* `xr` accesses x[-7], which is the ref count
		* `xu` accesses x[-6], which I think are the attributes 
		* `xt` accesses x[-5], which is the type
* Common functions:
	* `j2` joins two items into a list.
	* `nt` is the size in bytes of each of the types


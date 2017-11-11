CC=gcc -std=gnu11
CF=-fnested-functions -minline-all-stringops -fno-asynchronous-unwind-tables -fno-stack-protector -Wall -Wno-pointer-sign -Wno-strict-aliasing -Wno-parentheses -Wno-unused-function
LF=-s -nostdlib A.S

b: a.c b.c *.h makefile
	$(CC) -Os -o $@ $(LF) a.c b.c $(CF)

k: a.c k.c *.h makefile
	$(CC) -Os -o $@ $(LF) a.c k.c $(CF)

all: b k


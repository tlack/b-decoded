a[ii]$[x;a[-x;$[y;a[x;-y];1]];+y]
b[Ii]{h:#x;l:0;W(h>l)$[y>x[i:/l+h];l:i+1;h:i];l}
f[iII]{m:0;$[k:-x;W(x){x-:1;j:*y;N(k)y[i]:y[+i];y[k]:j;j:f[k;y;z];$[m<j;m:j;]};{N(#y)z[i]:y[i];W(j:*z){m+:1;N(j){k:z[i];z[i]:z[j];z[j]:k;j-:1}}}];m}
t[ii]$[y;[x;t[-x*2;y];t[x*2;y-:1]];[x;;]]
c[J]$[x[1];(*x)+c[x[1]]-c[x[2]];*x]
m[i]{k:0;N(x){r:-1.5+2*i%x;N(x){s:-1+2*j%x;p:q:0.;m:50;W(m*4>(t:p*p)+u:q*q){m-:1;q:s+2*p*q;p:r+t-u};k+:0=m}};k}

/test
a[3;4]
x:!9
b[x;7]
y:!8
z:!8
f[#y;y;z]
w:t[0;2]
c[w]
m[10]

/time
\t:2000 a[3;4]
x:!1000
\t N(1000000)b[x;1023&i]
y:!8
z:!8
\t:20 f[#y;y;z]
\t:100 t[0;13]
w:t[0;13]
\t:100 c[w]
\t:30 m[100]





#include <stdio.h>   /*** (C) Achim Flammenkamp, Uni Bielefeld, 1998-05-17 ***/
#include <stdlib.h>  /* SUM_{p<x} 1/p = ln(ln(x))+0.5772156649015-0.315718452052 */
#ifndef  uns32
#define  uns32  unsigned
#endif
#ifndef  uns64
#define  uns64  unsigned long long
#endif
#ifdef   LONG
#undef   LONG
#define  LONG  uns64
#define  UL  "%llu"
#define  HALF  uns32
#else
#define  LONG  uns32
#define  UL  "%u"
#define  HALF  unsigned short
#endif

#define  BITS  8
#define  LCM  ((2*3*5)/3)
#ifdef  DEBUG
#define  use(x)  printf(UL"\n",x),  jj++;
#elif defined(TEST)
#define  use(x)  jj++;
#else
#include <math.h>
#define  use(x)  do { /**/if(max<x-last)printf(UL" "UL"\n",x,max=x-last);/**/ \
                      sum += 1.0/x, last=x; jj++; } while(0);
double  sum=0.0;
LONG  max=0, last=2;
#endif

main(unsigned argc, char *argv[])
{
unsigned char  *sieve, *diff, *modulo;
unsigned char  bi, c, b, m;  /* works only for stop < 20678048681^2 ~ 4*10^20 */
LONG  stop, start, *index, ii, jj, hh;
uns32  size, h, i, j, k, hi, ji, hj;
HALF  psize;
if (argc <= 1)
   return  fprintf(stderr,"usage: %s stop [start [size] ]\nversion 1.0a(%u:%u)"
                   "  1998-05-19\n", argv[0],sizeof(LONG)*BITS,3*LCM),0 ;
if (argc <= 3 || 1!=sscanf(argv[3],"%u",&size))
   size = (7*LCM)<<9; /* 35KB */
else
   size = 7*LCM*((69+size)/7/LCM);
if (argc <= 2 || 1!=sscanf(argv[2],UL,&start))
   start= 0;
if (argc <= 1 || 1!=sscanf(argv[1],UL,&stop))
   stop= 1;
#ifdef  DEBUG
fprintf(stderr,"sieve size= %u Byte\n",size);
#endif
if (!(sieve = calloc(size+1, sizeof(unsigned char))))
   return  fprintf(stderr,"error: can't get %u KB storage for sieve\n",
                         (sizeof(unsigned char)*size+1024)>>10), 2;
for (j=1,ii=stop;ii;ii>>=2,j+=j);  /* rough approximation of sqrt(stop) */
do {   /* newton-iteration for sqrt(stop) */
   i = j;
   j = (i+stop/i)/2;
} while (j < i);
if (j > 2*BITS*size)
   return  fprintf(stderr,"error: sieve size must be at least %u\n",j/2/BITS), 3;
for (h=j,i=0;h>>=1;i+=1);
psize = (3*j)/2/i;  psize += psize/9;  /* Pi(stop) approximation */
if (!(index = (LONG*) malloc((sizeof(LONG)+2)*psize)))
   return  fprintf(stderr,"error: can't get storage for %u primes\n",psize), 4;
diff = (unsigned char*)(index+psize);
modulo = diff+psize;
#ifdef  DEBUG
   fprintf(stderr,"# sieve primes <= %u   (%u kB)\n",psize,(3*psize+511)>>9);
#endif
jj=0;  if (start <= 2)   use(2);
hh = BITS*size*(start/3/size/BITS);
k=0;
i=0; h=0;
jj=1;
b=1<<h;
m=1;
while(1)
{  do
   {  b<<=1;  h++;
      m+= 2;  if (m >= 3*LCM)  m -= 3*LCM;
      jj += h<<3;
      if (!b)  b=1, i++;
   } while( sieve[i]&b );
   j= 2*h + 1;
   if (jj > stop)  break;
   if (k >= psize)
      fprintf(stderr,"overflow:  # sieve primes > %u\n",k);
   diff[k]= ((4*j+1)/3 - (k ? hj : 0))/2;
   hj= (4*j+1)/3;
   index[k]= jj/3;
   modulo[k]= m/3;
   if (jj < start)
      index[k] += LCM*j*((start/3-index[k])/LCM/j);
   if (index[k] < hh)
   {  modulo[k] += 2*((start/3-index[k])/2/j);
      if (modulo[k] >= LCM)  modulo[k] -= LCM;
      index[k] += 2*j*((start/3-index[k])/2/j);
      while (index [k] < hh || modulo[k]==1 || modulo[k]==8)
      {  index[k] += (modulo[k]&1 ? (hj>>1)|1 : hj);
         modulo[k]++;
         if (modulo[k] >= LCM)  modulo[k] -= LCM;
      }
   }
   index[k] -= hh;
   k++;
   ii = jj>>1;
   hi= ii&(BITS-1);
   ii >>= 3;
   if (ii >= size)
      continue;
   for (c=BITS;c;c--)
   {  bi = 1<<hi;
      ji= ii;
      while (ji < size)
      {  sieve[ji] |= bi;
         ji += j;
      }
      hi += j;
      ii += hi/BITS;
      hi &= BITS-1;
   }
}
if (k > psize) exit(1);
#ifdef  DEBUG
   fprintf(stderr,"# {primes <= sqrt("UL") < %u} = %u\n",stop,j,k+1);
#endif
jj= (start<=2);
if (start <= 3 && stop >= 3)   use(3);
if (start <= 5 && stop >= 5)   use(5);
hh *= 3;
while (1)
{  for (i=0;i<size;i++)
      sieve[i]=0;
   if (!hh)
      sieve[0] |= 1;
   i=(diff[0]+diff[1])<<1 | 1;
   for (h=2;h<k;h++)
   {  i += diff[h]<<1;
      ii = index[h];
      if (ii >= BITS*size)
      {  index[h] = ii - BITS*size;
         continue;
      }
#ifdef  true_64bit_words
#define  hi ii
#else
      hi = ii;
#endif
      bi = 1;
      j = (3*i+1)>>2;
      ji = (i>>1)|1;
      switch( modulo[h] )
      {   repeat:
          case 0:    while(hi >= size)
                     {  hi -= size;  bi+=bi;  
                        if (!bi)  {  modulo[h]=0;  goto out; }
                     }
                     sieve[hi] |= bi;  hi += 2*j;
          case 2:    while(hi >= size)
                     {  hi -= size;  bi+=bi;  
                        if (!bi)  {  modulo[h]=2;  goto out; }
                     }
                     sieve[hi] |= bi;  hi += i;
          case 3:    while(hi >= size)
                     {  hi -= size;  bi+=bi;  
                        if (!bi)  {  modulo[h]=3;  goto out; }
                     }
                     sieve[hi] |= bi;  hi += ji;
          case 4:    while(hi >= size)
                     {  hi -= size;  bi+=bi;  
                        if (!bi)  {  modulo[h]=4;  goto out; }
                     }
                     sieve[hi] |= bi;  hi += i;
          case 5:    while(hi >= size)
                     {  hi -= size;  bi+=bi;  
                        if (!bi)  {  modulo[h]=5;  goto out; }
                     }
                     sieve[hi] |= bi;  hi += ji;
          case 6:    while(hi >= size)
                     {  hi -= size;  bi+=bi;  
                        if (!bi)  {  modulo[h]=6;  goto out; }
                     }
                     sieve[hi] |= bi;  hi += i;
          case 7:    while(hi >= size)
                     {  hi -= size;  bi+=bi;  
                        if (!bi)  {  modulo[h]=7;  goto out; }
                     }
                     sieve[hi] |= bi;  hi += 2*j;
          case 9:    while(hi >= size)
                     {  hi -= size;  bi+=bi;  
                        if (!bi)  {  modulo[h]=9;  goto out; }
                     }
                     sieve[hi] |= bi;  hi += ji;
                 while (hi+LCM*j < size)
                 {   sieve[hi] |= bi;  hi += 2*j;
                     sieve[hi] |= bi;  hi += i;
                     sieve[hi] |= bi;  hi += ji;
                     sieve[hi] |= bi;  hi += i;
                     sieve[hi] |= bi;  hi += ji;
                     sieve[hi] |= bi;  hi += i;
                     sieve[hi] |= bi;  hi += 2*j;
                     sieve[hi] |= bi;  hi += ji;
                 }
                 goto  repeat;
      }
      out:
      index[h] = hi;
#ifdef  true_64bit_words
#undef  hi
#endif
   }
   if (start > hh)
   {  bi= 1 << ((start-hh)/3/size);
      hh += 3*size*((start-hh)/3/size);
      i = LCM*((start-hh)/3/LCM);
      goto entry;
   }
   for (bi=1;bi;bi+=bi)
   {  for (i=0;i<size;i++)
      {  entry:
         if (!(sieve[i]&bi))
         {  ii= hh+(3*i+1);
            if (ii > stop)  goto end;
            use(ii);
         }
         if (!(sieve[i+=2]&bi))
         {  ii= hh+(3*i+1);
            if (ii > stop)  goto end;
            use(ii);
         }
         if (!(sieve[i+=1]&bi))
         {  ii= hh+(3*i+2);
            if (ii > stop)  goto end;
            use(ii);
         }
         if (!(sieve[i+=1]&bi))
         {  ii= hh+(3*i+1);
            if (ii > stop)  goto end;
            use(ii);
         }
         if (!(sieve[i+=1]&bi))
         {  ii= hh+(3*i+2);
            if (ii > stop)  goto end;
            use(ii);
         }
         if (!(sieve[i+=1]&bi))
         {  ii= hh+(3*i+1);
            if (ii > stop)  goto end;
            use(ii);
         }
         if (!(sieve[i+=1]&bi))
         {  ii= hh+(3*i+2);
            if (ii > stop)  goto end;
            use(ii);
         }
         if (!(sieve[i+=2]&bi))
         {  ii= hh+(3*i+2);
            if (ii > stop)  goto end;
            use(ii);
         }
      }
      hh += 3*size;
   }
}
end:
printf("# {primes <= "UL"} = "UL"\n",stop,jj);
#ifdef  TEST
#elif  defined(DEBUG)
#else
printf("%.12lf  %.12lf\n",sum,(sum-(log(log((double)stop))+0.5772156649015-0.315718452052))*sqrt((double)stop));
#endif
}

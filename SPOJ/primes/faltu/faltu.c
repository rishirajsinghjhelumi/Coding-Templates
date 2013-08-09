p(c){putchar(   c);}f(x,y,m){
	(y=m-   abs(m   -y))-   m&&m-
		x?f(x   <m?y:x&m,x<m?   x:y,m
				/2):p                   (x-m-
					1&&y?32:64);}   main(z){for(z
						=N*N;   z--;p        
						(z%N?32:10))f   (z%N,z/N,N);}

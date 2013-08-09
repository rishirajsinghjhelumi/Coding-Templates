main(){char*c=" _.+=#\n)rezneuM drahnreB(xx.xxx@xxx";int x,t,y;float a,
	b,d;for(y=0;y<25;y++){for(x=0;x<80;x++){t=b=d=0;do{a=b*b-d*d-2.1+.035*x
		;d=2*b*d+.088*y-1.1;b=a;t++;}while(t<32&&b*b+d*d<4);putchar(c[x>79?6:y>
				23&&x<28?34-x:t>31?0:t>>4?5:t>>3?4:t>>2?3:t>>1?2:1]);}}} /*xxx@xxx.xx*/

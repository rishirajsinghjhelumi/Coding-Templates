#include<vector>
#include<stdio.h>
#define len 
void sieve () {

	auto std::vector<bool> sieve(LEN,true); //LEN = length of sieve

	int i , j , k , i2 ;


	for( i = 3 ; i <= SR ; i += 2 ) {   //SR is sqrt(LEN)

		while( sieve[i]==false )
			i+=2;

		j = i*(i-2);
		i2 = i<<1 ;

		while( ( j = i2+j ) <= LEN )
			sieve[j]=false;

	}

	prime [0] = 2 ;

	for( i = 3 , j = 1 , k = 1 ; i <= LEN ; i += 2 )

		if( sieve[i] )
			prime [k++] = i ;

}

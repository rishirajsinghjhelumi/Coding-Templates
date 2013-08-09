#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>
const int nCompositeBuffSize = 100000010;
bool nIsComposite[nCompositeBuffSize] = { false, };
void print_primes_range( int nLowBound, int nUpBound )
{
	//assert( nUpBound-nLowBound < nCompositeBuffSize );
	int nSqRootOfUpBound = static_cast<int>( sqrt( nUpBound ) );
	for( int i=2; i<=nSqRootOfUpBound; i++ )
	{
		if( (i!=2 && i%2==0) || (i!=3 && i%3==0) || (i!=5 && i%5==0) )
			continue;

		int j;
		if( i>=nLowBound )
			j = i+i;
		else if( nLowBound%i == 0 )
			j = nLowBound;
		else
			j = nLowBound - nLowBound%i + i;
		for( ; j<=nUpBound; j+=i )
		{
			nIsComposite[j-nLowBound] = true;
		}
	}
	for( int i=nLowBound==1 ? 2 : nLowBound; i<=nUpBound; i++ )
		if( !nIsComposite[i-nLowBound] )
			printf( "%d\n", i );
}

int main()
{
	int nCases;
	std::cin >> nCases;
	for( int i=0; i<nCases; i++ )
	{
		int nLowLimit, nUpLimit;
		std::cin >> nLowLimit >> nUpLimit;
		print_primes_range( nLowLimit, nUpLimit );
		printf( "\n" );
	}
}

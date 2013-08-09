/**
 * Copyright 2003 by Steven S. Skiena; all rights reserved. 
 *
 * Permission is granted for use in non-commerical applications provided this 
 * copyright notice remains intact and unchanged.
 * 
 * This file contains the structure for representing big numbers. In addition, 
 * this file contains functions for adding, subtracting, multiplying, and
 * dividing very large numbers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIGITS 1000001    // Maximum Length Bignum 

#define PLUS        1    // Positive Sign Bit
#define MINUS      -1    // Negative Sign Bit

/** Struct for big numbers */
typedef struct {
	char digits[ MAXDIGITS ];  // Represent the number
	int signbit;               // 1 if positive, -1 if negative 
	int lastdigit;             // Index of high-order digit
} bignum;

/** Function headers declarations */
void print_bignum( bignum* n );
void string_to_bignum( char* s, bignum* n );
void int_to_bignum( int s, bignum* n );
void initialize_bignum( bignum* n );
void zero_justify( bignum* n );
void add_bignum( bignum* a, bignum* b, bignum* c );
void subtract_bignum( bignum* a, bignum* b, bignum* c );
void digit_shift( bignum* n, int d );
void multiply_bignum( bignum* a, bignum* b, bignum* c );
void divide_bignum(bignum *a, bignum *b, bignum *c);
int max( int a, int b );
int compare_bignum( bignum* a, bignum* b );

/** Prints big number */
void print_bignum( bignum* n )
{
	int i;

	if( n->signbit == MINUS ) printf( "-" );

	for( i = n->lastdigit; i >= 0; i-- )
	{
		printf( "%c", '0' + n->digits[ i ] );
	}

	printf("\n");
}

/** Converts a string to a big number */
void string_to_bignum( char* s, bignum* n )
{
	int i, j; 

	for( i = 0; i < MAXDIGITS; i++ )
	{
		n->digits[ i ] = ( char ) 0;
	}

	n->lastdigit = -1;

	for( j = strlen( s ) - 1; j > 0; j-- )
	{
		n->lastdigit++;
		n->digits[ n->lastdigit ] = s[ j ] - '0';
	}

	// Check if the last character is a minus sign or a digit
	if( s[ 0 ] == '-' )
	{
		n->signbit = MINUS;
	}
	else
	{
		n->lastdigit++;
		n->digits[ n->lastdigit ] = s[ 0 ] - '0';

		n->signbit = PLUS;
	}
}

/** Converts an integer to a big number */
void int_to_bignum( int s, bignum* n )
{
	int i, t;

	n->signbit = s >= 0 ? PLUS : MINUS;

	for( i = 0; i < MAXDIGITS; i++ )
	{
		n->digits[ i ] = ( char ) 0;
	}

	n->lastdigit = -1;

	t = abs( s );

	while( t > 0 ) 
	{
		n->lastdigit++;
		n->digits[ n->lastdigit ] = (t % 10);
		t = t / 10;
	}

	if( s == 0 )
	{
		n->lastdigit = 0;
	}
}

/** Initializes a big number */
void initialize_bignum( bignum* n )
{
	int_to_bignum( 0, n );
}

/** Returns the greatest of two integers */
int max( int a, int b )
{
	return a > b ? a : b;
}

/** Zero justifies a big number */
void zero_justify( bignum* n )
{
	while( ( n->lastdigit > 0 ) && ( n->digits[ n->lastdigit ] == 0 ) )
	{
		n->lastdigit--;
	}

	if( ( n->lastdigit == 0 ) && ( n->digits[ 0 ] == 0 ) )
	{
		n->signbit = PLUS;    /* hack to avoid -0 */
	}
}

/** Adds big numbers; i.e. c = a + b */
void add_bignum( bignum* a, bignum* b, bignum* c )
{
	int carry;            /* carry digit */
	int i;                /* counter */

	initialize_bignum( c );

	if( a->signbit == b->signbit )
	{
		c->signbit = a->signbit;
	}
	else 
	{
		if( a->signbit == MINUS ) 
		{
			a->signbit = PLUS;
			subtract_bignum( b, a, c );
			a->signbit = MINUS;
		} 
		else 
		{
			b->signbit = PLUS;
			subtract_bignum( a, b, c );
			b->signbit = MINUS;
		}

		return;
	}

	c->lastdigit = max( a->lastdigit, b->lastdigit ) + 1;
	carry = 0;

	for( i = 0; i <= ( c->lastdigit ); i++ ) 
	{
		c->digits[ i ] = ( char ) ( carry + a->digits[ i ] + b->digits[ i ] ) % 10;
		carry = ( carry + a->digits[ i ] + b->digits[ i ] ) / 10;
	}

	zero_justify( c );
}

/** Subtracts big numbers; i.e. c = a - b */
void subtract_bignum( bignum* a, bignum* b, bignum* c )
{
	int borrow;           /* has anything been borrowed? */
	int v;                /* placeholder digit */
	int i;                /* counter */

	initialize_bignum( c );

	if( ( a->signbit == MINUS ) || ( b->signbit == MINUS ) ) 
	{
		b->signbit = -1 * b->signbit;
		add_bignum( a, b, c );
		b->signbit = -1 * b->signbit;
		return;
	}

	if( compare_bignum( a, b ) == PLUS ) 
	{
		subtract_bignum( b, a, c );
		c->signbit = MINUS;
		return;
	}

	c->lastdigit = max( a->lastdigit, b->lastdigit );
	borrow = 0;

	for( i = 0; i <= ( c->lastdigit ); i++ ) 
	{
		v = ( a->digits[ i ] - borrow - b->digits[ i ] );

		if( a->digits[ i ] > 0)
		{
			borrow = 0;
		}

		if( v < 0 ) 
		{
			v = v + 10;
			borrow = 1;
		}

		c->digits[ i ] = ( char ) v % 10;
	}

	zero_justify( c );
}

/** Compares big numbers */
int compare_bignum( bignum* a, bignum* b )
{
	int i;                /* counter */

	if( ( a->signbit == MINUS ) && ( b->signbit == PLUS ) ) return( PLUS );
	if( ( a->signbit == PLUS ) && ( b->signbit == MINUS ) ) return( MINUS );

	if( b->lastdigit > a->lastdigit ) return( PLUS * a->signbit );
	if( a->lastdigit > b->lastdigit ) return( MINUS * a->signbit );

	for( i = a->lastdigit; i >= 0; i-- )
	{
		if( a->digits[ i ] > b->digits[ i ] ) return( MINUS * a->signbit );
		if( b->digits[ i ] > a->digits[ i ] ) return( PLUS * a->signbit );
	}

	return( 0 );
}

/** Multiplies a big number by 10^d */
void digit_shift( bignum* n, int d )
{
	int i;                /* counter */

	if( ( n->lastdigit == 0 ) && ( n->digits[ 0 ] == 0 ) ) return;

	for( i = n->lastdigit; i >= 0; i-- )
	{
		n->digits[ i + d ] = n->digits[ i ];
	}

	for( i = 0; i < d; i++ )
	{
		n->digits[ i ] = 0;
	}

	n->lastdigit = n->lastdigit + d;
}

/** Multiplies big numbers; i.e. c = a * b */
void multiply_bignum( bignum* a, bignum* b, bignum* c )
{
	bignum row;            /* represent shifted row */
	bignum tmp;            /* placeholder bignum */
	int i, j;              /* counters */

	initialize_bignum( c );
	row = *a;

	for( i = 0; i <= b->lastdigit; i++ ) 
	{
		for( j = 1; j <= b->digits[ i ]; j++ ) 
		{
			add_bignum( c, &row, &tmp );
			*c = tmp;
		}
		digit_shift( &row, 1 );
	}

	c->signbit = a->signbit * b->signbit;
	zero_justify( c );
}

/** Divides big numbers; i.e. c = a / b */
void divide_bignum(bignum *a, bignum *b, bignum *c)
{
	bignum row;              /* represent shifted row */
	bignum tmp;              /* placeholder bignum */
	int asign, bsign;        /* temporary signs */
	int i;                   /* counters */

	initialize_bignum( c );
	c->signbit = a->signbit * b->signbit;

	asign = a->signbit;
	bsign = b->signbit;

	a->signbit = PLUS;
	b->signbit = PLUS;

	initialize_bignum( &row );
	initialize_bignum( &tmp );

	c->lastdigit = a->lastdigit;

	for( i = a->lastdigit; i >= 0; i-- ) 
	{
		digit_shift( &row, 1 );
		row.digits[ 0 ] = a->digits[ i ];
		c->digits[ i ] = 0;
		while( compare_bignum( &row, b ) != PLUS ) 
		{
			c->digits[ i ]++;
			subtract_bignum( &row, b, &tmp );
			row = tmp;
		}
	}

	zero_justify( c );

	a->signbit = asign;
	b->signbit = bsign;
}

/** Test Function */
int main( )
{
	bignum n1, n2, n3, zero;

	// Instantiate string buffers for big numbers a and b
	char* a = calloc( MAXDIGITS, sizeof( char ) );
	char* b = calloc( MAXDIGITS, sizeof( char ) );

	// Get big numbers a and b as strings
	printf( "a = " );
	fgets( a, MAXDIGITS, stdin );

	printf( "b = " );
	fgets( b, MAXDIGITS, stdin );

	// Remove the newline character (if present) from string buffers
	char* nl;
	if( ( nl = strchr( a, '\n' ) ) != NULL ) *nl = '\0';
	if( ( nl = strchr( b, '\n' ) ) != NULL ) *nl = '\0';

	// Create a and b big number instances via the string buffers
	string_to_bignum( a, &n1 );
	string_to_bignum( b, &n2 );

	// Test addition
	add_bignum( &n1, &n2, &n3 );
	printf( "a + b = " );
	print_bignum( &n3 );

	// Test comparison
	int comparison = compare_bignum( &n1, &n2 );
	printf( "a %s b\n", comparison == 0 ? "==" : ( comparison < 0 ? ">" : "<" ) );

	// Test subtraction
	subtract_bignum( &n1, &n2, &n3 );
	printf( "a - b = " );    
	print_bignum( &n3 );

	// Test multiplication
	multiply_bignum( &n1, &n2, &n3 );
	printf( "a * b = " );
	print_bignum( &n3 );

	// Test division
	int_to_bignum( 0, &zero );
	if( compare_bignum( &zero, &n2 ) == 0 )
	{
		printf( "a / b = NaN\n" );
	}
	else 
	{
		divide_bignum( &n1, &n2, &n3 );
		printf( "a / b = " );
		print_bignum( &n3 );
	}

	return 0;
}

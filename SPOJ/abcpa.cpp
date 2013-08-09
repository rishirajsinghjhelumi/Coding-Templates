#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

#define DEBUG 0
using namespace std;

struct A {
	int x;
	int y;
	A( int i, int j ) : x(i), y(j) {}
};

bool operator < ( A const& a, A const& b )
{
	if( a.x != b.x || a.y != b.y )
		return true;
	else
		return false;
}

int main ()
{
	int H, W;
	int k = 1;
	while( scanf( "%d %d\n", &H, &W ) )
	{ 
		if( H == 0 && W == 0 )
			break;
		vector<vector<int> > M;
		set<A> As;
		char c;
		//vector<int> fRow( W+2 );
		M.push_back(vector<int>( W+2 ));
		for( int i=0; i<H; ++i )
		{
			vector<int> nums;
			nums.push_back( 0 );
			for( int j=0; j<W+1; ++j )
			{
				scanf( "%c", &c );
				nums.push_back( (int)c );
				if( (int)c == 65 )
					As.insert( A( i+1, j+1 ) );
			}
			M.push_back( nums );
		}
		M.push_back(vector<int>( W+2 ));

#if DEBUG
		// print vector<vector>
		for(int i=0; i<H+2; ++i )
		{
			for( int j=0; j<W+2; ++j )
			{
				cout << M[i][j] << " ";
			}
			cout << endl;
		}

		for(set<A>::iterator i = As.begin(); i!=As.end(); ++i)
		{
			cout << i->x << ", " << i->y << endl;
		}
#endif

		// do breadth first search until we cannot go any further
		int d = (As.empty( ))?0:1;
		while( 1 )
		{
			set<A> newLocations;
			for( set<A>::iterator i = As.begin(); i!=As.end(); ++i )
			{
				// check all 8 paths from a cell
				if( M[i->x-1][i->y-1] == M[i->x][i->y]+1 )
					newLocations.insert( A( i->x-1, i->y-1 ) );
				if( M[i->x][i->y-1] == M[i->x][i->y]+1 )
					newLocations.insert( A( i->x, i->y-1 ) );
				if( M[i->x+1][i->y-1] == M[i->x][i->y]+1 )
					newLocations.insert( A( i->x+1, i->y-1 ) );
				if( M[i->x-1][i->y] == M[i->x][i->y]+1 )
					newLocations.insert( A( i->x-1, i->y ) );
				if( M[i->x+1][i->y] == M[i->x][i->y]+1 )
					newLocations.insert( A( i->x+1, i->y ) );
				if( M[i->x-1][i->y+1] == M[i->x][i->y]+1 )
					newLocations.insert( A( i->x-1, i->y+1 ) );
				if( M[i->x][i->y+1] == M[i->x][i->y]+1 )
					newLocations.insert( A( i->x, i->y+1 ) );
				if( M[i->x+1][i->y+1] == M[i->x][i->y]+1 )
					newLocations.insert( A( i->x+1, i->y+1 ) ); 
			}			
			if( !newLocations.empty( ) )
			{
				++d;
				As = newLocations;
			}
			else
				break;
			if( d == 26 )
				break;
		}	
		cout << "Case " << k++ << ": " << d << endl;
	}
}


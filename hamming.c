#include <stdlib.h>
#include <stdio.h>
#include <time.h>               /* Random integer function */
#include <math.h>               /* Square root function */

int
rand_binary()
{
	return rand() % 2;
}

void
rand_string( int *arr, int size )
{
	for ( int i = 0; i < size; i++ )
	{
		arr[ i ] = rand_binary();
	}
}

/*
        Print in neat rows that are sqrt( size )
        in length.
 */

void
print_string( int *arr, int size )
{
	for ( int i = 0; i < size; i++ )
	{
		printf( "%d ", arr[ i ] );
		
		if ( ( i+1 ) % ( int ) sqrt( size ) == 0 )
		{
			printf( "\n" );
		}
	}
}

int
reduce( int *arr, int size )
{
	int                     error = 0;
	
	for ( int i = 0; i < size; i++ )
	{
		if ( arr[ i ] )
		{
			error ^= i;
		}
	}

	return error;
}

void
set_parity_bits( int *arr, int size, int error )
{
	if ( error == 0 )
	{
		return;
	}

	for ( int j = size / 2; j > 0; j /= 2 )
	{
		if ( error & j )
		{
			arr[ j ] = !arr[ j ];
		}
	}
}

int
main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		return 0;
	}
	
        int                     size = atoi( argv[ 1 ] );
	int                     parity = ( int ) sqrt( size );

	if ( sqrt( size ) - parity != 0 )
	{
		printf( "Error: size must have a whole number as its root: sqrt( %d ) -> %f\n", size, sqrt( size ) );
		return 1;
	}

	int*                    arr;
	int                     error;
	int                     messageSize = size - parity + 1;

	/*
	        Initialize time library for random int function
	 */

	srand( time( NULL ) );
	
	arr = ( int * ) malloc( sizeof( int ) * size );

	printf( "size: %d bits\n", size );
	printf( "parity: %d + 1 = %d bits\n", parity, parity + 1 );
	printf( "message: %d bits ~ %d bytes\n", messageSize, messageSize / 8 );

	/*
		Set the byte arry to random binary values (1 or 0).
	 */

	rand_string( arr, size );
	
	print_string( arr, size );
	
	/*
		The reduce function detects the presence of an error in
		the byte array.
	 */

	error = reduce( arr, size );
	printf( "error = %d\n", error );

	/*
		The parity bits is used to check sections of the byte 
		array, narrow down where an error lies, and correct it.
	 */

	set_parity_bits( arr, size, error );
	
	print_string( arr, size );

	error = reduce( arr, size );
	printf( "error = %d\n", error );
}


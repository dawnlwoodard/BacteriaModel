#include "Bacteria.h"

using namespace std;

Bacteria::Bacteria()
{

	bacteria.push_back( new Bacterium() );
	bacteria.push_back( new Bacterium() );
	bacteria.push_back( new Bacterium() );
	bacteria.push_back( new Bacterium() );
	bacteria.push_back( new Bacterium() );
	bacteria.push_back( new Bacterium() );
	bacteria.push_back( new Bacterium() );
	bacteria.push_back( new Bacterium() );
	bacteria.push_back( new Bacterium() );
	bacteria.push_back( new Bacterium() );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );
	printf("Number of bacteria: %d\n", get_number()); remove( 0 );

}

Bacteria::~Bacteria()
{

}

int Bacteria::get_number()
{

	return (int)bacteria.size();

}

bool Bacteria::remove( int index )
{

	if ( index < bacteria.size() )
	{

		bacteria.erase( bacteria.begin() + index );
		return true;

	}
	else
	{

		fprintf(stderr, "Invalid bacteria index (%d)!\n", index);
		return false;

	}

}

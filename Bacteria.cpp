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
	printf("Number of bacteria: %d\n", (int)bacteria.size());

}

Bacteria::~Bacteria()
{

}

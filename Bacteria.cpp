#include "Bacteria.h"
#include "Lineage.h" 
#include <iostream>


using namespace std;

Bacteria::Bacteria( int pop0, int generations )
{
	for (int i = 0; i < pop0; i++)
		bacteria.push_back( new Lineage(generations) );

	
	for (int i = 0; i<generations-1; i++)
		for (int j = 0; j < bacteria.size(); j++)
			bacteria[j]->divide();
	printf("Number of lineages: %d\n", get_number());
	printf("Population size: %d\n", get_pop());
}

Bacteria::~Bacteria()
{

}

int Bacteria::get_number()
{
	return (int)bacteria.size();
}

int Bacteria::get_pop()
{
	int pop = 0;
	for (int i=0;i<bacteria.size();i++)
	{
		pop += bacteria[i]->get_size();	
	}
	return pop;
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

#include "Bacteria.h"
#include "Lineage.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

Bacteria::Bacteria( int pop0, int generations, int k )
{
	this->k = k;

	for (int i = 0; i < (int)pop0; i++)
		bacteria.push_back( new Lineage(generations) );

	
	for (int i = 0; i < (int)generations-1; i++)
		for (int j = 0; j < (int)bacteria.size(); j++)
			bacteria[j]->divide();
	this->random();
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
	for (int i=0;i < (int)bacteria.size();i++)
	{
		pop += bacteria[i]->get_size();	
	}
	return pop;
}

int Bacteria::get_death_prob()
{
	int prob = 2*this->get_pop()*(1-this->get_pop()/k);
    return prob;
}

bool Bacteria::remove( int lin, int death_prob )
{

	if ( lin < (int)bacteria.size() )
	{

		bacteria[lin]->random(death_prob);
		return true;

	}
	else
	{

		fprintf(stderr, "Invalid bacteria index (%d)!\n", lin);
		return false;

	}

}

void Bacteria::random()
{
	printf("Removing within %d lineages\n", this->get_number());
	int death_prob = this->get_death_prob();

	for (int i = 0; i < this->get_number(); i++)
	{
		printf("removing within lineage %d\n", i); 
		this->remove(i, death_prob);
	}
}

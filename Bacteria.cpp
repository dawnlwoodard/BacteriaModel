#include "Bacteria.h"
#include "Lineage.h"
#include "Plot.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

Bacteria::Bacteria( int pop0, int generations, int k )
{

	this->plot = Plot::CreateInstance();

	this->k = k;
	this->generations = generations;
	
	this->initialize( pop0 );
	this->generate();

	if ( debug ) printf("Number of lineages: %d\n", get_number());
	if ( debug ) printf("Population size: %d\n", get_pop());
}

Bacteria::~Bacteria()
{

}
void Bacteria::initialize(int pop0)
{

	pops.resize(generations+1); pops[0] = pop0;
	for (int i = 0; i < (int)pop0; i++)
		bacteria.push_back( new Lineage(generations) );
	this->random();
}

void Bacteria::generate()
{

	for (int i = 0; i < (int)generations; i++)
	{
		new_generation(i);
		this->random();
	}
}

void Bacteria::new_generation(int gen)
{
		
	for (int j = 0; j < (int)bacteria.size(); j++)
	{
		if (debug) printf("Dividing in lineage %d\n",j);
		bacteria[j]->divide();

		pops[gen+1] = get_pop();
		if ( debug ) printf("Population = %d\n", get_pop());
	}			

}

void Bacteria::get_pop_vector( vector<int> &pops )
{

	pops = this->pops;
	
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

	if ( debug ) printf("Removing within %d lineages\n", this->get_number());
	int death_prob = this->get_death_prob();

	//Tell every lineage to randomly erase bacteria
	for (int i = 0; i < this->get_number(); i++)
	{
		if ( debug ) printf("removing within lineage %d\n", i); 
		this->remove(i, death_prob);
	}	

	//Take out lineages that have no more bacterium in them
	int size = bacteria.size();
	for (int i = 0; i < size; i++)
	{
		if ( debug ) printf("Size of lineage %d = %d\n", i, bacteria[i]->get_size());
		if (bacteria[i]->get_size() == 0)
			bacteria.erase(bacteria.begin() + i);
		if ( debug ) printf("Number of lineages = %d\n", (int)bacteria.size());
	}

}

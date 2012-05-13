#include "Bacteria.h"
#include "Lineage.h"
#include "Plot.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

Bacteria::Bacteria( unsigned pop0, unsigned generations, unsigned cap )
{

	this->plot = Plot::CreateInstance();

	this->cap = cap;
	this->generations = generations;
	
	this->initialize( pop0 );
	this->generate();

}

Bacteria::~Bacteria()
{

}

//create initial deque of pop0 lineages, kill portion of these
void Bacteria::initialize(unsigned pop0)
{

	pops.resize(generations+1); pops[0] = pop0;
	for ( unsigned i = 0; i < pop0; i++ )
		bacteria.push_back( new Lineage() );
	this->remove();

}

//tell each lineage to create a new generation up through the maximum given (generations)
//after each generation is created, kill a portion of these
void Bacteria::generate()
{

	for (unsigned j = 0; j < (unsigned)generations; j++)
	{

		reproduce(j);
		this->remove();
		for (unsigned i = 0; i < (unsigned)bacteria.size(); i++)
			bacteria[i]->add_babies();

	}

}

//call each lineage within the deque and tell it to divide 
//get the population after each generation and put it in pops so growth can be plotted over time
void Bacteria::reproduce(unsigned gen)
{
	
	birthProb = 0.5;//1 - (double)this->get_pop()/(double)this->cap;
	for (unsigned j = 0; j < (unsigned)bacteria.size(); j++)
	{

		bacteria[j]->divide(birthProb);
		pops[gen+1] = get_pop();

	}			

}

//return vector of population values after each generation 
void Bacteria::get_pop_vector( vector<unsigned> &pops )
{

	pops = this->pops;		

}

//return total number of lineages in the deque bacteria
unsigned Bacteria::get_number()
{

	return (unsigned)bacteria.size();

}

//return total number of bacterium in all lineages within bacteria
unsigned Bacteria::get_pop()
{

	unsigned pop = 0;
	for ( iter = bacteria.begin(); iter != bacteria.end(); ++iter )
		pop += (*iter)->get_pop_size();
	return pop;

}

//calls remove on deque bacteria 
void Bacteria::remove()
{

	this->deathProb = (1.0*(double)this->get_pop())/(double)(this->cap + this->get_pop());
	
	//Tell every lineage to randomly erase bacteria
	for ( iter = bacteria.begin(); iter != bacteria.end(); ++iter )
		(*iter)->random(deathProb);

	bacteria.erase(remove_if(bacteria.begin(),bacteria.end(),*this), bacteria.end());

}

#include "Lineage.h"
#include "Bacterium.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Lineage::Lineage()
{

	//generate random resistance level from 0 to 0.99
	this->resistance = (double)(rand() % 10000)/(double)10000;
	this->initialize();

	if ( debug ) printf("resistance: %f\n", this->resistance);

}

Lineage::~Lineage()
{

}

//add initial bacterium to lineage with random resistance level
void Lineage::initialize()
{

	lineage.push_back( new Bacterium(resistance, -1) );

}

//add one new Bacterium to the lineage for each one for which randNum <= birthProb
bool Lineage::divide(double birthProb)
{

	//int randBirth = birthProb*(double)(rand() % (this->get_size()+1));	

	int size = (int)lineage.size();
	for ( int i = 0; i < size; i++ )
	{

		double randResist = (double)(rand() % 10000) / 1000000.0 - 0.005;
		double randNum = (double)(rand() % 100) / 100.0;
		if (randNum <= birthProb)
			lineage.push_back( new Bacterium(randResist + lineage[i]->get_resistance(), i) );
		if ( debug ) printf("dividing bacterium %d\n", i);

	}

/*	for ( int i = 0; i < randBirth; i++ )
	{

		int randBac = ( this->get_size() ) ? rand() % this->get_size() : 0;
		if ( !randBac ) continue;
			
		double randResist = (double)(rand() % 10000) / 1000000.0 - 0.005;
		lineage.push_back( new Bacterium(randResist + lineage[i]->get_resistance(), i) );
		

	}*/

	return true;

}

//erases Bacterium from lineage at the given index
bool Lineage::die(int index)
{

	if ( index < (int)lineage.size() )
	{

		lineage.erase( lineage.begin() + index );
		if ( debug ) printf("Bacterium %d died\n", index);
		return true;

	}
	else
	{

		fprintf(stderr, "Invalid index (%d)!\n", index);
		return false;

	}

} 

void Lineage::random(double death_prob)
{

	if ( debug ) printf("death_prob: %f\n", death_prob);
	//double randDeath = death_prob*(double)(rand() % (this->get_size()+1));
	//printf("randDeath = %f\n",randDeath);

	//if ( debug ) printf("removing %d bacteria from lineage\n",randNum);
/*	for ( int i = 0; i < randNum; i++ )
	{

		int randBac = ( this->get_size() ) ? rand() % this->get_size() : 0;
		if ( !randBac ) continue;
		this->die(randBac);

	}*/
		
	for (int i = 0; i < this->get_size(); i++)
	{
		
	    double randNum = (double)(rand() % 100) / 100.0;
	//	printf("randNum = %f\n", randNum);
		if (randNum <= death_prob)
			this->die(i);

	}
}

//returns length of lineage
int Lineage::get_size()
{

	return (int)lineage.size();

}

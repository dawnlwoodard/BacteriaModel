#include "Lineage.h"
#include "Bacterium.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Lineage::Lineage()
{

	this->resistance = (double)(rand() % 10000)/(double)10000;
	this->initialize();

	if ( debug ) printf("resistance: %f\n", this->resistance);

}

Lineage::~Lineage()
{

}

void Lineage::initialize()
{

	lineage.push_back( new Bacterium(resistance, -1) );

}

bool Lineage::divide()
{
	
	int size = (int)lineage.size();
	for ( int i = 0; i < size; i++ )
	{

		double randResist = (double)(rand() % 10000) / 1000000.0 - 0.005;
		lineage.push_back( new Bacterium(randResist + lineage[i]->get_resistance(), i) );
		if ( debug ) printf("dividing bacterium %d\n", i);

	}
	
	return true;

}

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
	int randNum = death_prob*(double)(rand() % (this->get_size()+1));
	if ( debug ) printf("removing %d bacteria from lineage\n",randNum);
	for ( int i = 0; i < randNum; i++ )
	{

		int randBac = ( this->get_size() ) ? rand() % this->get_size() : 0;
		if ( !randBac ) continue;
		this->die(randBac);

	}

}

int Lineage::get_size()
{

	return (int)lineage.size();

}

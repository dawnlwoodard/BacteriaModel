#include "Lineage.h"
#include "Bacterium.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Lineage::Lineage()
{

	//generate random resistance level from 0 to 0.9999
	this->resistance = (rand() % 10000)/10000.0;

	//add initial bacterium to lineage with random resistance level
	lineage.push_back( new Bacterium(resistance) );

}

Lineage::~Lineage()
{

}

//add one new Bacterium to the lineage for each one for which randNum < birthProb
void Lineage::divide(double birthProb)
{

	//int randBirth = birthProb*(double)(rand() % (this->get_size()+1));	

	for ( iter = lineage.begin(); iter != lineage.end(); ++iter )
	{

		double randResist = (double)(rand() % 10000) / 1000000.0 - 0.005;
		double randNum = (double)(rand() % 100) / 100.0;

		if (randNum < birthProb)// && !(*iter)->is_baby())
			lineage.push_back( new Bacterium(randResist + (*iter)->get_resistance()) );

	}

}

void Lineage::add_babies()
{

	for( iter = lineage.begin(); iter != lineage.end(); ++iter ) (*iter)->set_baby( false );

}

void Lineage::random(double deathProb)
{

	this->deathProb = deathProb;
	lineage.erase(remove_if(lineage.begin(),lineage.end(),*this), lineage.end());

}

//returns length of lineage
int Lineage::get_size()
{

	return (int)lineage.size();

}

//returns size of population
int Lineage::get_pop_size()
{

	return (int)lineage.size();

}

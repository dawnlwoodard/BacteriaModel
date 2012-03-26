#include "Lineage.h"
#include "Bacterium.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Lineage::Lineage(int generations)
{
	int resistance = rand() % 1;
	int pop0 = 1;
	for (int i = 0; i<pop0; i++)
		lineage.push_back(new Bacterium(resistance, 0));
}

Lineage::~Lineage()
{

}

bool Lineage::divide()
{
	
	/*if ( index < lineage.size() )
	{
		lineage.insert(lineage.begin() + index, new Bacterium());
		return true;

	}
	else
	{

		fprintf(stderr, "Invalid index (%d)!\n", index);
		return false;

	}*/
	int size = lineage.size();
	for (int i=0; i < size; i++)
	{
		deque<Bacterium
		lineage.insert(i+1, new Bacterium(lineage[size-1]->get_resistance() + 0.01,lineage[i]));
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

void Lineage::random(int death_prob)
{
	int randNum = rand() % this->get_size();
	printf("removing %d bacteria from lineage\n",randNum);
	for (int i=0; i<randNum; i++)
	{
		int randBac = rand() % this->get_size();
		this->die(randBac); 
	}
}

int Lineage::get_size()
{
	return (int)lineage.size();
}

#include "Lineage.h"
#include "Bacterium.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Lineage::Lineage(int generations)
{
	double resistance = (double)(rand() % 10000)/(double)10000; 
	this->initialize();

	if ( debug ) printf("resistance: %f\n", resistance);

	/*int pop0 = 1;
	for (int i = 0; i<pop0; i++)
		lineage.push_back(new Bacterium(resistance, 0));
	*/
}

Lineage::~Lineage()
{

}

void Lineage::initialize()
{
	lineage.push_back(new Bacterium(resistance,0));
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

	//deque<Bacterium*> temp;

/*	for (int i=0; i < (int)lineage.size(); i++)
	{
		double random = (double)(rand() % 10000) / (double)1000000 - 0.005;
		temp.insert(temp.end(), new Bacterium( random + lineage[i]->get_resistance(), i ));
	}
	
	printf("temp made with %d bacterium\n", temp.size());
*/
		
	int size = (int)lineage.size();
	for (int i=0; i < size; i++)
	{
		double random = (double)(rand() % 10000) / (double)1000000 - 0.005;
		lineage.push_back( new Bacterium(random + lineage[i]->get_resistance(),i) );
		if ( debug ) printf("added bacterium %d to lineage\n", i + 1);	
	}
//	temp.clear();
/*
	for (int i=0; i < (int)lineage.size(); i++)
		lineage.insert(lineage.end(), new Bacterium(lineage[i]->get_resistance() + 0.01,i));
*/
	
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
	int randNum = (rand() % (this->get_size()+1));
	if ( debug ) printf("removing %d bacteria from lineage\n",randNum);
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

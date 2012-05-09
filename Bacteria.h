#ifndef BACTERIA_H
#define BACTERIA_H

#include "Plot.h"
#include "Lineage.h"
#include "globals.h"
#include <deque>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Bacteria
{

	private:
		Plot* plot;
		deque<Lineage*> bacteria;
		deque<Lineage*>::iterator iter;
		vector<int> pops, deathRates;
		unsigned int generations;
		unsigned int cap;
		double birthProb;
		double deathProb;

	public:
		Bacteria( unsigned int pop0, unsigned int generations, unsigned int cap );
		~Bacteria();
		int get_number();
		void get_pop_vector( vector<int> &pops );
		void get_death_vector (vector<int> &deaths );
		int get_pop();
		void remove();
		void initialize(int pop0);
		void generate();
		void reproduce(int gen);
		bool operator() (Lineage* l)
		{

			return !l->get_size();

		}

};
#endif

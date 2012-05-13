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
		vector<unsigned> pops, deathRates;
		unsigned generations;
		unsigned cap;
		double birthProb;
		double deathProb;

	public:
		Bacteria( unsigned pop0, unsigned generations, unsigned cap );
		~Bacteria();
		unsigned get_number();
		void get_pop_vector( vector<unsigned> &pops );
		void get_death_vector (vector<unsigned> &deaths );
		unsigned get_pop();
		void remove();
		void initialize(unsigned pop0);
		void generate();
		void reproduce(unsigned gen);
		bool operator() (Lineage* l)
		{

			return !l->get_size();

		}

};
#endif

#ifndef BACTERIA_H
#define BACTERIA_H

#include "Plot.h"
#include "Lineage.h"
#include "globals.h"
#include <deque>
#include <vector>
#include <stdio.h>

using namespace std;

class Bacteria
{
	private:
		Plot* plot;
		deque<Lineage*> bacteria;
		vector<int> pops;
		int generations;
		int k;

	public:
		Bacteria( int pop0, int generations, int k );
		~Bacteria();
		int get_number();
		void get_pop_vector( vector<int> &pops );
		int get_pop();
		void remove();
		void initialize(int pop0);
		void generate();
		void new_generation(int gen);
		int get_death_prob(); 

};
#endif

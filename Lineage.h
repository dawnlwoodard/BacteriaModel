#ifndef LINEAGE_H
#define LINEAGE_H

#include "Bacterium.h"
#include "globals.h"
#include <deque>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Lineage
{

	private:
		deque<Bacterium*> lineage;
		deque<Bacterium*>::iterator iter;
		double resistance;
		double deathProb;
		double birthProb;

	public:
		Lineage();
		~Lineage();
		void divide(double birthProb);
		void add_babies();
		int get_size();
		int get_pop_size();
		vector<int> get_deaths();
		void random(double death_prob);
		bool operator() (Bacterium* b)
		{

			double randNum = (double)(rand() % 100) / 100.0;
			return (randNum < deathProb);

		}

};

#endif

#ifndef LINEAGE_H
#define LINEAGE_H

#include "Bacterium.h"
#include "globals.h"
#include <deque>
#include <stdio.h>

using namespace std;

class Lineage
{

	private:
		deque<Bacterium*> lineage;
		deque<Bacterium*> old_babies;
		deque<Bacterium*> new_babies;
		double resistance;
	public:
		Lineage();
		~Lineage();
		void initialize();
		bool divide(double birthProb);
		void add_babies();
		bool die(int index);
		int get_size();
		void random(double death_prob);

};

#endif

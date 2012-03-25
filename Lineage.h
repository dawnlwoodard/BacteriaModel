#ifndef LINEAGE_H
#define LINEAGE_H

#include "Bacterium.h"
#include <deque>
#include <stdio.h>

using namespace std;

class Lineage
{

	private:
		deque<Bacterium*> lineage;
		int resistance;
	public:
		Lineage(int generations);
		~Lineage();
		bool divide();
		bool die(int index);
		int get_size();
		void random(int death_prob);
};

#endif

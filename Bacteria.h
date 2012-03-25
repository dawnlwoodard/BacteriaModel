#ifndef BACTERIA_H
#define BACTERIA_H

#include "Lineage.h"
#include <deque>
#include <stdio.h>

using namespace std;

class Bacteria
{
	private:
		deque<Lineage*> bacteria;

	public:
		Bacteria( int pop0, int generations, int k );
		~Bacteria();
		int get_number();
		bool remove( int lin, int death_prob );
		int get_pop();
		void random();
		int get_death_prob(); 
		int k;
};
#endif

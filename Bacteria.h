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
		Bacteria( int pop0 );
		~Bacteria();
		int get_number();
		bool remove( int index );
		int get_pop();
};

#endif

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
		Bacteria();
		~Bacteria();
		int get_number();
		bool remove( int index );

};

#endif

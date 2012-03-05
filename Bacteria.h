#ifndef BACTERIA_H
#define BACTERIA_H

#include "Bacterium.h"
#include <deque>
#include <stdio.h>

using namespace std;

class Bacteria
{
	private:
		deque<Bacterium*> bacteria;

	public:
		Bacteria();
		~Bacteria();
		int get_number();
		bool remove( int index );

};

#endif

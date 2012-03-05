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

	public:
		Lineage();
		~Lineage();

};

endif

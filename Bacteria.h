#ifndef BACTERIA_H
#define BACTERIA_H

#include "Bacterium.h"
#include <vector>
#include <stdio.h>

using namespace std;

class Bacteria
{
	private:
		vector<Bacterium*> bacteria;

	public:
		Bacteria();
		~Bacteria();

};

#endif

#ifndef BACTERIUM_H
#define BACTERIUM_H

#include "globals.h"

using namespace std;

class Bacterium
{
	private:
		int resistance;
	public:
		Bacterium(int resistance, int parent);
		~Bacterium();
		int get_resistance();
};

#endif

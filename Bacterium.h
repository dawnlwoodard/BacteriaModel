#ifndef BACTERIUM_H
#define BACTERIUM_H

#include "globals.h"

using namespace std;

class Bacterium
{
	private:
		int resistance;
		int parent;
	public:
		Bacterium(double resistance, int parent);
		~Bacterium();
		int get_parent();
		double get_resistance();
};

#endif

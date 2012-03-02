#ifndef BACTERIA_H
#define BACTERIA_H

//#include "Bacterium.h"
#include <vector>

using namespace std;

class Bacteria
{
	private:
		vector<Bacteria*> bacteria;

	public:
		Bacteria();
		~Bacteria();

};

#endif

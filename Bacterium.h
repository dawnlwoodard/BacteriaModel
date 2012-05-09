#ifndef BACTERIUM_H
#define BACTERIUM_H

#include "globals.h"

using namespace std;

class Bacterium
{

	private:
		int resistance;
		int parent;
		bool baby_status;

	public:
		Bacterium(double resistance);
		~Bacterium();
		bool is_baby();
		void set_baby( bool baby_status );
		int get_parent();
		double get_resistance();

};

#endif

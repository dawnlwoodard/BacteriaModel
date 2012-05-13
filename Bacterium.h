#ifndef BACTERIUM_H
#define BACTERIUM_H

#include "globals.h"

using namespace std;

class Bacterium
{

	private:
		double resistance;
		bool baby_status;

	public:
		Bacterium(double resistance);
		~Bacterium();
		bool is_baby();
		void set_baby( bool baby_status );
		double get_resistance();

};

#endif

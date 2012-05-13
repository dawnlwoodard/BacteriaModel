#include "Bacterium.h"

using namespace std;

Bacterium::Bacterium(double resistance)
{

	this->resistance = resistance;
	set_baby( true );

}

Bacterium::~Bacterium()
{

}

double Bacterium::get_resistance()
{

	return this->resistance; 

}

bool Bacterium::is_baby()
{

	return this->baby_status;

}

void Bacterium::set_baby( bool baby_status )
{

	this->baby_status = baby_status;

}

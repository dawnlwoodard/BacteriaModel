#include "Bacterium.h"

using namespace std;

Bacterium::Bacterium(double resistance, int parent)
{

}

Bacterium::~Bacterium()
{

}

double Bacterium::get_resistance()
{
	return this->resistance; 
}

int Bacterium::get_parent()
{
	return this->parent;
} 

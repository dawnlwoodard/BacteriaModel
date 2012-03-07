#include "Lineage.h"
#include "Bacterium.h"

using namespace std;

Lineage::Lineage(int generations)
{
	int pop0 = 1;
	for (int i = 0; i<pop0; i++)
		lineage.push_back(new Bacterium());
}

Lineage::~Lineage()
{

}

bool Lineage::divide()
{
	
	/*if ( index < lineage.size() )
	{
		lineage.insert(lineage.begin() + index, new Bacterium());
		return true;

	}
	else
	{

		fprintf(stderr, "Invalid index (%d)!\n", index);
		return false;

	}*/
	int size = lineage.size();
	for (int i=0; i < size; i++)
		lineage.insert(lineage.end(), new Bacterium());
	 
	return true;
}

bool Lineage::die(int index)
{
	if ( index < (int)lineage.size() )
	{

		lineage.erase( lineage.begin() + index );
		return true;

	}
	else
	{

		fprintf(stderr, "Invalid index (%d)!\n", index);
		return false;

	}

} 

int Lineage::get_size()
{
	return (int)lineage.size();
}

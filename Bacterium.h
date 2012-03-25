#ifndef BACTERIUM_H
#define BACTERIUM_H

using namespace std;

class Bacterium
{
	private:
		int resistance;
	public:
		Bacterium(int resistance);
		~Bacterium();
		int get_resistance();
};

#endif

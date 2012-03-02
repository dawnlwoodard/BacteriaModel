#include <stdio.h>
#include "Plot.h"

using namespace std;

Plot* plot = Plot::CreateInstance();
const double pi = 3.141592653589793;

int main()
{

	char buffer[16];

	double P, P0, r, k;

	//P = (k*P0*exp(r*t)) / (k + P0*(exp(r*t)-1));

	char command[128];

	while (true)
	{

		printf("P0: ");
		scanf("%lf", &P0);

		printf("r:  ");
		scanf("%lf", &r);

		printf("k:  ");
		scanf("%lf", &k);

		sprintf(command, "f(x) = (%f*%f*exp(%f*x)) / (%f + %f*(exp(%f*x)-1))", k,P0,r,k,P0,r);
		plot->set_yrange(0,k+P0);
		plot->write( command );
		plot->write( "plot f(x)" );

	}

	delete(plot);

	return 0;

}

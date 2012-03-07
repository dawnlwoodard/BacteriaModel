#include <stdio.h>
#include "Plot.h"
#include "Bacteria.h"

using namespace std;

Plot* plot = Plot::CreateInstance();
const double pi = 3.141592653589793;

int main()
{

	char buffer[16];

	double P, P0, r, k;

	//P = (k*P0*exp(r*t)) / (k + P0*(exp(r*t)-1));

	char command[128];

	Bacteria* bacteria = new Bacteria( 2, 4 );

	/*while (true)
	{

		printf("P0: ");
		scanf("%lf", &P0);

		printf("r:  ");
		scanf("%lf", &r);

		printf("k:  ");
		scanf("%lf", &k);

		sprintf(command, "P(x) = (%f*%f*exp(%f*x)) / (%f + %f*(exp(%f*x)-1))", k,P0,r,k,P0,r); plot->write( command );
		sprintf(command, "k(x) = %f", k); plot->write( command );
		plot->set_yrange(0,1.05*k);
		plot->write( "plot P(x) lt 1, k(x) lt 3" );

	}

	delete(plot);*/

	return 0;

}

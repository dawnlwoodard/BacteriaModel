#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <vector>
#include "Plot.h"
#include "Bacteria.h"
#include "globals.h"

using namespace std;

bool debug = true;
bool userInput = true;
Plot* plot = Plot::CreateInstance();

void quit( int sig );

int main()
{

	unsigned int pop0 = 10;
	unsigned int gens = 10;
	unsigned int cap  = 500;
	double rate = 1.0;
	char command[128];

	Bacteria* bacteria;
	vector<int> pop, pops;

	// Initialize random seed.
	srand( (unsigned)time(NULL) );
	
	if ( userInput )
	{

		// Set pop0, gens, and cap to invalid values;
		pop0 = gens = cap = 0;

		// Wait for user to input valid values for pop0, gens, and cap.
		while ( pop0 == 0 ) { printf("Initial Population:    "); scanf("%d", &pop0); }
		while ( gens == 0 ) { printf("Number of Generations: "); scanf("%d", &gens); }
		while ( cap  == 0 ) { printf("Carrying Capacity:     "); scanf("%d", &cap);  }

	}
	else
	{

		printf("Initial Population:    %d\n", pop0);
		printf("Number of Generations: %d\n", gens);
		printf("Carrying Capacity:     %d\n", cap);

	}

	// Create bacteria object.
	bacteria = new Bacteria( pop0, gens, cap);
	
	// Set graphing window based on user input.
	plot->set_xrange(0, gens);
	plot->set_yrange(0, 1.05*cap);
	
	// Initialize gnuplot for three simultaneous plots.
	sprintf(command, "plot %d title \"Capacity\", '-' title \"Modeled\" with lp pt 7, '-' title \"Expected\" with lp pt 7", cap ); plot->write(command);

	// Send model data to gnuplot.
	bacteria->get_pop_vector( pops );
	for ( unsigned int i = 0; i <= gens; i++ )
	{

		sprintf(command, "%d %d", i, pops[i]); plot->write( command );

	}
	plot->write("e");

	// Send expected data to gnuplot.
	pop.resize( gens + 1 );
	for ( unsigned int i = 0; i <= gens; i++ )
	{

		// P(n+1) = P(n) + r*P(n)*(1-P(n)/k)
		if ( i == 0 ) pop[0] = pop0;
		else pop[i] = pop[i-1] + rate*pop[i-1]*( 1.0 - pop[i-1]/(double)cap );
		sprintf(command, "%d %d", i, pop[i]); plot->write( command );

	}
	plot->write("e");
	
	// Wait for CTRL+C from user.
	while (true) signal(2, &quit); return 0;

}

void quit( int sig )
{

	delete plot;
	exit(0);

}

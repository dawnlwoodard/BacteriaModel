#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <vector>
#include "Plot.h"
#include "Bacteria.h"
#include "globals.h"

using namespace std;

bool debug = false;
bool userInput = false;
Plot* plot = Plot::CreateInstance();

void quit( int sig );

int main( int argc, char* argv[] )
{

	unsigned int pop0 = 10;
	unsigned int gens = 100;
	unsigned int cap  = 250;

	unsigned int min  = 0;
	unsigned int max  = 0;

	double rate = 1.0;
	char command[128];

	Bacteria* bacteria;
	vector<unsigned int> pop, pops;

	if ( argc == 4 )
	{

		userInput = false;
		pop0 = atoi( argv[1] );
		gens = atoi( argv[2] );
		cap  = atoi( argv[3] );

	}

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

	// Initialize random seed.
	srand( (unsigned)time(NULL) );

	// UNCOMMENT FOR SCREENSHOTS (WILL UPDATE THIS LATER)
    //plot->write("set term png enhanced color");
	//char savefile[128];
	//sprintf(savefile, "screenshots/plot-%d-%d-%d.png", pop0, gens, cap);
	//sprintf(command,  "set out '%s'", savefile);
    //plot->write( command );

	// Create bacteria object.
	bacteria = new Bacteria( pop0, gens, cap);

	// Retrieve population vector.
	bacteria->get_pop_vector( pops );

	// Determine largest population in vector.
	for ( unsigned int i = 0; i <= gens; i++ )
		if ( pops[i] > max ) max = pops[i];
	if ( cap > max ) max = cap;

	// Set graphing window based on calculated ranges.
	plot->set_xrange(0, gens);
	plot->set_yrange(min, 1.01*max);

	// Set appropriate title for graph window.
	sprintf(command, "Bacteria Population (P0=%d, G=%d, K=%d)", pop0, gens, cap);
	plot->set_title( command );

	// Initialize gnuplot for three simultaneous plots.
	sprintf(command, "plot %d title '%s', '-' title '%s' with lp pt 7, '-' title '%s' with lp pt 7", cap, "Capacity", "Modeled", "Expected" ); plot->write(command);

	// Send model data to gnuplot.
	for ( unsigned int i = 0; i <= gens; i++ )
	{

		sprintf(command, "%d %d", i, pops[i]);
		plot->write( command );

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

	while (true) signal(2, &quit);

	return 0;

}

void quit( int sig )
{

	delete plot;
	exit(0);

}

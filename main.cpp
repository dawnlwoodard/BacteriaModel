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

char command[128], title[128], savefile[128];
vector<unsigned> pop, pops;

unsigned pop0 = 10;
unsigned gens = 100;
unsigned cap  = 250;
double rate   = 1.0;

unsigned minimum = 0;
unsigned maximum = 0;

void init_plot();
void send_data();
void quit( int sig );

int main( int argc, char* argv[] )
{

	Bacteria* bacteria;

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

	// Create bacteria object.
	bacteria = new Bacteria( pop0, gens, cap);

	// Retrieve population vector.
	bacteria->get_pop_vector( pops );

	// Determine largest population in vector.
	for ( unsigned i = 0; i <= gens; i++ )
		if ( pops[i] > maximum ) maximum = pops[i];
	if ( cap > maximum ) maximum = cap;

	// Initialize plot.
	init_plot();

	// Wait for CTRL-C signal.
	while (true) signal(2, &quit);

	return 0;

}

void init_plot()
{

	// Set graphing window based on calculated ranges.
	plot->set_xrange(0, gens);
	plot->set_yrange(minimum, 1.01*maximum);

	// Set appropriate title for graph window.
	sprintf(title, "Bacteria Population (P0=%d, G=%d, K=%d)", pop0, gens, cap);
	plot->set_title( title );

	// Initialize gnuplot for three simultaneous plots.
	sprintf(command, "plot %d title '%s', '-' title '%s' with lp pt 7, '-' title '%s' with lp pt 7", cap, "Capacity", "Modeled", "Expected" ); plot->write(command);

	// Send data to gnuplot.
	send_data();

	// Save a screenshot of the current instance.
	sprintf(savefile, "screenshots/plot-%d-%d-%d.png", pop0, gens, cap);
	plot->write("set term png enhanced");
	sprintf(command,  "set out '%s'", savefile);
	plot->write( command );
	plot->refresh();
	send_data();
	plot->write("set term x11");

}

void send_data()
{

	// Send model data to gnuplot.
	for ( unsigned i = 0; i <= gens; i++ )
	{

		sprintf(command, "%d %d", i, pops[i]);
		plot->write( command );

	}
	plot->write("e");

	// Send expected data to gnuplot.
	pop.resize( gens + 1 );
	for ( unsigned i = 0; i <= gens; i++ )
	{

		// P(n+1) = P(n) + r*P(n)*(1-P(n)/k)
		if ( i == 0 ) pop[0] = pop0;
		else pop[i] = pop[i-1] + rate*pop[i-1]*( 1.0 - pop[i-1]/(double)cap );
		sprintf(command, "%d %d", i, pop[i]); plot->write( command );

	}
	plot->write("e");

}

void quit( int sig )
{

	delete plot;
	exit(0);

}

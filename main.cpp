#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <vector>
#include "Plot.h"
#include "Bacteria.h"
#include "globals.h"

using namespace std;

Plot* plot = Plot::CreateInstance();
const double pi = 3.141592653589793;
deque<Bacteria*> plotBac;  

bool debug = false;
bool userInput = false;

void quit( int sig );

int main()
{

	int maxGen = 10;
	int pop0 = 10;
	int k = 500;
	double r = 1.0;

	srand( (unsigned)time(NULL) );

	char command[128];

	if ( userInput )
	{

		printf("Initial Population:    "); scanf("%d", &pop0);
		printf("Number of Generations: "); scanf("%d", &maxGen);
		printf("Carrying Capacity:     "); scanf("%d", &k);

	}
	else
	{

		printf("Initial Population:    %d\n", pop0);
		printf("Number of Generations: %d\n", maxGen);
		printf("Carrying Capacity:     %d\n", k);

	}

/*	for ( int i = 0; i <= maxGen ; i++ )
		plotBac.push_back( new Bacteria(pop0, i, k) );

	int max = 0;
	for ( int i = 0; i < (int)plotBac.size(); i++ )
	{

		int pop = plotBac[i]->get_pop();
		if ( pop > max ) max = pop;

	}*/

	Bacteria* bacteria = new Bacteria( pop0, maxGen, k);
	
	plot->set_xrange(0,maxGen);
	plot->set_yrange(0,k+100);
	
	sprintf(command, "plot %d title \"Capacity\", '-' title \"Modeled\" with lp pt 7, '-' title \"Expected\" with lp pt 7", k ); plot->write(command);

	vector<int> pops;
	bacteria->get_pop_vector( pops );
	for ( int i = 0; i <= maxGen; i++ )
	{
		sprintf(command, "%d %d", i, pops[i]);
		plot->write( command );
	}
	plot->write("e");

	vector<int> pop;
	pop.resize( maxGen + 1 );
	for ( int i = 0; i <= maxGen; i++ )
	{

		if ( i == 0 ) pop[0] = pop0;
		else pop[i] = pop[i-1] + r*pop[i-1]*( 1.0 - pop[i-1]/(double)k );
		// P(n+1) = P(n) + r*P(n)*(1-P(n)/k)

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

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
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
	int k = 2000;

	srand( (unsigned)time(NULL) );

	char command[128];

	if ( userInput )
	{

		printf("Initial Population:    "); scanf("%d", &pop0);
		printf("Number of generations: "); scanf("%d", &maxGen);
		printf("Carrying capacity:     "); scanf("%d", &k);

	}
	else
	{

		printf("Initial Population:    %d\n", pop0);
		printf("Number of generations: %d\n", maxGen);
		printf("Carrying capacity:     %d\n", k);

	}

	for ( int i = 0; i <= maxGen ; i++ )
		plotBac.push_back( new Bacteria(pop0, i, k) );

	int max = 0;
	for ( int i = 0; i < (int)plotBac.size(); i++ )
	{

		int pop = plotBac[i]->get_pop();
		if ( pop > max ) max = pop;

	}

	plot->set_xrange(0,maxGen);
	// later ymax should be somewhere slightly above carrying capacity
	plot->set_yrange(0,max);
	
	sprintf(command, "plot %d title \"Capacity\", '-' title \"Bacteria\" with lp pt 7", k); plot->write(command);
	for (int i = 0; i <= maxGen; i++)
	{	
		int size = plotBac[i]->get_pop();
		sprintf(command, "%d %d",i, size); plot->write( command );
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

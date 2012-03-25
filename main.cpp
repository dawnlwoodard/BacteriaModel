#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "Plot.h"
#include "Bacteria.h"

using namespace std;

Plot* plot = Plot::CreateInstance();
const double pi = 3.141592653589793;
deque<Bacteria*> plotBac;  

void quit( int sig );

int main()
{

	int maxGen;	
	double P0;
	int k;

	srand( (unsigned)time(NULL) );

	char command[128];

	printf("P0: ");
	scanf("%lf", &P0);
		
	printf("Number of generations: ");
	scanf("%d", &maxGen);	

	printf("Carrying capacity: ");
	scanf("%d", &k);	

	for (int i=0; i<maxGen;i++)
	{
		plotBac.push_back(new Bacteria(P0, maxGen, k));
	}

	int max = 0;
	for ( int i = 0; i < (int)plotBac.size(); i++ )
	{

		int pop = plotBac[i]->get_pop();
		if ( pop > max ) max = pop;

	}

	plot->set_xrange(0,maxGen);
	plot->set_yrange(0,max);
	plot->write("plot '-' with points");
	for (int i = 0; i < maxGen; i++)
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

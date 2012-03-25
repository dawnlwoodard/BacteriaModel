// Plot.cpp

#include "Plot.h"
#include <stdio.h>

Plot* Plot::pInstance = NULL;

Plot* Plot::CreateInstance()
{

	if (!pInstance) pInstance = new Plot();
	return pInstance;

}

Plot::Plot()
{

	gnuplot = popen("gnuplot -persist > /dev/null 2>&1","w");
	//write("set term postscript eps color");
	write("set title \"Bacteria Population Over Time\"");
	write("set xlabel \"Generations\"");
	write("set ylabel \"Population\"");
	write("set pointsize 0.75");
	write("set key off");
	set_xrange(0,100);
	set_yrange(0,100);

}

Plot::~Plot()
{

	write("set terminal x11 close 0");
	write("exit");
	pclose(gnuplot);

}

void Plot::set_xrange( double min, double max )
{

	char command[128];
	sprintf(command, "set xrange[%f:%f]",min,max);
	write( command );

}

void Plot::set_yrange( double min, double max )
{

	char command[128];
	sprintf(command, "set yrange[%f:%f]",min,max);
	write( command );

}

void Plot::write( const char* command )
{

	fprintf(gnuplot, "%s\n", command);
	fflush(gnuplot);

}

void Plot::refresh()
{

	write("replot");

}

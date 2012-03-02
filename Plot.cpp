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
	write("set xlabel \"Time\"");
	write("set xrange[0:]");
	write("set ylabel \"Population\"");
	write("set yrange[0:]");
	write("f(x) = exp(x)");
	write("plot f(x)");

}

Plot::~Plot()
{

	write("set terminal x11 close 0");
	write("exit");
	pclose(gnuplot);

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

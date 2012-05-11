// Plot.h

#ifndef PLOT_H
#define PLOT_H

#include <stdio.h>

using namespace std;

class Plot
{

	private:
		Plot();
        Plot(Plot const&){};
        void operator=(Plot const&){};
        static Plot* pInstance;
		FILE* gnuplot;

	public:
		~Plot();
		static Plot* CreateInstance();
		void set_xrange( double min, double max );
		void set_yrange( double min, double max );
		void set_title( const char* title );
		void write( const char* command );
		void refresh();

};

#endif

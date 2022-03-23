#include <vector>
#include <cmath>
#include <boost/tuple/tuple.hpp>

#include "gnuplot-iostream.h"

int main() {
	Gnuplot gp;
	gp << "set terminal qt title \"title\"" << std::endl;

	gp << "set title \"Heat Map generated from a file containing Z values only\" font \"Times New Roman, 12\"" << std::endl;
	gp << "unset key" << std::endl;
	gp << "set tic scale 0" << std::endl;

//Color runs from white to green
	//gp << "set palette rgbformula 9, 10, 15" << std::endl;
	//gp << "set colorbox user size .03, .6 noborder" << std::endl;
	gp << "set cbtics scale 0" << std::endl;
	//gp << "set cbrange[-50:50]" << std::endl;
	gp << "set cblabel font \"Times New Roman, 12\"" << std::endl;
	//gp << "unset cbtics" << std::endl;

	//gp << "set format cb \"%4.1f\"" << std::endl;

	gp << "set xrange[-0.5:24.5]" << std::endl;
	gp << "set yrange[-0.5:24.5]" << std::endl;

	gp << "FILE1 = \"IM_arr.txt\"" << std::endl;
	gp << "map1= FILE1" << std::endl;
	gp << "FILE2 = \"IM_arr_3row.txt\"" << std::endl;
	gp << "map2 = FILE2" << std::endl;
	gp << "set view map" << std::endl;

	gp << "set contour base" << std::endl;
	gp << "plot map2 using 2:1:3 with image, \\" << std::endl;
	gp << "map2 using 2:1:($3 == 0 ?\"\":sprintf(\"%g\",$3)) with labels font \"Times, 8\" textcolor rgbcolor \"white\"" << std::endl;

	//gp << "plot map1 matrix using 1:2:3 with image, \\" << std::endl;
	////gp << "map1 matrix using 1:2:($3 == 0 ?\"\":sprintf(\"%g\",$3)) with labels" << std::endl;
	//gp << "map1 matrix using 1:2:($3 == 0 ?\"\":sprintf(\"%g\",$3)) with labels" << std::endl;
	//gp << "shell" << std::endl;



}
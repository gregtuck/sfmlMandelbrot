#include <iostream>
#include <complex>
#include "MDBTsk.h"

uint32_t image[HEIGHT][WIDTH];



void computemdb::run()
{
	const int MAX_ITERATIONS = 500;

	uint32_t colour = (float)0xffffff * ((float)y / (float)HEIGHT);

	for (int x = 0; x < WIDTH; ++x)
	{
		std::complex<double> c(left + (x *(right - left) / WIDTH), top + (y *(bottom - top) / HEIGHT));

		std::complex<double> z(0.0, 0.0);

		int iterations = 0;

		while (abs(z) < 2.0 && iterations < MAX_ITERATIONS)
		{
			z = (z * z) + c;

			++iterations;
		}
		

		if (iterations == MAX_ITERATIONS)
		{
			
			image[y][x] = 0xff000000;
		}
		/*else if (iterations < 500 && iterations >= 400)
		{
			image[y][x] = 0xFF110000;
		}
		else if (iterations < 400 && iterations >= 6)
		{
			image[y][x] = 0xFF0000ff;
		}*/
		else
		{
			image[y][x] = 0xFF000000 | colour;
		}
	}
}
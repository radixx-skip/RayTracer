// RayTracer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "CImg.h"

int main()
{
	cimg_library::CImg<unsigned char> test(256, 256, 1, 3, 0);
	cimg_library::CImgDisplay disp;
	for (int i = 0; i < 255; i++)
	{
		for (int j = 0; j < 255; j++)
		{
			test(i, j, 1) = i;
			test(i, j, 2) = j;
			disp = test;
		}
	}
	disp.close();
	test.display();
    return 0;
}


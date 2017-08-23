// RayTracer.cpp : Defines the entry point for the console application.
//
#include <iostream>

#include "Camera.h"

int main()
{
	int I = 480;
	int J = 480;

	Camera cam(I, J, 200.0);
	cam.render();
	cam.display("Camera");
    return 0;
}


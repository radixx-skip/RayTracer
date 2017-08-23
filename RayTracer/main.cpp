// RayTracer.cpp : Defines the entry point for the console application.
//
#include <iostream>

#include "src\Camera.h"

int main()
{
	int I = 1280;
	int J = 640;

	Camera cam(I, J);
	cam.render();
	cam.display("Camera");
    return 0;
}


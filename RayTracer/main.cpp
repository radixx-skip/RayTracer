// RayTracer.cpp : Defines the entry point for the console application.
//
#include <iostream>

#include "Camera.h"
#include "World.h"
#include "ObjectHeaders.h"

int main()
{
	int I = 480;
	int J = 480;

	World& world = World::instance();
	world.add("objects.json");


	Camera cam(I, J, 200.0);
	cam.render();
	cam.display("Camera");
    return 0;
}


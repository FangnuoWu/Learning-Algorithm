#include <iostream>
#include "Dijkstra.h"

/**
 * You can use this file to test your code.
 */
int main()
{
	DijkstraProject2 pro;
	pro.readFromFile();
	for (int i = 0; i < pro.getNumber(); i++) {
		pro.set(i);
		pro.run1();
		pro.run2();
	}	
}


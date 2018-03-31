#include <omp.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "ParticleContainer.h"

using namespace std;

int main()
{
	ParticleContainer mParticleContainer;
	for (;;)
	{
		mParticleContainer.Tick(mParticleContainer.getMaxInterval());
		cout << sqrt(mParticleContainer.getPower()) <<" "<< mParticleContainer.getMaxInterval() << endl;
	}
	while (1);
	return 0;
}
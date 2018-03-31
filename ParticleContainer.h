#pragma once

#include <omp.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "Particle.h"

class ParticleContainer
{
public:
	double epsilon = 0.002;
	double t = 0;
	double G = 0.0000000000667;
	std::vector<Particle> mParticles;
	ParticleContainer()
	{
		for (int i = 1; i < 10; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				for (int k = 1; k < 10; k++)
				{
					mParticles.push_back(Particle(10000, Vector(i * 1, j * 1, k * 1)));
				}
			}
		}
	}

	double getMaxInterval()
	{
		double maxV2 = getMaxV2();
		if (maxV2 != 0&& (epsilon / sqrt(maxV2)<=1000))
		{
			return epsilon / sqrt(maxV2);
		}
		return 0.1;
	}

	double getMaxV2()
	{
		double maxV2 = 0;
		for (int i = 0; i < mParticles.size(); i++)
		{
			double v2 = mParticles[i].mVelocity.Length2();
			if (v2 > maxV2)
			{
				maxV2 = v2;
			}
		}
		return maxV2;
	}

	double getPower()
	{
		double power = 0;
		for (int i = 1; i < mParticles.size(); i++)
		{
			power -= G * mParticles[0].mMass*mParticles[i].mMass / sqrt((mParticles[0].mCoordinate + -mParticles[i].mCoordinate).Length2());
		}
		for (int i = 0; i < mParticles.size(); i++)
		{
			//power += mParticles[i].mMass*mParticles[i].mVelocity.Length2();
		}
		return power;
	}

	void Tick(double interval)
	{
#pragma omp parallel for
		for (int i = 0; i < mParticles.size(); i++)
		{
			Vector mAcc(0, 0, 0);
			for (int j = 0; j < i; j++)
			{
				mAcc += G * mParticles[j].mMass / ((mParticles[i].mCoordinate + -mParticles[j].mCoordinate).Length2() + epsilon * epsilon)*Normalize(mParticles[j].mCoordinate + -mParticles[i].mCoordinate);
			}
			for (int j = i + 1; j < mParticles.size(); j++)
			{
				mAcc += G * mParticles[j].mMass / ((mParticles[i].mCoordinate + -mParticles[j].mCoordinate).Length2() + epsilon * epsilon)*Normalize(mParticles[j].mCoordinate + -mParticles[i].mCoordinate);
			}
			mParticles[i].mAcceleration = mAcc;
			mParticles[i].mVelocity += (mAcc * interval);
		}

		for (int i = 0; i < mParticles.size(); i++)
		{
			mParticles[i].mCoordinate += (mParticles[i].mVelocity*interval + (-mParticles[i].mAcceleration*interval*interval));
		}
		t += interval;
	}
};

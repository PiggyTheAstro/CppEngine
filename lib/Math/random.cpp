#include <Math/random.h>
#include <random>

namespace Random
{
	int Randint(int lowerBound, int upperBound)
	{
		std::random_device randomDev;
		std::mt19937 rng(randomDev);
		std::uniform_int_distribution<std::mt19937::result_type> dist(lowerBound, upperBound);
		return dist(rng);
	}

	float Rand(float lowerBound, float upperBound)
	{
		std::random_device randomDev;
		std::mt19937 rng(randomDev);
		std::uniform_int_distribution<std::mt19937::result_type> dist(lowerBound * 100, upperBound * 100);
		return (float)dist(rng) / 100.0f;
	}
}
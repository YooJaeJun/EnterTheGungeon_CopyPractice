#include "framework.h"

Random::Random()
{
	random_device rd;
	randomEngine = make_shared<default_random_engine>(rd());
}

Random::~Random()
{
}

int Random::Int(int min, int max)
{
	uniform_int_distribution<int> result(min, max);
	
	return result(*randomEngine);
}

float Random::Float(float min, float max)
{
	uniform_real_distribution<float> result(min, max);
	
	return result(*randomEngine);
}

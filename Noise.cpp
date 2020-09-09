#include "Noise.h"


void Noise::makeRandomArray(int width, int height)
{
	std::cout << "Filling array. ";
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution(-1.0, 1.0);
	arrayWidth = width;
	arrayHeight = height;
	randomArray = new float*[arrayWidth];
	for (int i = 0; i < arrayWidth; i++) {
		randomArray[i] = new float[arrayHeight];
		for (int j = 0; j < arrayHeight; j++) {
			randomArray[i][j] = distribution(generator);
		}
	}
	std::cout << "Done." << std::endl;
}

float Noise::fade(float t)
{
	return t*t*t*(t*(t*6.0 - 15.0) + 10.0);
}

float Noise::grad(int x, int y)
{
	float r = randomArray[x % arrayWidth][y % arrayHeight];
	return r > 0.5 ? 1.0 : -1.0;
}


Noise::Noise(int width, int height)
{
	makeRandomArray(width, height);
}

Noise::~Noise()
{
	for (int i = 0; i < arrayWidth; i++) {
		delete[] randomArray[i];
	}
	delete[] randomArray;
	std::cout << "Array deleted" << std::endl;
}



float Noise::perlin(float x, float y)
{
	int p0x = (int)x;
	int p0y = (int)y;
	int p1x = p0x + 1;
	int p1y = p0y;
	int p2x = p0x;
	int p2y = p0y + 1;
	int p3x = p0x + 1;
	int p3y = p0y + 1;


	float g0 = grad(p0x, p0y);
	float g1 = grad(p1x, p1y);
	float g2 = grad(p2x, p2y);
	float g3 = grad(p3x, p3y);

	float t0 = x - p0x;
	float fade_t0 = fade(t0);
	float t1 = y - p0y;
	float fade_t1 = fade(t1);
	float p0p1 = (1.0f - fade_t0) * (x - p0x + y - p0y) * g0 + fade_t0 * (x - p1x + y - p1y) * g1;
	float p2p3 = (1.0f - fade_t0) * (x - p2x + y - p2y) * g2 + fade_t0 * (x - p3x + y - p3y) * g3;
	return (1.0f - fade_t1) * p0p1 + fade_t1 * p2p3;
}

void Noise::printArray() {
	for (int i = 0; i < arrayWidth; i++) {
		for (int j = 0; j < arrayHeight; j++) {
			std::cout << i << " " << j << ": " << randomArray[i][j] << std::endl;
		}
	}
}
#pragma once
#include <vector>
#include <iostream>
#include <random>

class Noise
{
private:
    int arrayWidth, arrayHeight;
    float** randomArray;
    void makeRandomArray(int width, int height);
    float fade(float t);
    float grad(int x, int y);
public:
    Noise() : Noise(256) {}
    Noise(int size) : Noise(256, 256) {}
    Noise(int width, int height);
    ~Noise();
    float perlin(float x, float y);
    void printArray();
};


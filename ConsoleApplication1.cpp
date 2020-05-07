// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

std::array<int, 4> pickMorphs(const std::vector<float>& weights);

int main()
{
	std::vector<float> weights = {320.5f,2.0f, 3.2f, 2, 4, 5, 6, 7, 8, 9, 2, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 
		8, 1, 2, 3, 4, 5, 2, 1, 2, 3, 4, 2, 2, 1, 2, 3, 150, 3, 3, 3, 3,3 ,3 ,3 ,3, 3, 3,3 ,3, 3,
		3, 2 ,3 , 5, 6, 7, 8, 2, 3, 4, 5, 6, 7, 8, 2, 3, 4, 5, 6, 7, 8, 379, 999, 1253, 123};
	std::vector<float> weights2 = { 0.3f, 0.5f, 0.9f, 0.001f, 0.3f, 0.3f, 0.9999f, 0.45f, 0.93f };

	for (int i = 0; i < 100; i++)
	{
		std::array<int, 4> result = pickMorphs(weights);
		for (int i = 0; i < result.size(); i++)
			std::cout << result[i] << " ";
	}

    return 0;
}

std::array<int, 4> pickMorphs(const std::vector<float>& weights)
{
	// gdyby nie const to weights moznaby posortowac 

	std::array<int, 4> result;

	if (weights.size() < 4)
	{
		result[0] = -1;
		result[1] = 0;
		result[2] = 0;
		result[3] = 0;
		return result;
	}
	std::vector<float> copyWeights = weights;
	std::array<float, 4> temp = { 0, 0, 0, 0 };

	std::sort(copyWeights.begin(), copyWeights.end());

	for (int i = 0; i < 4; i++)
	{
		temp[i] = copyWeights.back();
		copyWeights.pop_back();
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < weights.size(); j++)
		{
			if (temp[i] == weights[j])
			{
				result[i] = j;
				if (i > 0)
					if (result[i] == result[i - 1])
					{
						result[i] = 0;
						continue;
					}
				break;
			}
		}
	}
	return result;
}


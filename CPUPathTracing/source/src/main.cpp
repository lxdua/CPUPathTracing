#include <iostream>
#include <glm/glm.hpp>

#include "thread_pool.hpp"
#include "film.hpp"

class SimpleTask : public Task
{
	void run() override
	{
		std::cout << "Hello" << std::endl;
	}
};

int main()
{
	Film film{ 1920,1080 };
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			film.SetPixel(j, i, { 0.5,0.7,0.2 });
		}
	}

	film.Save("test.ppm");

	//auto now = std::chrono::high_resolution_clock::now();
	
	//auto time = std::chrono::high_resolution_clock::now() - now;
	//auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
	//std::cout << "Time: " << ms.count() << std::endl;

	return 0;
}
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include "Farm.h"

void Farm::add_task(Task *task)
{
	std::unique_lock<std::mutex> lock(block);
	queue.push(task);
}

void Farm::run()
{
	std::vector<std::thread> threads;

	for (int i = 0; i < 6; ++i)
	{
		threads.push_back(std::thread([this]() {
			while (!queue.empty()) {

				block.lock();
				Task *t = queue.front();
				queue.pop();
				block.unlock();

				t->run();
				delete t;
			}
		}));
	}

	for (std::thread& t : threads)
	{
		t.join();
	}
}
#ifndef FARM_H
#define FAMR_H

#include <queue>
#include <mutex>
#include "Task.h"

class Farm {
public:
	void add_task(Task *Task);

	void run();

private:
	std::queue<Task *> queue;
	std::mutex block;
};


#endif // !FARM_H


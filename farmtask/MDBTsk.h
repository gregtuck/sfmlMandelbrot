#ifndef MDBTASK_H
#define MDBTASK_H

#include <string>
#include "Task.h"

const int WIDTH = 640;
const int HEIGHT = 480;


extern uint32_t image[HEIGHT][WIDTH];

class computemdb : public Task
{
public:
	computemdb(const double left, const double right, const double top, const double bottom, double start, double finish, int y)
	{
		this->left = left;
		this->right = right;
		this->top = top;
		this->bottom = bottom;
		this->start = start;
		this->finish = finish;
		this->y = y;

	}

	void run();

private:

	double left;
	double right;
	double top;
	double bottom;
	int start;
	int finish;
	int y;
};


#endif // !MDBTASK_H

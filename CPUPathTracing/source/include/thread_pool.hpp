#pragma once

#include <thread>
#include <vector>
#include <list>
#include <mutex>

class Task
{
public:
	virtual void run() = 0;
};

class ThreadPool
{
public:
	static void WorkerThread(ThreadPool* master);
	ThreadPool(size_t thread_count = 0);
	~ThreadPool();

	void Wait() const;

	void AddTask(Task* task);
	Task* GetTask();

private:
	bool alive;
	std::vector<std::thread> threads;
	std::list<Task*> tasks;
	std::mutex lock;
};
#pragma once

#include <atomic>
#include <thread>

class SpinLock
{
public:
	void Acqure() { while (flag.test_and_set(std::memory_order_acquire)) std::this_thread::yield(); }
	void Release() { flag.clear(std::memory_order_release); }

private:
	std::atomic_flag flag{};
};

class Guard
{
public:
	Guard(SpinLock& spin_lock) : spin_lock(spin_lock) { spin_lock.Acqure(); }
	~Guard() { spin_lock.Release(); }
private:
	SpinLock& spin_lock;
};
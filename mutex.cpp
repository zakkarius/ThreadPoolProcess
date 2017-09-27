// Author: Zagidulla Taishev

#include "mutex.h"
#include <windows.h>
#include <cassert>

CRITICAL_SECTION g_�riticalSection;

Mutex::Mutex()
{
   ::InitializeCriticalSection(&g_�riticalSection);
}

Mutex::~Mutex()
{
   ::DeleteCriticalSection(&g_�riticalSection);
}

void Mutex::lock()
{
   ::EnterCriticalSection(&g_�riticalSection);
}

void Mutex::unlock()
{
   ::LeaveCriticalSection(&g_�riticalSection);
}

Locker::Locker(Mutex& mutex)
: m_mutex(mutex)
{
   m_mutex.lock();
}

Locker::~Locker()
{
   m_mutex.unlock();
}

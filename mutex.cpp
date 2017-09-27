// Author: Zagidulla Taishev

#include "mutex.h"
#include <windows.h>
#include <cassert>

CRITICAL_SECTION g_ñriticalSection;

Mutex::Mutex()
{
   ::InitializeCriticalSection(&g_ñriticalSection);
}

Mutex::~Mutex()
{
   ::DeleteCriticalSection(&g_ñriticalSection);
}

void Mutex::lock()
{
   ::EnterCriticalSection(&g_ñriticalSection);
}

void Mutex::unlock()
{
   ::LeaveCriticalSection(&g_ñriticalSection);
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

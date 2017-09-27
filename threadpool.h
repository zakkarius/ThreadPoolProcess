// Author: Zagidulla Taishev

#pragma once

#include "workerthread.h"
#include "mutex.h"
#include "request.h"
#include <list>
#include <vector>
#include <windows.h>

class ThreadPool
{
public:
   ThreadPool(size_t numberOfThreads);

   void acquireWorker(WorkerThread* worker);
   void stop();

private:
   static unsigned int WINAPI executeThread(void* parameter);

   bool fetchWorker(WorkerThread** worker);

private:
   const size_t m_numberOfThreads;
   bool m_stopped;

   Mutex m_workMutex;

   std::list<WorkerThread*> m_workerQueue;

   std::vector<HANDLE> m_threads;
};

// Author: Zagidulla Taishev

#include "threadpool.h"
#include <process.h>

ThreadPool::ThreadPool(size_t numberOfThreads)
: m_numberOfThreads((numberOfThreads >= 1) ? numberOfThreads : 1)
, m_stopped(false)
{
   for (size_t i = 0; i < m_numberOfThreads; ++i)
   {

      HANDLE handle = (HANDLE)_beginthreadex(NULL, 0, &ThreadPool::executeThread, this, 0, NULL);

      m_threads.push_back(handle);

   }

}

void ThreadPool::acquireWorker(WorkerThread* worker)
{
   Locker lock(m_workMutex);
   m_workerQueue.push_back(worker);
}

bool ThreadPool::fetchWorker(WorkerThread** worker)
{
   Locker lock(m_workMutex);

   if (m_workerQueue.empty())
   {
      *worker = NULL;
   }
   else
   {
      *worker = m_workerQueue.front();
      m_workerQueue.pop_front();
   }

   return !m_stopped;
}

void ThreadPool::stop()
{
   m_stopped = true;
   // optimization - have no require to delete unprocessed requests
   //   for (std::list<WorkerThread*>::iterator it = m_workerQueue.begin(); it != m_workerQueue.end(); ++it)
   //   {
   //     delete *it;
   //   }
   m_workerQueue.clear();

   for (size_t i = 0; i < m_numberOfThreads; ++i)

   {
      ::WaitForSingleObject(m_threads.at(i), INFINITE);
   }
}

unsigned int WINAPI ThreadPool::executeThread(void* parameter)
{
   WorkerThread* worker = NULL;

   ThreadPool* threadPool = static_cast<ThreadPool*>(parameter);
   if (threadPool == NULL)
   {
      return 1;
   }

   while (threadPool->fetchWorker(&worker))

   {

      if(worker)

      {

         worker->execute();

         delete worker;

         worker = NULL;

      }

   }

   return 0;
}

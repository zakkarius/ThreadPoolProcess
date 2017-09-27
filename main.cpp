// Author: Zagidulla Taishev

#include <iostream>
#include "threadpool.h"
#include "request.h"
using namespace std;

int main()
{
   ThreadPool pool(NumberOfThreads);

   while (Request* request = GetRequest())
   {
      WorkerThread* workerThread = new WorkerThread(request);
      pool.acquireWorker(workerThread);
   }

   pool.stop();

   return 0;
}

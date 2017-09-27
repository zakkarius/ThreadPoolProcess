// Author: Zagidulla Taishev

#include "workerthread.h"
#include "request.h"

WorkerThread::WorkerThread(Request* request)
: m_request(request)
{
}

void WorkerThread::execute()
{
   ProcessRequest(m_request);
}

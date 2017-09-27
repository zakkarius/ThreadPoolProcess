// Author: Zagidulla Taishev

#pragma once

class Request;

class WorkerThread
{
public:
   WorkerThread(Request* request);
   void execute();

private:
   Request* m_request;
};

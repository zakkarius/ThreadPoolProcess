// Author: Zagidulla Taishev

#pragma once

class Mutex
{
public:
   Mutex();
   ~Mutex();

   void lock();
   void unlock();

private:
   Mutex(const Mutex&);
   Mutex& operator=(const Mutex&);
};

class Locker
{
public:
   Locker(Mutex& mutex);
   ~Locker();

private:
   Locker(const Locker&);
   Locker& operator=(const Locker&);

   Mutex& m_mutex;
};

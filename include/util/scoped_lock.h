#ifndef SCOPED_LOCK_H
#define SCOPED_LOCK_H
#include"util/base_def.h"
namespace luckyDaily {
#if defined(_DEBUG) 
#define US_UNEXPECTED() 
#else 
#define US_UNEXPECTED() 
#endif
	template <class M>
	class LF_DLL_API scoped_lock
		/// A class that simplifies thread synchronization
		/// with a mutex.
		/// The constructor accepts a Mutex (and optionally
		/// a timeout value in milliseconds) and locks it.
		/// The destructor unlocks the mutex.
	{
	public:
		explicit scoped_lock(M& mutex) : _mutex(mutex)
		{
			_mutex.lock();
		}

		scoped_lock(M& mutex, long milliseconds) : _mutex(mutex)
		{
			_mutex.lock(milliseconds);
		}

		~scoped_lock()
		{
			try
			{
				_mutex.unlock();
			}
			catch (...)
			{
				US_UNEXPECTED();
			}
		}

	private:
		M& _mutex;

		scoped_lock();
		scoped_lock(const scoped_lock&);
		scoped_lock& operator = (const scoped_lock&);
	};


	template <class M>
	class LF_DLL_API scoped_lock_with_unlock
		/// A class that simplifies thread synchronization
		/// with a mutex.
		/// The constructor accepts a Mutex (and optionally
		/// a timeout value in milliseconds) and locks it.
		/// The destructor unlocks the mutex.
		/// The unlock() member function allows for manual
		/// unlocking of the mutex.
	{
	public:
		explicit scoped_lock_with_unlock(M& mutex) : _pMutex(&mutex)
		{
			_pMutex->lock();
		}

		scoped_lock_with_unlock(M& mutex, long milliseconds) : _pMutex(&mutex)
		{
			_pMutex->lock(milliseconds);
		}

		~scoped_lock_with_unlock()
		{
			try
			{
				unlock();
			}
			catch (...)
			{
				US_UNEXPECTED();
			}
		}

		void unlock()
		{
			if (_pMutex)
			{
				_pMutex->unlock();
				_pMutex = 0;
			}
		}

	private:
		M* _pMutex;

		scoped_lock_with_unlock();
		scoped_lock_with_unlock(const scoped_lock_with_unlock&);
		scoped_lock_with_unlock& operator = (const scoped_lock_with_unlock&);
	};



}
#endif //

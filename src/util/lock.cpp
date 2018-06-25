#include"util/lock.h"
namespace LF{
	fast_lock::fast_lock()
	{
#ifdef _WIN32
		InitializeCriticalSection(&m_critical_section);
#else
		pthread_mutex_init(&m_mutex, NULL);
#endif
	}

	fast_lock::~fast_lock()
	{
#ifdef _WIN32
		DeleteCriticalSection(&m_critical_section);
#else
		pthread_mutex_destroy(&m_mutex);
#endif
	}

	void lock_instance::lock()
	{
#ifdef _WIN32
		EnterCriticalSection(&m_lock.m_critical_section);
#else
		pthread_mutex_lock(&m_lock.m_mutex);
#endif
	}

	void lock_instance::unlock()
	{
#ifdef _WIN32
		LeaveCriticalSection(&m_lock.m_critical_section);
#else
		pthread_mutex_unlock(&m_lock.m_mutex);
#endif
	}

#ifndef _WIN32
	bool lock_instance::try_lock()
	{
		return pthread_mutex_trylock(&m_lock.m_mutex) == 0;
	}
#endif

	auto_lock::auto_lock(lock_instance* pLock)
	{
		m_pLock = pLock;
		if (NULL != m_pLock)
			m_pLock->lock();
	}

	auto_lock::~auto_lock()
	{
		if (NULL != m_pLock)
			m_pLock->unlock();
	}
}
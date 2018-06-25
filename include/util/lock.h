#ifndef LOCK_UTIL_H
#define LOCK_UTIL_H
#include"util/base_def.h"
#include"util/scoped_lock.h"
#include"util/os_type.h"
namespace LF{
	class LF_DLL_API fast_lock
	{
	public:
		fast_lock();
		~fast_lock();

	public:
#ifdef _WIN32
		CRITICAL_SECTION m_critical_section;
#else
		pthread_mutex_t m_mutex;
#endif
	};


	class LF_DLL_API lock_instance
	{
	public:
		typedef scoped_lock<lock_instance> scoped_lock;
		typedef scoped_lock_with_unlock<lock_instance> scoped_lock_with_unlock;
		void lock();
		void unlock();
#ifndef _WIN32
		virtual bool try_lock();
#endif
	private:
		fast_lock	m_lock;
	};

	class LF_DLL_API auto_lock
	{
	public:
		auto_lock(lock_instance* pLock);
		virtual ~auto_lock();
	private:
		lock_instance* m_pLock;
	};

}
#endif //
#ifndef SINGLETON_H
#define SINGLETON_H
#include"base_def.h"
#include <assert.h>
namespace LF{

	template <typename T>
	class singleton
	{
	protected:
		static T* singleton_;

	public:
		singleton(void)
		{
			assert(!singleton_);
#if defined(_MSC_VER) && _MSC_VER < 1200	 
			int offset = (int)(T*)1 - (int)(singleton <T>*)(T*)1;
			singleton_ = (T*)((int)this + offset);
#else
			singleton_ = static_cast< T* >(this);
#endif
		}


		~singleton(void){ assert(singleton_);  singleton_ = 0; }

		static T& singleton_obj(void) { assert(singleton_);  return (*singleton_); }
		static T* singleton_ptr(void){ return singleton_; }
	};

#define OBJ_SINGLETON_INIT(TYPE)					\
 template <>	 TYPE * singleton< TYPE >::singleton_ = 0;


}

#endif //!SINGLETON_H
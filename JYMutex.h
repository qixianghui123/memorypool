#ifndef _JYMUTEX_H
#define _JYMUTEX_H

#include <pthread.h>
#include <malloc.h>
#include <time.h>

class JYMutex
{
public:
	JYMutex(void);
	virtual ~JYMutex(void);

	bool Lock();
	bool Unlock();
	pthread_mutex_t* getHandle(){ return m_pLock; };

protected:
	pthread_mutex_t *m_pLock;
};

#endif

#ifndef JYMEMORY_POOL_H_
#define JYMEMORY_POOL_H_

#include "JYChunk.h"
#include "JYMutex.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;


class JYMemoryPool
{
				public:
								JYMemoryPool(int pool_size);
								~JYMemoryPool();
								JYChunk* Alloc();
								int Free(JYChunk* chunk);
				public:
								static JYMemoryPool* GetInstance();
				private:
								list<JYChunk*>			m_memory_list;
								int									m_pool_size;
								JYMutex							m_mutex;
				private:
								static JYMemoryPool *g_pool;
};
#endif

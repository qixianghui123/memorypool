#include "JYMemoryPool.h"

JYMemoryPool* JYMemoryPool::g_pool = NULL;

JYMemoryPool::JYMemoryPool(int pool_size)
{
				m_mutex.Lock();
				m_pool_size = pool_size;
				for(int i=0; i<m_pool_size; i++)
				{
								JYChunk *chunk = new JYChunk(1024*10);
								m_memory_list.push_back(chunk);
				}
				m_mutex.Unlock();
}

JYMemoryPool::~JYMemoryPool()
{
				list<JYChunk*>(m_memory_list).swap(m_memory_list);
}

JYChunk* JYMemoryPool::Alloc()
{
				m_mutex.Lock();
				if(m_memory_list.size() <= 0)
				{

								m_mutex.Unlock();
								return NULL;
				}
				JYChunk *chunk = m_memory_list.front();
				if(chunk->Data()!=NULL && chunk->GetBlockSize()>=1024 && chunk->GetStatus() == idle)
				{
								m_mutex.Unlock();
								m_memory_list.pop_front();
								return chunk;
				}
				else
				{
								m_mutex.Unlock();
								return NULL;
				}
}

int JYMemoryPool::Free(JYChunk* chunk)
{
				m_mutex.Lock();
				if(m_memory_list.size()>= m_pool_size)
				{
								m_mutex.Unlock();
								return -1;
				}
				else
				{
								m_memory_list.push_back(chunk);
								m_mutex.Unlock();
								return 0;
				}
}

JYMemoryPool* JYMemoryPool::GetInstance()
{
				if(g_pool == NULL)
				{
								g_pool = new JYMemoryPool(100);
				}
				return g_pool;
}

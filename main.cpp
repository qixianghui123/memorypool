#include "JYMemoryPool.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void *test(void *s)
{
				JYMemoryPool *pool = JYMemoryPool::GetInstance();
				for(int i=0; i<20000; i++)
				{
 								JYChunk *chunk = pool->Alloc();
								if(chunk)
								{
												char *buf = (char *)chunk->Data();
								
												strcpy(buf, "222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222");
												cout << buf << "\n"<< i <<endl;
												pool->Free(chunk);
								}
				}
}
int main()
{
				int i;
				for(i=0; i<100; i++)
				{
								pthread_t tid;
								pthread_create(&tid, NULL, test, NULL);
								cout << "thread number is " << i << endl;
				}
				sleep(1000000);
}

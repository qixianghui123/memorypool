#include "JYChunk.h"
#include <stdio.h>
#include <stdlib.h>

JYChunk::JYChunk(int block_size)
{
				m_block_size = block_size;
				m_data = (void *)malloc(m_block_size);
				m_status = idle;
}

JYChunk::~JYChunk()
{
				if(m_data)
				{
								free(m_data);
								m_block_size = 0;
				}
}

void* JYChunk::Data()
{
				if(m_data)
				{
								return m_data;
				}
				return NULL;
}

int JYChunk::GetStatus()
{
				return m_status;
}

int JYChunk::GetBlockSize()
{
				return m_block_size;
}

int JYChunk::SetBlockSize(int block_size)
{
				m_block_size = block_size;
}

int JYChunk::SetStatus(int status)
{
				m_status = status;
}


#ifndef JY_CHUNK_H_
#define JY_CHUNK_H_

enum status
{
				busy = 1,
				idle = 2
};

class JYChunk
{
				public:
								JYChunk(int block_size = 1024);
								~JYChunk();
								void*		Data();
								int			GetStatus();
								int			GetBlockSize();
								int			SetBlockSize(int block_size);
								int			SetStatus(int status);
				private:
								void*		m_data;
								int			m_status;
								int			m_block_size;
};
#endif

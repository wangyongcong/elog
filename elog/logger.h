#ifndef WYC_HEADER_LOGGER
#define WYC_HEADER_LOGGER

#include <cstdint>
#include <string>

namespace wyc
{

enum LOG_LEVEL
{
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL,

	LOG_LEVEL_COUNT,
};

#define DEFAULT_ROTATE_SIZE (4*1024*1024)

class xlogger
{
public:
	xlogger();
	~xlogger();
	bool create(const char* log_name, const char* save_path=0, size_t rotate_size = 0, LOG_LEVEL lvl = LOG_DEBUG);
	void write(const char* record, size_t size);
	void flush();
	void trace();
	void debug();
	void info();
	void warn();
	void error();
	void fatal();
	LOG_LEVEL get_level() const;
	size_t get_rotation_size() const;
private:
	FILE *m_hfile;
	std::string m_path;
	std::string m_fname;
	size_t m_cur_size;
	size_t m_rotate_size;
	unsigned m_rotate_cnt;
	LOG_LEVEL m_level;
};


}; // end of namespace wyc

#endif // WYC_HEADER_LOGGER

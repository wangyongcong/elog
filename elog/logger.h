#ifndef WYC_HEADER_LOGGER
#define WYC_HEADER_LOGGER

#include <cstdint>

namespace wyc
{

enum LOG_LEVEL
{
	LOG_TRACE,
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL,

	LOG_LEVEL_COUNT,
};

class xlogger
{
public:
	xlogger();
	~xlogger();
	bool create(const char* file_path, size_t rotation_size, LOG_LEVEL lvl);
	void write(LOG_LEVEL lvl, const char* record, size_t size);
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
};


}; // end of namespace wyc

#endif // WYC_HEADER_LOGGER

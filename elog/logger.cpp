#include <algorithm>
#include <ctime>
#include "logger.h"

namespace wyc
{

const char* s_log_lvl_tag[wyc::LOG_LEVEL_COUNT] = {
	"DEBUG",		
	"INFO",		
	"WARN",	
	"ERROR",
	"FATAL",
};

xlogger::xlogger()
{
	m_hfile = NULL;
	m_cur_size = 0;
	m_rotate_size = DEFAULT_ROTATE_SIZE;
	m_rotate_cnt = 0;
	m_level = LOG_DEBUG;
}

xlogger::~xlogger()
{
	if (m_hfile) {
		fclose(m_hfile);
		m_hfile = 0;
	}
}

bool xlogger::create(const char* log_name, const char* save_path, size_t rotate_size, LOG_LEVEL lvl)
{
	if (!save_path || 0 == save_path[0])
		m_path = ".\\logs\\";
	else {
		m_path = save_path;
		std::replace(m_path.begin(), m_path.end(), '/', '\\');
		if (m_path[m_path.size() - 1] != '\\')
			m_path += "\\";
	}
	m_fname = log_name;
	std::string file_path;
	file_path.reserve(m_path.size() + m_fname.size() + 5);
	file_path += m_path;
	file_path += m_fname;
	file_path += ".log";
	if (m_hfile) {
		fclose(m_hfile);
		m_hfile = 0;
	}
	m_hfile = _fsopen(file_path.c_str(), "w", _SH_DENYWR);
	if (!m_hfile) {
		// build the directory tree
		std::string cmd = "mkdir ";
		cmd += m_path;
		if (std::system(cmd.c_str()))
			return false;
		// try again!
		m_hfile = _fsopen(file_path.c_str(), "w", _SH_DENYWR);
		if (!m_hfile)
			return false;
	}
	m_cur_size = 0;
	if (!rotate_size)
		m_rotate_size = DEFAULT_ROTATE_SIZE;
	else
		m_rotate_size = rotate_size;
	m_rotate_cnt = 0;
	m_level = lvl;
	return true;
}

void xlogger::write(const char* record, size_t size)
{
	if (!m_hfile) 
		return;
	if (m_cur_size + size < m_rotate_size)
	{
		m_cur_size += size;
	}
	else
	{
		// rotate
	}
}

void xlogger::flush()
{
}

}; // end of namesapce wyc

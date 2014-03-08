// elog.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <thread>
#include <ctime>
#include "logger.h"

int _tmain(int argc, _TCHAR* argv[])
{
	wyc::xlogger log;
	log.create("test",NULL,1024*1024,wyc::LOG_WARN);
	const char *dummy_info = "This is a dummy message for logger debugging.";
	std::chrono::milliseconds ms(33);
	unsigned cnt = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			log.debug("[%d] %s", ++cnt, dummy_info);
			log.info ("[%d] %s", ++cnt, dummy_info);
			log.warn ("[%d] %s", ++cnt, dummy_info);
			log.error("[%d] %s", ++cnt, dummy_info);
			log.fatal("[%d] %s", ++cnt, dummy_info);
		}
		log.flush();
		printf("%d records were written...\n", cnt);
		std::this_thread::sleep_for(ms);
	}
	return 0;
}


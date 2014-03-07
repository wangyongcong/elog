// elog.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "logger.h"

int _tmain(int argc, _TCHAR* argv[])
{
	wyc::xlogger log;
	log.create("test");

	return 0;
}


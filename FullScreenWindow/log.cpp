#include "stdafx.h"
#include "log.h"

void initLog()
{
	logging::add_file_log
		(
			keywords::file_name = "debug.log",
			// This makes the sink to write log records that look like this:
			// 1: <normal> A normal severity message
			// 2: <error> An error severity message
			keywords::format =
			(
				expr::stream
				<< expr::attr< unsigned int >("LineID") << " |"
				<< " [ " << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S") << "]"
				<< ": <" << logging::trivial::severity << "> "
				<< expr::smessage
			),
			keywords::auto_flush = true
		);

	logging::add_console_log
		(
			std::clog,
			keywords::format =
			(
				expr::stream
				<< expr::attr< unsigned int >("LineID") << " |"
				<< " [ " << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S") << "]"
				<< ": <" << logging::trivial::severity << "> "
				<< expr::smessage
			),
			keywords::auto_flush = true
		);

	logging::add_common_attributes();
}


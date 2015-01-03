#pragma once

//Link: -lpthread -lboost_log -lboost_system -lboost_thread

#pragma warning(disable:4996)
#pragma warning(disable:4714)
#pragma warning(disable:4512)
#pragma warning(disable:4100)

#define BOOST_ALL_DYN_LINK
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/log/support/date_time.hpp>


namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace trivial = boost::log::trivial;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;

void initLog();

using namespace logging::trivial;

#define LOG(severity) \
	src::severity_logger< severity_level > lg; \
    BOOST_LOG_SEV(lg, severity) << "(" << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << ") "
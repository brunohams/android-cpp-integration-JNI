
#pragma once

#include <android/log.h>

#ifndef NDEBUG
#define LOGD (args . ..) \
android_log_print(android_LogPriority::ANDROID_LOG_DEBUG, "Calculator", args)
#else
#define LOGD(args...)
#endif
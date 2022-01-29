#pragma once
#include <mutex>

#ifndef NS_EA_BEGIN
#    define NS_EA_BEGIN namespace EA {
#    define NS_EA_END }
#endif

#ifdef OPENGA_EXTERN_LOCAL_VARS
extern std::mutex mtx_rand;
#else
std::mutex mtx_rand;
#endif

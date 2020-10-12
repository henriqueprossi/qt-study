#include <QtGlobal>
#include "sysinfo.h"

#ifdef Q_OS_WIN

#elif defined(Q_OS_MAC)

#elif defined(Q_OS_LINUX)
#include "sysinfolinuximpl.h"
#endif

SysInfo& SysInfo::instance()
{
#ifdef Q_OS_WIN

#elif defined(Q_OS_MAC)

#elif defined(Q_OS_LINUX)
    static SysInfoLinuxImpl singleton;
#endif

    return singleton;
}

SysInfo::SysInfo()
{

}

SysInfo::~SysInfo()
{

}

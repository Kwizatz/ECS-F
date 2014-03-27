#ifndef ECSFCOMPONENT_H
#define ECSFCOMPONENT_H
#include "ECSFPlatform.h"
#include <stdint.h>
namespace ECSF
{
    class DLL Component
    {
    public:
        Component();
        virtual ~Component();
        virtual uint32_t GetTypeId() const;
        virtual const char* GetTypeIdString() const = 0;
    };
}
#endif

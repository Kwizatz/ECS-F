#include "ECSFComponent.h"
#include "crc.h"
#include <stddef.h>
#include <string.h>
namespace ECSF
{
    Component::Component()
    {
    }

    Component::~Component()
    {
    }

    uint32_t Component::GetTypeId() const
    {
        const char* idstring = GetTypeIdString();
        return CRC32 ( reinterpret_cast<const uint8_t*> ( idstring ), static_cast<uint32_t> ( strlen ( idstring ) ) );
    }
}

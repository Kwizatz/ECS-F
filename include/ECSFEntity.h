#ifndef ECSFENTITY_H
#define ECSFENTITY_H
#include "ECSFPlatform.h"
#include "ECSFSystem.h"
#include "ECSFComponent.h"
#include <stdint.h>
#include <map>
#ifdef _MSC_VER
#pragma warning( push )
/*
Get rid of the anoying STL "x needs to have dll-interface to be used by clients of class y" warning
We should be fine as long as we do not return any templated classes or allow
direct access to the one we define as members of our class.
*/
#pragma warning( disable : 4251 )
#endif

namespace ECSF
{
    class DLL Entity
    {
    public:
        const uint32_t GetId() const;
        void AttachComponent ( Component* component );
        void DetachComponent ( Component* component );
        Component* GetComponent ( uint32_t component_type_id );
        Component* GetComponent ( const char* component_type_id_string );
    private:
        /* Only the Engine class should be able to create entities */
        friend class Engine;
        Entity ( uint32_t id );
        ~Entity();
        uint32_t id;
        std::map<uint32_t, Component*> components;
    };
}
#ifdef _MSC_VER
#pragma warning( pop )
#endif
#endif

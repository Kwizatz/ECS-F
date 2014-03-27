#include "crc.h"
#include "ECSFEntity.h"
#include <stddef.h>
#include <assert.h>
namespace ECSF
{
    Entity::Entity()
    {
    }

    Entity::~Entity()
    {
    }

    void Entity::AttachComponent ( Component* component )
    {
        assert ( component != NULL );
        /* Avoid calling component->GetTypeId() more than once */
        const uint32_t component_type_id = component->GetTypeId();
        /* If the entity already has a component of this type, do not replace it */
        if ( components.find ( component_type_id ) == components.end() )
        {
            components[component_type_id] = component;
        }
    }

    void Entity::DetachComponent ( Component* component )
    {
        assert ( component != NULL );
        std::map<uint32_t, Component*>::iterator i = components.find ( component->GetTypeId() );
        if ( i != components.end() )
        {
            components.erase ( i );
        }
    }

    Component* Entity::GetComponent ( uint32_t component_type_id )
    {
        /* If the entity already has a component of this type, do not replace it */
        std::map<uint32_t, Component*>::iterator i = components.find ( component_type_id );
        if ( i == components.end() )
        {
            return NULL;
        }
        return i->second;
    }

    Component* Entity::GetComponent ( const char* type_id_string )
    {
        return GetComponent ( CRC32 ( reinterpret_cast<const uint8_t*> ( type_id_string ), static_cast<uint32_t> ( strlen ( type_id_string ) ) ) );
    }
}

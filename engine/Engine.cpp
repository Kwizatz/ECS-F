#include "ECSFEngine.h"
#include <assert.h>
#include <algorithm>

namespace ECSF
{
    Engine::Engine() : next_entity_id ( 0 )
    {
    }

    Engine::~Engine()
    {
    }

    void Engine::Subscribe ( uint32_t message, System* system )
    {
        mailbox[message].push_back ( system );
    }

    void Engine::Unsubscribe ( uint32_t message, System* system )
    {
        std::vector<System*>::iterator  i = std::find ( mailbox[message].begin(), mailbox[message].end(), system );
        if ( i != mailbox[message].end() )
        {
            mailbox[message].erase ( i );
        }
    }

    void Engine::SendMessage ( uint32_t message )
    {
        for ( std::vector<System*>::iterator i = mailbox[message].begin(); i != mailbox[message].end(); ++i )
        {
            /* Call System Message Handler */
            ( *i )->ProcessMessage ( message );
        }
    }

    void Engine::AttachSystem ( System* system )
    {
        assert ( system != NULL );
        /* Only append the system if it is not already in the vector */
        if ( std::find ( systems.begin(), systems.end(), system ) == systems.end() )
        {
            /*  The systems vector should remain ordered by the order of insertion,
                as this is also the order in which each system will be updated */
            systems.push_back ( system );
            system->engine = this;
            system->OnAttach();
        }
    }

    void Engine::DetachSystem ( System* system )
    {
        assert ( system != NULL );
        std::vector<System*>::iterator i = std::find ( systems.begin(), systems.end(), system );
        if ( i != systems.end() )
        {
            system->OnDetach();
            system->engine = NULL;
            systems.erase ( i );
        }
    }

    void Engine::Update()
    {
        for ( std::vector<System*>::iterator i = systems.begin(); i != systems.end(); ++i )
        {
            if ( ( *i )->PreUpdate != NULL )
            {
                ( *i )->PreUpdate();
            }
            /* Call System Update Function */
            ( *i )->Update();
            if ( ( *i )->PostUpdate != NULL )
            {
                ( *i )->PostUpdate();
            }
        }
    }

    Entity* Engine::NewEntity()
    {
        Entity* entity = new Entity ( next_entity_id++ );
        if ( entity != NULL )
        {
            entities.push_back ( entity );
        }
        return entity;
    }

    void Engine::DeleteEntity ( Entity* entity )
    {
        if ( entity != NULL )
        {
            std::vector<Entity*>::iterator i = std::find ( entities.begin(), entities.end(), entity );
            if ( i != entities.end() )
            {
                entities.erase ( i );
            }
            delete entity;
        }
    }
}

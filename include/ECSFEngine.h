#ifndef ECSFENGINE_H
#define ECSFENGINE_H
#include "ECSFPlatform.h"
#include "ECSFSystem.h"
#include <stdint.h>
#include <map>
#include <vector>
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
    class DLL Engine
    {
    public:
        Engine();
        ~Engine();
        void SendMessage ( uint32_t message );
        void AttachSystem ( System* system );
        void DetachSystem ( System* system );
        void Update();
    private:
        /*  We'll only allow systems themselves to subscribe or unsubscribe
            to any events.
        */
        friend class System;
        void Subscribe ( uint32_t message, System* system );
        void Unsubscribe ( uint32_t message, System* system );
        /// Our Mailbox for the observer pattern
        std::map<uint32_t, std::vector<System*> > mailbox;
        /// Our collection of Systems
        std::vector<System*> systems;
    };
}
#ifdef _MSC_VER
#pragma warning( pop )
#endif
#endif//ECSFENGINE_H

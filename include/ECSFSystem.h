#ifndef ECSFSYSTEM_H
#define ECSFSYSTEM_H
#include "ECSFPlatform.h"
#include <stdint.h>
namespace ECSF
{
    class DLL Engine;
    class DLL System
    {
    public:
        System();
        virtual ~System();
        virtual void OnAttach() = 0;
        virtual void OnDetach() = 0;
        virtual void ProcessMessage ( uint32_t message ) = 0;
        Engine* GetEngine();
    protected:
        void ( *PreUpdate ) ();
        void ( *PostUpdate ) ();
    private:
        friend class Engine;
        virtual void Update() = 0;
        Engine* engine;
    };
}
#endif//ECSFSystem_H

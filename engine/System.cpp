#include "ECSFSystem.h"
#include "ECSFEngine.h"
#include <stddef.h>
namespace ECSF
{
    System::System() :
        PreUpdate ( NULL ),
        PostUpdate ( NULL ),
        engine ( NULL )
    {
    }

    System::~System()
    {
    }

    Engine* System::GetEngine()
    {
        return engine;
    }
}

#include "ECSFSystem.h"
#include "ECSFEngine.h"
#include <stddef.h>
namespace ECSF
{
    System::System() : engine ( NULL )
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

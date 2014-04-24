ECS-F
=====

Entity Component System Framework (ECS-F)

This is for now a proof of concept for a general game engine ECS framework.

Demo
====

The Framework is meant to be a standalone library, however the usage demo uses the Irrlicht engine as a render system.
The Demo is OPTIONAL and disabled by default, it can be enabled on cmake-gui by checking the BUILD_DEMO option checkbox.
A BUILD_IRRLICH option is provided if Irrlicht itself is desired to be build from source as part of the ECS-F build, this option however is discouraged as it requires the DirectX SDK, and some extra fiddling with the project settings.
On either case, the CMake script handles downloading the Irrlicht SDK and setting library and include paths for you.

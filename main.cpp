#include <iostream>
#include "Engine.h"
int main()
{
    UEngine* Engine = new UEngine();

    Engine->Initialize();

    Engine->Run();

    Engine->Terminate();

    delete Engine;
    Engine = nullptr;
}

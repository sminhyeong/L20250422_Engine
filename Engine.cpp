#include <iostream>
#include <Windows.h>
#include "Engine.h"
#include "Input.h"
#include "World.h"

UEngine::UEngine()// : World(nullptr)
{
	IsRunning = false;
	InputDevice = nullptr;
	World = nullptr;
}

UEngine::~UEngine()
{

}

void UEngine::Initialize()
{
	InputDevice = new UInput();
	World = new UWorld();
	IsRunning = true;
}

void UEngine::Run()
{
	while (IsRunning)
	{
		Input();
		Tick();
		Render();

		if (toupper(UInput::KeyCode) == 'P')
		{
			IsRunning = false;
		}
		Sleep(1000 / 60);
	}
}

void UEngine::Terminate()
{
	if (World)
	{
		delete World;
		World = nullptr;
	}
	if (InputDevice)
	{
		delete InputDevice;
		InputDevice = nullptr;
	}
}

void UEngine::Input()
{
	InputDevice->Tick();
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}

#include <iostream>
#include <Windows.h>
#include "Engine.h"
#include "Input.h"
#include "World.h"
#include "Renderer.h"


UEngine* UEngine::instance = nullptr;

UEngine::UEngine()// : World(nullptr)
{
	IsRunning = false;
	InputDevice = nullptr;
	World = nullptr;
	instance = nullptr;
	Window = nullptr;
}

UEngine::~UEngine()
{
	delete instance;
	instance = nullptr;


}

void UEngine::Initialize(std::string filepath)
{

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	Window = SDL_CreateWindow("Engine", 800, 600, SDL_WINDOW_OPENGL);
	InputDevice = new UInput();
	World = new UWorld();
	World->Load(filepath);
	IsRunning = true;

	URenderer::GetInstance();
}

void UEngine::Run()
{
	while (IsRunning)
	{
		SDL_PollEvent(&Event);
		switch (Event.type)
		{
		case SDL_EVENT_QUIT:
			IsRunning = false;
		}
		Input();
		Tick();
		Render();
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

	if (Window)
	{
		SDL_DestroyWindow(Window);
		Window = nullptr;
		SDL_Quit();
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

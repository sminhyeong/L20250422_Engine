#pragma once
#include <string>
#include "SDL3/SDL.h"
#pragma comment(lib, "SDL3")


class UWorld;
class UInput;

class UEngine
{
private:
	UEngine();
public :
	static UEngine* GetInstance()
	{
		if (!instance)
			instance = new UEngine();
		return instance;
	}
	virtual ~UEngine();

	void Initialize(std::string filepath = "level01.map");
	
	void Run();
	void Terminate();

	SDL_Window* Window;
	SDL_Event Event;
private :
	static UEngine* instance;
	bool IsRunning;

	void Input();
	void Tick();
	void Render();

	UInput* InputDevice;
	UWorld* World;
};

#define GEninge UEngine::GetInstance()

#pragma once

class UWorld;
class UInput;

class UEngine
{
public : 
	UEngine();
	virtual ~UEngine();

	void Initialize();
	
	void Run();
	void Terminate();

private :
	bool IsRunning;

	void Input();
	void Tick();
	void Render();

	UInput* InputDevice;
	UWorld* World;
};


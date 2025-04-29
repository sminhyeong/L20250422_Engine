#pragma once
#include <Windows.h>
#include "Vector2D.h"
#include "SDL3/SDL.h"

#pragma comment(lib,"SDL3")
class AActor;

class URenderer
{
protected:
	URenderer();
	static URenderer* instance;
	
	HANDLE ScreenHandles[2];
	int CurrentScreenIndex;
public:
	virtual ~URenderer();
	static URenderer* GetInstance();

	void Clear();
	void Render(const AActor* RenderingObject);
	void Flip();
	void Prescent();

	SDL_Renderer *Renderer;
};


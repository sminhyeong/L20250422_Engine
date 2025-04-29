#include "Renderer.h"
#include "Engine.h"
#include "Actor.h"

URenderer* URenderer::instance = nullptr;

URenderer::URenderer()
{
	ScreenHandles[0] = CreateConsoleScreenBuffer(GENERIC_READ | FILE_GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenHandles[1] = CreateConsoleScreenBuffer(GENERIC_READ | FILE_GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	CurrentScreenIndex = 0;
	Renderer = SDL_CreateRenderer(GEninge->Window,nullptr);
}

URenderer::~URenderer()
{
	for (auto handle : ScreenHandles)
	{
		CloseHandle(handle);
	}
	SDL_DestroyRenderer(Renderer);
}

URenderer* URenderer::GetInstance()
{
	if (!instance)
	{
		instance = new URenderer();
	}
	return instance;
}

void URenderer::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenHandles[CurrentScreenIndex], ' '
		, 100 * 40, COORD{0,0}, &DW);

	SDL_SetRenderDrawColor(Renderer,0,0,0,1);
	SDL_RenderClear(Renderer);

}

void URenderer::Render(const AActor* RenderingObject)
{
	char Shapes[2] = { RenderingObject->Shape,'\0'};
	SetConsoleCursorPosition(ScreenHandles[CurrentScreenIndex], COORD{ (SHORT)RenderingObject->Location.X,(SHORT)RenderingObject->Location.Y });
	WriteConsole(ScreenHandles[CurrentScreenIndex], Shapes, 1, NULL, NULL);

	//SDL_SetRenderDrawColor(Renderer, RenderingObject->Color.r, RenderingObject->Color.g, RenderingObject->Color.b, 1);
	SDL_FRect Location{ RenderingObject->Location.X*30, RenderingObject->Location.Y * 30 ,30,30 };
	//SDL_RenderRect(Renderer, &rect);
	SDL_RenderTexture(Renderer, RenderingObject->textue, nullptr, &Location);
}

void URenderer::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenHandles[CurrentScreenIndex]);
	CurrentScreenIndex++;
	CurrentScreenIndex %= 2;
}

void URenderer::Prescent()
{
	SDL_RenderPresent(Renderer);
}

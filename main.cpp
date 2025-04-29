#include <iostream>
#include <windows.h>
#include "Engine.h"
#include "SDL3/SDL.h"

#pragma comment(lib, "SDL3")

int main()
{
	/* UEngine* Engine = UEngine::Instance();*/
	//int (*FP)(int, int);
	//int a = 5;
	//int c = 5;
	//FP = [](int A, int B)
	//	{
	//		return A * B;
	//	};

	GEninge->Initialize();
	GEninge->Run();
	GEninge->Terminate();

	return 0;
}

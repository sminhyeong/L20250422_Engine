#include <fstream>
#include <iostream>
#include<algorithm>
#include "World.h"
#include "Actor.h"
#include "Player.h"
#include "Wall.h"
#include "Goal.h"
#include "Monster.h"
#include "Ground.h"
#include "Vector2D.h"
#include "Renderer.h"

UWorld::UWorld()
{
	//MapWidth = 0;
	//SpawnActor(new APlayer());
	//SpawnActor(new AWall());

	//AWall* NewWall = new AWall();
	//NewWall->Location.X = 1;
	//NewWall->Location.Y = 0;

	//SpawnActor(NewWall);
	//
	//NewWall = new AWall();
	//NewWall->Location.X = 2;
	//NewWall->Location.Y = 0;

	//SpawnActor(NewWall);
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
		Actor = nullptr;
	}
	Actors.clear();
}

void UWorld::Load(std::string filepath)
{
	//구현
	//Map파일 읽어서 만들기
	///text
	std::ifstream map;
	map.open(filepath);

	if (map.fail())
	{
		printf("Load Failed : World Setting File Not Found\n");
		return;
	}
	int width = 0;
	int heigh = 0;
	char data[20] = { '\0', };

	std::string MapData = "";

	while (map.getline(data, sizeof(data)))
	{
		std::string MapDataLine(data);
		for (auto MapData : MapDataLine)
		{
			SetActorData(MapData, width, heigh);
			width++;
		}

		heigh++;
		width = 0;

	}
	map.close();

	std::sort(Actors.begin(), Actors.end(), [](const AActor* A, const AActor* B)
		{return A->GetRenderOrder() > B->GetRenderOrder(); });
	//SortActors();
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	URenderer::GetInstance()->Clear();
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
	URenderer::GetInstance()->Flip();
	URenderer::GetInstance()->Prescent();

}

void UWorld::SpawnActor(AActor* NewActor)
{
	NewActor->SetMyWorld(this);
	Actors.push_back(NewActor);
}

void UWorld::DestroyActor(AActor* DestroyedActor)
{
	Actors.erase(find(Actors.begin(), Actors.end(), DestroyedActor));
	//delete DestroyedActor;
}

std::vector<AActor*>& UWorld::GetAllActors()
{
	return Actors;
}

std::vector<AActor*> UWorld::GetActors(int X, int Y)
{
	std::vector<AActor*> actors;
	for (auto actor : Actors)
	{
		if (actor->Location.X == X && actor->Location.Y == Y)
		{
			actors.push_back(actor);
		}
	}
	return actors;
}

void UWorld::SetActorData(char Shape, int Width, int heigh)
{
	AActor* NewActor = nullptr;

	SpawnActor(new AGround(Fvector2D(Width, heigh)));

	switch (toupper(Shape))
	{
	case '*':
		NewActor = new AWall(Fvector2D(Width, heigh));
		break;
	case 'P':
		NewActor = new APlayer(Fvector2D(Width, heigh));
		break;
	case 'G':
		NewActor = new AGoal(Fvector2D(Width, heigh));
		break;
	case 'M':
		NewActor = new AMonster(Fvector2D(Width, heigh));
		break;
	}

	
	
	if (NewActor)
	{
		SpawnActor(NewActor);
	}
}

void UWorld::SortActors()
{
	for (int i = 0; i < Actors.size() - 1; i++)
	{
		int ChangeIdx = 0;
		int MaxRenderOrder = Actors[i]->GetRenderOrder();
		for (int j = i + 1; j < Actors.size(); j++)
		{
			if (Actors[j]->GetRenderOrder() > MaxRenderOrder)
			{
				ChangeIdx = j;
				MaxRenderOrder = Actors[j]->GetRenderOrder();
			}
		}

		AActor* temp = Actors[i];
		Actors[i] = Actors[ChangeIdx];
		Actors[ChangeIdx] = temp;
		temp = nullptr;
	}
	//for (auto Actor : Actors)
	//{
	//	std::cout << Actor->GetRenderOrder() << std::endl;
	//}
}

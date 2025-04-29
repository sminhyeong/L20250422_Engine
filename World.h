#pragma once
#include <vector>
#include <string>
class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	virtual void Load(std::string filepath);
	virtual void Tick();
	virtual void Render();

	void SpawnActor(AActor* NewActor);
	void DestroyActor(AActor* DestroyedActor);
	
	std::vector<AActor*>& GetAllActors();

	std::vector<AActor*> GetActors(int X, int Y);

protected:
	void SetActorData(char Shape,int Width, int heigh);
	std::vector<AActor*> Actors;
	void SortActors();
	
};


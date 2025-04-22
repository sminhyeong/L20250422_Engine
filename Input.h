#pragma once
class UInput
{
public:
	UInput();
	virtual ~UInput();

	virtual void Tick();

	static char KeyCode;
};



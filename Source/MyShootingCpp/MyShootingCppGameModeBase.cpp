// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyShootingCppGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "ScoreWidget.h"

void AMyShootingCppGameModeBase::BeginPlay()
{
	// Score������ �����ؼ� 
	UScoreWidget* ui = CreateWidget<UScoreWidget>(GetWorld(), scoreWidgetFactory);
	// ȭ�鿡 ����ϰ�ʹ�.
}

void AMyShootingCppGameModeBase::AddScore(int value)
{
	// ������ �����ϰ�ʹ�.
	score = score + value;
}

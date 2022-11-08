// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyShootingCppGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "ScoreWidget.h"

void AMyShootingCppGameModeBase::BeginPlay()
{
	// Score위젯을 생성해서 
	UScoreWidget* ui = CreateWidget<UScoreWidget>(GetWorld(), scoreWidgetFactory);
	// 화면에 출력하고싶다.
}

void AMyShootingCppGameModeBase::AddScore(int value)
{
	// 점수를 누적하고싶다.
	score = score + value;
}

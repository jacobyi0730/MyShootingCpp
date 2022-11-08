// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyShootingCppGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "ScoreWidget.h"
#include <Components/TextBlock.h>

void AMyShootingCppGameModeBase::BeginPlay()
{
	// Score위젯을 생성해서 
	scoreWidget = CreateWidget<UScoreWidget>(GetWorld(), scoreWidgetFactory);
	// 화면에 출력하고싶다.
	scoreWidget->AddToViewport();
}

void AMyShootingCppGameModeBase::AddScore(int value)
{
	// 점수를 누적하고싶다.
	score = score + value;
	// UI에도 점수를 반영하고싶다.
	scoreWidget->TextBlock_Score->SetText(FText::AsNumber(score));
}

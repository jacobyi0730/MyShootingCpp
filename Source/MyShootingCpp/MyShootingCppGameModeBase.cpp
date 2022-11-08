// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyShootingCppGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "ScoreWidget.h"
#include <Components/TextBlock.h>

void AMyShootingCppGameModeBase::BeginPlay()
{
	// Score������ �����ؼ� 
	scoreWidget = CreateWidget<UScoreWidget>(GetWorld(), scoreWidgetFactory);
	// ȭ�鿡 ����ϰ�ʹ�.
	scoreWidget->AddToViewport();
}

void AMyShootingCppGameModeBase::AddScore(int value)
{
	// ������ �����ϰ�ʹ�.
	score = score + value;
	// UI���� ������ �ݿ��ϰ�ʹ�.
	scoreWidget->TextBlock_Score->SetText(FText::AsNumber(score));
}

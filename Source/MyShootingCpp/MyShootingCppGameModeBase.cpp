// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyShootingCppGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "ScoreWidget.h"
#include <Components/TextBlock.h>
#include "GameOverWidget.h"

void AMyShootingCppGameModeBase::BeginPlay()
{
	// Score������ �����ؼ� 
	scoreWidget = CreateWidget<UScoreWidget>(GetWorld(), scoreWidgetFactory);
	// ȭ�鿡 ����ϰ�ʹ�.
	scoreWidget->AddToViewport();

	gameOverWidget = CreateWidget<UGameOverWidget>(GetWorld(), gameOverWidgetFactory);

	// ���콺 Ŀ���� �������ʰ� �ϰ�ʹ�.
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);
	// �Է¸�带 GameOnly
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
}

void AMyShootingCppGameModeBase::AddScore(int value)
{
	// ������ �����ϰ�ʹ�.
	score = score + value;
	// UI���� ������ �ݿ��ϰ�ʹ�.
	scoreWidget->TextBlock_Score->SetText(FText::AsNumber(score));
}

void AMyShootingCppGameModeBase::ShowGameOverUI()
{
	gameOverWidget->AddToViewport();
	// ���콺�� ���̰��ϰ�ʹ�.
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
	// �Է¸�带 UIOnly�� �ϰ�ʹ�.
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	GetWorld()->GetFirstPlayerController()->SetPause(true);

}

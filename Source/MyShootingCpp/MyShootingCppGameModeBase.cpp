// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyShootingCppGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "ScoreWidget.h"
#include <Components/TextBlock.h>
#include "GameOverWidget.h"

void AMyShootingCppGameModeBase::BeginPlay()
{
	// Score위젯을 생성해서 
	scoreWidget = CreateWidget<UScoreWidget>(GetWorld(), scoreWidgetFactory);
	// 화면에 출력하고싶다.
	scoreWidget->AddToViewport();

	gameOverWidget = CreateWidget<UGameOverWidget>(GetWorld(), gameOverWidgetFactory);

	// 마우스 커서를 보이지않게 하고싶다.
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);
	// 입력모드를 GameOnly
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
}

void AMyShootingCppGameModeBase::AddScore(int value)
{
	// 점수를 누적하고싶다.
	score = score + value;
	// UI에도 점수를 반영하고싶다.
	scoreWidget->TextBlock_Score->SetText(FText::AsNumber(score));
}

void AMyShootingCppGameModeBase::ShowGameOverUI()
{
	gameOverWidget->AddToViewport();
	// 마우스를 보이게하고싶다.
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
	// 입력모드를 UIOnly로 하고싶다.
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	GetWorld()->GetFirstPlayerController()->SetPause(true);

}

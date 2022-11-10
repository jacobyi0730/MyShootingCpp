// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyShootingCppGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "ScoreWidget.h"
#include <Components/TextBlock.h>
#include "GameOverWidget.h"
#include "HighScoreSaveGame.h"
#include <Kismet/GameplayStatics.h>

void AMyShootingCppGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	saveUserIndex = 0;

	// Score위젯을 생성해서 
	scoreWidget = CreateWidget<UScoreWidget>(GetWorld(), scoreWidgetFactory);
	// 화면에 출력하고싶다.
	scoreWidget->AddToViewport();

	gameOverWidget = CreateWidget<UGameOverWidget>(GetWorld(), gameOverWidgetFactory);

	// 마우스 커서를 보이지않게 하고싶다.
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);
	// 입력모드를 GameOnly
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());

	highScore = TryLoadGame();
	scoreWidget->TextBlock_HighScore->SetText(FText::AsNumber(highScore));
}

void AMyShootingCppGameModeBase::AddScore(int value)
{
	// 점수를 누적하고싶다.
	score = score + value;
	// UI에도 점수를 반영하고싶다.
	scoreWidget->TextBlock_Score->SetText(FText::AsNumber(score));

	// 만약 score > highScore 라면
	if (score > highScore)
	{ 
		highScore = score;
		//    UI 에도 반영하고싶다.
		scoreWidget->TextBlock_HighScore->SetText(FText::AsNumber(highScore));

		TrySaveGame(highScore);
	}
}

void AMyShootingCppGameModeBase::TrySaveGame(int32 value)
{
	USaveGame* temp = UGameplayStatics::CreateSaveGameObject(UHighScoreSaveGame::StaticClass());
	
	UHighScoreSaveGame* saveInst = Cast<UHighScoreSaveGame>(temp);

	saveInst->save_highScore = value;

	if (UGameplayStatics::SaveGameToSlot(saveInst, saveFileName, 0))
	{
		UE_LOG(LogTemp, Warning, TEXT("Save Successed!!"));
	}
}

int32 AMyShootingCppGameModeBase::TryLoadGame()
{
	if (false == UGameplayStatics::DoesSaveGameExist(saveFileName, 0))
	{
		return 0;
	}
	USaveGame* temp = UGameplayStatics::LoadGameFromSlot(saveFileName, 0);
	UHighScoreSaveGame* saveInst = Cast<UHighScoreSaveGame>(temp);
	return saveInst->save_highScore;
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

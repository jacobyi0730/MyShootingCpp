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

	// Score������ �����ؼ� 
	scoreWidget = CreateWidget<UScoreWidget>(GetWorld(), scoreWidgetFactory);
	// ȭ�鿡 ����ϰ�ʹ�.
	scoreWidget->AddToViewport();

	gameOverWidget = CreateWidget<UGameOverWidget>(GetWorld(), gameOverWidgetFactory);

	// ���콺 Ŀ���� �������ʰ� �ϰ�ʹ�.
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);
	// �Է¸�带 GameOnly
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());

	highScore = TryLoadGame();
	scoreWidget->TextBlock_HighScore->SetText(FText::AsNumber(highScore));
}

void AMyShootingCppGameModeBase::AddScore(int value)
{
	// ������ �����ϰ�ʹ�.
	score = score + value;
	// UI���� ������ �ݿ��ϰ�ʹ�.
	scoreWidget->TextBlock_Score->SetText(FText::AsNumber(score));

	// ���� score > highScore ���
	if (score > highScore)
	{ 
		highScore = score;
		//    UI ���� �ݿ��ϰ�ʹ�.
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
	// ���콺�� ���̰��ϰ�ʹ�.
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
	// �Է¸�带 UIOnly�� �ϰ�ʹ�.
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	GetWorld()->GetFirstPlayerController()->SetPause(true);

}

// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyShootingCppGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MYSHOOTINGCPP_API AMyShootingCppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	int score = 0;
	int highScore;
	void AddScore(int value);

	FString saveFileName = TEXT("highscore");
	int32 saveUserIndex;

	// highScore���� ���ϸ� ȣ��
	void TrySaveGame(int32 value);
	// ������ �����Ҷ� �ѹ� ȣ��
	int32 TryLoadGame();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UScoreWidget> scoreWidgetFactory;

	class UScoreWidget* scoreWidget;


	UPROPERTY(EditAnywhere)
	TSubclassOf<class UGameOverWidget> gameOverWidgetFactory;

	class UGameOverWidget* gameOverWidget;

	void ShowGameOverUI();


};

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
	void AddScore(int value);

	TSubclassOf<class UScoreWidget> scoreWidgetFactory;
	class UScoreWidget* scoreWidget;
};

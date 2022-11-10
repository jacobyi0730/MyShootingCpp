// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

/**
 *
 */
UCLASS()
class MYSHOOTINGCPP_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TextBlock_ScoreTitle;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TextBlock_Score;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TextBlock_HighScore;
};

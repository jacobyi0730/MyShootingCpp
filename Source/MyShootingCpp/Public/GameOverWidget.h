// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYSHOOTINGCPP_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Restart;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Quit;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetAnim), Transient)
	class UWidgetAnimation* NewAnimation;

	UFUNCTION()
	void OnMyRestart();
	UFUNCTION()
	void OnMyQuit();
};

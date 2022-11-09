// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include <Components/Button.h>
#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetSystemLibrary.h>

void UGameOverWidget::NativeConstruct()
{
	// ��ư�� �Լ��� �����ϰ�ʹ�.
	Button_Restart->OnClicked.AddDynamic(this, &UGameOverWidget::OnMyRestart);

	Button_Quit->OnClicked.AddDynamic(this, &UGameOverWidget::OnMyQuit);
}

void UGameOverWidget::OnMyRestart()
{
	FString levelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	UGameplayStatics::OpenLevel(GetWorld(), FName(*levelName));
}
void UGameOverWidget::OnMyQuit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, false);
}

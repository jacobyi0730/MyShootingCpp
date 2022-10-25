// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCodingActor.h"

// Sets default values
AMyCodingActor::AMyCodingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCodingActor::BeginPlay()
{
	Super::BeginPlay();
	 // 객체가 자기자신을 부를때 this라고 부른다.
	
	//int result = PlusPure(10, 30);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), result);
	
	if (number == 0)// 만약 number가 0이라면
	{
		UE_LOG(LogTemp, Warning, TEXT("안녕"));// "안녕" 을 출력하고싶다.
	}
	else if (number >= 1 && number <= 3)// 그렇지 않고 number가 1이상 그리고  number가 3이하라면
	{
		UE_LOG(LogTemp, Warning, TEXT("Hello"));// "Hello"를 출력하고싶다.
	}
	else // 이도저도 아니라면
	{
		UE_LOG(LogTemp, Warning, TEXT("Bye"));// "Bye"를 출력하고싶다.
	}
	
	
	



}

// Called every frame
void AMyCodingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCodingActor::NotifyActorBeginOverlap(AActor* OtherActor)
{

}

int AMyCodingActor::PlusCallable(int a, int b)
{
	return a + b;
}
int AMyCodingActor::PlusPure(int a, int b)
{
	return a + b;
}

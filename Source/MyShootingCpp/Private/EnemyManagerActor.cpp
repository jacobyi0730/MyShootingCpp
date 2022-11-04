// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManagerActor.h"
#include <Components/ArrowComponent.h>
#include "EnemyActor.h"
#include <Kismet/GameplayStatics.h>
#include "PlayerPawn.h"

// Sets default values
AEnemyManagerActor::AEnemyManagerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spawnArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("spawnArrow"));
	spawnArrow->SetRelativeRotation(FRotator(-90, 0, 0));
}

// Called when the game starts or when spawned
void AEnemyManagerActor::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle timerHandle;
	GetWorldTimerManager().SetTimer(timerHandle, this, &AEnemyManagerActor::MakeEnemy, makeTime, true);
}

// Called every frame
void AEnemyManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//// 1. 시간이 흐르다가 
	//currentTime = currentTime + DeltaTime;
	//// 2. 만약 현재시간 > 생성시간을 초과하면
	//if (currentTime > makeTime)
	//{
	//	// 3. 적 공장에서 적을 만들어서 spawnArrow위치에 배치하고싶다.
	//	GetWorld()->SpawnActor<AEnemyActor>(enemyFactory, spawnArrow->GetComponentTransform());
	//	// 4. 현재시간을 초기화 하고싶다.
	//	currentTime = 0;
	//}

}

void AEnemyManagerActor::MakeEnemy()
{
	// 만약 플레이폰이 파괴되지 않았다면
	// 만약 플레이폰이 nullptr이 아니라면
	/*AActor* target = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerPawn::StaticClass());
	
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerPawn::StaticClass(), OutActors);

	for each (AActor* var in OutActors)
	{

	}*/

	auto target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (target != nullptr)
	{
		GetWorld()->SpawnActor<AEnemyActor>(enemyFactory, spawnArrow->GetComponentTransform());
	}
}


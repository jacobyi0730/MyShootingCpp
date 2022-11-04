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

	//// 1. �ð��� �帣�ٰ� 
	//currentTime = currentTime + DeltaTime;
	//// 2. ���� ����ð� > �����ð��� �ʰ��ϸ�
	//if (currentTime > makeTime)
	//{
	//	// 3. �� ���忡�� ���� ���� spawnArrow��ġ�� ��ġ�ϰ�ʹ�.
	//	GetWorld()->SpawnActor<AEnemyActor>(enemyFactory, spawnArrow->GetComponentTransform());
	//	// 4. ����ð��� �ʱ�ȭ �ϰ�ʹ�.
	//	currentTime = 0;
	//}

}

void AEnemyManagerActor::MakeEnemy()
{
	// ���� �÷������� �ı����� �ʾҴٸ�
	// ���� �÷������� nullptr�� �ƴ϶��
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


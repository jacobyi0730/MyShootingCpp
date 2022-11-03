// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerPawn.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	// boxComp를 Root로 하고싶다.
	RootComponent = boxComp;

	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("Enemy"));

	boxComp->SetBoxExtent(FVector(50, 50, 50));

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyActor::OnBoxComponentBeginOverlap);


	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	// 태어날 때 방향을 정하고싶다.
	// 30% 확률로 플레이어방향, 나머지는 앞방향으로 결정하고싶다.
	float result = FMath::FRandRange(0.0f, 1.0f);
	if (result < 0.3f)
	{
		// 플레이어방향
		auto target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		direction = target->GetActorLocation() - GetActorLocation();
		direction.Normalize();
	}
	else {
		// 앞방향
		direction = GetActorForwardVector();
	}

}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 그 방향으로 이동하고싶다.
	// P = P0 + vt
	SetActorLocation(GetActorLocation() + direction * speed * DeltaTime);
}

void AEnemyActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	// 부딪힌 상대가 플레이어라면
	////if (OtherActor->IsA(APlayerPawn::StaticClass()))
	//auto player = Cast<APlayerPawn>(OtherActor);
	//if (player != nullptr)
	//{
	//	// 너죽고 
	//	OtherActor->Destroy();
	//	// 나죽고 하고싶다.
	//	this->Destroy();
	//}

}

void AEnemyActor::OnBoxComponentBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor->IsA(APlayerPawn::StaticClass()))
	{
		Explosion();

		// 너죽고 
		OtherActor->Destroy();
		// 나죽고 하고싶다.
		this->Destroy();
	}
}

void AEnemyActor::Explosion()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionVFXFactory, GetActorLocation());
}


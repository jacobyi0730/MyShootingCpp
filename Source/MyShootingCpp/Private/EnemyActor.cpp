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
	// boxComp�� Root�� �ϰ�ʹ�.
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
	// �¾ �� ������ ���ϰ�ʹ�.
	// 30% Ȯ���� �÷��̾����, �������� �չ������� �����ϰ�ʹ�.
	float result = FMath::FRandRange(0.0f, 1.0f);
	if (result < 0.3f)
	{
		// �÷��̾����
		auto target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		direction = target->GetActorLocation() - GetActorLocation();
		direction.Normalize();
	}
	else {
		// �չ���
		direction = GetActorForwardVector();
	}

}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// �� �������� �̵��ϰ�ʹ�.
	// P = P0 + vt
	SetActorLocation(GetActorLocation() + direction * speed * DeltaTime);
}

void AEnemyActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	// �ε��� ��밡 �÷��̾���
	////if (OtherActor->IsA(APlayerPawn::StaticClass()))
	//auto player = Cast<APlayerPawn>(OtherActor);
	//if (player != nullptr)
	//{
	//	// ���װ� 
	//	OtherActor->Destroy();
	//	// ���װ� �ϰ�ʹ�.
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

		// ���װ� 
		OtherActor->Destroy();
		// ���װ� �ϰ�ʹ�.
		this->Destroy();
	}
}

void AEnemyActor::Explosion()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionVFXFactory, GetActorLocation());
}


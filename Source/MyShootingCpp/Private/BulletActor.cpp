// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>
#include "EnemyActor.h"

// Sets default values
ABulletActor::ABulletActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	// boxComp�� Root�� �ϰ�ʹ�.
	RootComponent = boxComp;

	// �浹ó�� case 1 : ���� ����
	//boxComp->SetGenerateOverlapEvents(true);
	//boxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//boxComp->SetCollisionObjectType(ECC_GameTraceChannel3);
	//boxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	//boxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);

	// �浹ó�� case 2 : preset�� �̿�
	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("Bullet"));

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ABulletActor::OnBoxComponentBeginOverlap);

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ���� �̵��ϰ�ʹ�.
	// P = P0 + vt
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * speed * DeltaTime);

}

void ABulletActor::OnBoxComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AEnemyActor::StaticClass()))
	{
		auto enemy = Cast<AEnemyActor>(OtherActor);
		enemy->Explosion();

		// ���װ� 
		OtherActor->Destroy();
		// ���װ� �ϰ�ʹ�.
		this->Destroy();
	}
}

//void ABulletActor::NotifyActorBeginOverlap(AActor* OtherActor)
//{
//	// ���� �ε��� ��밡 Enemy���
//	if (OtherActor->IsA(AEnemyActor::StaticClass()))
//	{
//		// ���װ� 
//		OtherActor->Destroy();
//		// ���װ� �ϰ�ʹ�.
//		this->Destroy();
//	}
//	
//	//AEnemyActor* enemy = Cast<AEnemyActor>(OtherActor);
//	//if (enemy != nullptr)
//	//{
//
//	//}
//	
//	
//}


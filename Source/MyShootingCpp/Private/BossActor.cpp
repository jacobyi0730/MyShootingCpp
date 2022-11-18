// Fill out your copyright notice in the Description page of Project Settings.


#include "BossActor.h"
#include <Kismet/KismetMathLibrary.h>
#include "EnemyBulletActor.h"

// Sets default values
ABossActor::ABossActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABossActor::BeginPlay()
{
	Super::BeginPlay();

	state = EBossState::Idle;
	origin = GetActorLocation();

}

// Called every frame
void ABossActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (state)
	{
	case EBossState::Move:
		TickMove();
		break;
	case EBossState::Attack:
		TickAttack();
		break;
	}
}

void ABossActor::TickMove()
{
	FVector loc = UKismetMathLibrary::VLerp(origin, moveTarget->GetActorLocation(), alpha);

	SetActorLocation(loc);

	alpha += GetWorld()->GetDeltaSeconds() / speedRate;

	if (alpha >= 1)
	{
		state = EBossState::Attack;
	}
}

void ABossActor::TickAttack()
{
	if (bFireOneShot)
	{
		// 시간이 흐르다가
		currentTime += GetWorld()->GetDeltaSeconds();
		// 발사시간이 되면
		if (currentTime > fireTime)
		{
			currentTime = 0;
			// 적총알공장에서 총알을 12발 만들어서 360도로 쏘고싶다.
			FQuat zeroQ = FQuat(FRotator(90, 0, 0));
			for (int i = 0; i < 12; i++)
			{
				FQuat addQ = FQuat(FRotator(0, i * 30, 0));
				FRotator angle = FRotator(zeroQ * addQ);
				MakeEnemyBullet(GetActorLocation(), angle);
			}
		}
	}
	else
	{
		currentTime += GetWorld()->GetDeltaSeconds();
		if (currentTime > shotFireTime)
		{
			currentTime = 0;
			float shotAngle = 360 / shotMaxIndex;
			FQuat zeroQ = FQuat(FRotator(90, 0, 0));
			FQuat addQ = FQuat(FRotator(0, shotIndex * shotAngle, 0));
			FRotator angle = FRotator(zeroQ * addQ);
			MakeEnemyBullet(GetActorLocation(), angle);
			
			shotIndex = (shotIndex + 1) % shotMaxIndex;

			//shotIndex = (shotIndex + shotMaxIndex - 1) % shotMaxIndex;
		}
	}
}

void ABossActor::MakeEnemyBullet(FVector loc, FRotator angle)
{
	GetWorld()->SpawnActor<AEnemyBulletActor>(enemyBulletFactory, loc, angle);
}


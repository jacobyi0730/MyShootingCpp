// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBulletActor.generated.h"

UCLASS()
class MYSHOOTINGCPP_API AEnemyBulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyBulletActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBoxComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;
	
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	// 위로 이동하고싶다.
	UPROPERTY(EditAnywhere)
	float speed = 1000;

	UPROPERTY(EditAnywhere, Category = Info)
	class UParticleSystem* explosionVFXFactory;

	void Explosion();
};

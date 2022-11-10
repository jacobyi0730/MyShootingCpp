// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class MYSHOOTINGCPP_API AEnemyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION()
	void OnBoxComponentBeginOverlap(
	UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult);

	// ���������ʹ�.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	// �¾ �� ������ ���ϰ�ʹ�. 30% Ȯ���� �÷��̾����, �������� �չ������� �����ϰ�ʹ�.

	// ��ư��鼭 �� �������� �̵��ϰ�ʹ�.
	UPROPERTY(EditAnywhere, Category = Info)
	FVector direction;
	UPROPERTY(EditAnywhere, Category = Info)
	float speed = 500;
public:
	// Enemy�� ������(Bullet, Player)�� �ε����� �����ϰ�ʹ�.
	UPROPERTY(EditAnywhere, Category = Info)
	class UParticleSystem* explosionVFXFactory;

	void Explosion();

	FTimerHandle timerHandleMakeBullet;
	UPROPERTY(EditAnywhere)
	float makeMin = 0.5f;
	UPROPERTY(EditAnywhere)
	float makeMax = 1.0f;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemyBulletActor> enemyBulletFactory;

	void MakeEnemyBullet();
};

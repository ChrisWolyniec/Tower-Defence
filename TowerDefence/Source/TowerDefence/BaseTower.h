// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTower.generated.h"

UCLASS()
class TOWERDEFENCE_API ABaseTower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseTower();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;


	// Getters and Setters
	virtual void SetTowerName(FString towerName) { mName = towerName; }
	virtual FString GetTowerName() { return mName; }

	virtual void SetAttackDamage(int attackDamage) { mAttackDamage = attackDamage; }
	virtual int GetAttackDamge() { return mAttackDamage; }
	
	virtual void SetAttackRange(int attackRange) { mAttackRange = attackRange; }
	virtual int GetAttackRange() { return mAttackRange; }

	virtual void SetAttackSpeed(int attackSpeed) { mAttackSpeed = attackSpeed; }
	virtual int GetAttackSpeed() { return mAttackSpeed; }

	virtual void SetTowerCost(int cost) { mCost= cost; }
	virtual int GetTowerCost() { return mCost; }

	enum TowerTypes  
	{
		AOE,
		SLOW,
		NORMAL
	};

private:
	FString mName = "Base";
	int mAttackDamage = 0; 
	int mAttackRange = 0;
	int mAttackSpeed = 0;
	int mCost = 0;



};

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	x = 0;
	y = 0;
	totalDist = 0.0f;
	eventCnt = 0;
	// TO
}

void AMyActor::move(int newX, int newY)
{	
	int prevX = x;

	int prevY = y;
	x += newX;
	y += newY;
	FVector2D pointA(prevX, prevY);
	FVector2D pointB(x, y);
	float dist = FVector2D::Distance(pointA, pointB);
	totalDist += dist;
	UE_LOG(LogTemp, Warning, TEXT("Actor moved to (%d, %d), Distance: %.2f"), x, y, dist);
}

int AMyActor::step() {
	bool rand = FMath::RandBool(); // true or false를 50% 확률로 return
	if (rand) eventCnt++;

	return FMath::RandRange(0, 1);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay(); // 부모 클래스(AActor)의 BeginPlay() 실행
		
	for (int i = 0; i < 10; i++) {
		int rand = step();
		move(rand, rand);
	}
	UE_LOG(LogTemp, Warning, TEXT("total distance %.2f, total event count: %d"), totalDist, eventCnt);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "lightSwitchBP.generated.h"

UCLASS()
class MYT2PROJECT_API AlightSwitchBP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AlightSwitchBP();

	// Create Light Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "SwitchComponents")
	class UPointLightComponent* PointLight1;

	// Create Sphere Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "SwitchComponents")
	class USphereComponent* Sphere1;


	/* called when something enters sphere component */
	UFUNCTION(BlueprintNativeEvent, Category= "SwitchFunctions")
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/* called when something leaves the sphere component */
	UFUNCTION(BlueprintNativeEvent, Category= "SwitchFunctions")
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void OnOverlapEnd_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Toggles Light Visibility
	UFUNCTION()
	void ToggleLight();

	// Desired Intensity for the Light Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "SwitchVariables")
	float DesiredIntensity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

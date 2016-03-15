#pragma once

#include "RealSenseComponent.h"
#include "ExpressionComponent.generated.h"
UCLASS(editinlinenew, meta = (BlueprintSpawnableComponent), ClassGroup = RealSense)
class UExpressionComponent : public URealSenseComponent
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		int32 HeadCount;

	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		FVector HeadPosition;

	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		FRotator HeadRotation;

	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		FVector EyesDirection;

	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		float EyebrowLeft;
	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		float EyebrowRight;
	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		float EyeClosedLeft;
	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		float EyeClosedRight;
	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		float MouthOpen;
	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		float MouthKiss;
	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		float MouthSmile;
	UPROPERTY(BlueprintReadOnly, Category = "RealSense")
		float MouthThunge;


	UExpressionComponent();

	void InitializeComponent() override;

	void TickComponent(float DeltaTime, enum ELevelTick TickType,
		FActorComponentTickFunction *ThisTickFunction) override;

private:
};
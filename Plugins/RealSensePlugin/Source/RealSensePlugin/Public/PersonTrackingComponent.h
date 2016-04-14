#pragma once

#include "RealSenseComponent.h"
#include "PersonTrackingComponent.generated.h"

UCLASS(editinlinenew, meta = (BlueprintSpawnableComponent), ClassGroup = RealSense) 
class UPersonTrackingComponent : public URealSenseComponent
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RealSense")
	TArray<FSkeletonData> SkeletonData;

	UPersonTrackingComponent();

	void InitializeComponent() override;
	
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void PrintSkeletonData();
	void DrawSkeletonData();

private:
};

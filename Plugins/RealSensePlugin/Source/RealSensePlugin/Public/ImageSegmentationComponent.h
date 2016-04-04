#pragma once

#include "RealSenseComponent.h"
#include "ImageSegmentationComponent.generated.h"

UCLASS(editinlinenew, meta = (BlueprintSpawnableComponent), ClassGroup = RealSense) 
class UImageSegmentationComponent : public URealSenseComponent
{
	GENERATED_UCLASS_BODY()
		
	UPROPERTY(BlueprintReadWrite, Category = "RealSense")
	TArray<FSimpleColor> BGSBuffer;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RealSense")
	TArray<int32> GetSortedPlayerIDs();

	UImageSegmentationComponent();

	void InitializeComponent() override;
	
	void TickComponent(float DeltaTime, enum ELevelTick TickType, 
		               FActorComponentTickFunction *ThisTickFunction) override;

private:
	int channel = 0;
	void UpdateBuffer();
};

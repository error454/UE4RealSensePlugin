#include "RealSensePluginPrivatePCH.h"
#include "HandTrackingComponent.h"

UHandTrackingComponent::UHandTrackingComponent(const class FObjectInitializer& ObjInit) 
	: Super(ObjInit) 
{ 
	m_feature = RealSenseFeature::HAND_TRACKING;
}

void UHandTrackingComponent::InitializeComponent()
{
	Super::InitializeComponent();

}

void UHandTrackingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) 
{
	if (globalRealSenseSession->IsCameraRunning() == false) 
	{
		return;
	}

	TQueue<FHandData>* data = globalRealSenseSession->GetHandData();
	if (data)
	{
		FHandData HandData;
		if (data->Dequeue(HandData))
		{
			UE_LOG(LogTemp, Warning, TEXT("Gesture: %s"), *HandData.Name);
		}
	}
}
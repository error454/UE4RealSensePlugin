#include "RealSensePluginPrivatePCH.h"
#include "ImageSegmentationComponent.h"
#include "RealSenseBlueprintLibrary.h"

UImageSegmentationComponent::UImageSegmentationComponent(const class FObjectInitializer& ObjInit)
	: Super(ObjInit)
{
	m_feature = RealSenseFeature::IMAGE_SEGMENTATION;
}

void UImageSegmentationComponent::InitializeComponent()
{
	Super::InitializeComponent();

	BGSBuffer.SetNumZeroed(2500);
	if (rand() & 2) {
		channel = 0;
	}
	else {
		channel = 1;
	}
}

void UImageSegmentationComponent::UpdateBuffer()
{
	FSimpleColor Current_Color = BGSBuffer[0];

	if (channel == 0) {
		Current_Color.R = (Current_Color.R + 1) % 256;
	}
	else {
		Current_Color.B = (Current_Color.B + 1) % 256;
	}
	Current_Color.A = 255;

	for (int i = 0; i < 2500; i++) {
		BGSBuffer[i] = Current_Color;
	}
}

TArray<int32> UImageSegmentationComponent::GetSortedPlayerIDs()
{
	TArray<int32> PlayerIDs;
	AGameState* MyGameState = GetWorld()->GetGameState();
	if (MyGameState != nullptr) {
		for (APlayerState* ps : MyGameState->PlayerArray) {
			PlayerIDs.Add(ps->PlayerId);
		}
		PlayerIDs.Sort();
	}
	return PlayerIDs;
}

void UImageSegmentationComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, 
	                                 FActorComponentTickFunction *ThisTickFunction) 
{
//	if (globalRealSenseSession->IsCameraRunning() == false) {
//		return;
//	}

	UpdateBuffer();
//	BGSBuffer = globalRealSenseSession->GetBGSBuffer();
}

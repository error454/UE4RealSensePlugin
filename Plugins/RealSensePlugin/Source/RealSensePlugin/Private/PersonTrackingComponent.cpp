#include "RealSensePluginPrivatePCH.h"
#include "PersonTrackingComponent.h"

UPersonTrackingComponent::UPersonTrackingComponent(const class FObjectInitializer& ObjInit) 
	: Super(ObjInit) 
{ 
	m_feature = RealSenseFeature::PERSON_TRACKING;
}

void UPersonTrackingComponent::InitializeComponent()
{
	Super::InitializeComponent();

}

void UPersonTrackingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) 
{
	if (globalRealSenseSession->IsCameraRunning() == false) 
	{
		return;
	}

	SkeletonData = globalRealSenseSession->GetSkeletonData();

	PrintSkeletonData();
}

void UPersonTrackingComponent::PrintSkeletonData()
{
	for (auto& a : SkeletonData)
	{
		FString jointName = "Unknown";
		const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("FSkeletonData"), true);
		if (EnumPtr)
		{
			jointName = EnumPtr->GetDisplayNameText((int32)a.JointType).ToString();
		}
		UE_LOG(LogTemp, Warning, TEXT("Bone: %s Loc: %s"), *jointName, *a.Location.ToString());
	}
}

void UPersonTrackingComponent::DrawSkeletonData()
{

}

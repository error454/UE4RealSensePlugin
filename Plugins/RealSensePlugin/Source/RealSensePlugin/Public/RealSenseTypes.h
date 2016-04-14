#pragma once

#include "RealSenseTypes.generated.h"

// List of features provided by the RealSense SDK
enum RealSenseFeature : uint8 {
	CAMERA_STREAMING = 0x1,
	SCAN_3D = 0x2,
	HEAD_TRACKING = 0x4,
	PERSON_TRACKING = 0X8,
	HAND_TRACKING = 0X10,
};

// Resolutions supported by the RealSense RGB camera
UENUM(BlueprintType) 
enum class EColorResolution : uint8 {
	UNDEFINED = 0 UMETA(DisplayName = " "),
	RES1 = 1 UMETA(DisplayName = "1920 x 1080 x 30"),
	RES2 = 2 UMETA(DisplayName = "1280 x 720 x 30"),
	RES3 = 3 UMETA(DisplayName = "640 x 480 x 60"),
	RES4 = 4 UMETA(DisplayName = "640 x 480 x 30"),
	RES5 = 5 UMETA(DisplayName = "320 x 240 x 60"),
	RES6 = 6 UMETA(DisplayName = "320 x 240 x 30"),
};

// Resolutions supported by the RealSense depth camera
// (F200) denotes that this resolution is only supported by the F200 camera.
// (R200) denotes that this resolution is only supported by the R200 camera.
UENUM(BlueprintType) 
enum class EDepthResolution : uint8 {
	UNDEFINED = 0 UMETA(DisplayName = " "),
	RES1 = 1 UMETA(DisplayName = "640 x 480 x 60 (F200)"),
	RES2 = 2 UMETA(DisplayName = "640 x 480 x 30 (F200)"),
	RES3 = 3 UMETA(DisplayName = "628 x 468 x 90 (R200)"),
	RES4 = 4 UMETA(DisplayName = "628 x 468 x 60 (R200)"),
	RES5 = 5 UMETA(DisplayName = "628 x 468 x 30 (R200)"),
	RES6 = 6 UMETA(DisplayName = "480 x 360 x 90 (R200)"),
	RES7 = 7 UMETA(DisplayName = "480 x 360 x 60 (R200)"),
	RES8 = 8 UMETA(DisplayName = "480 x 360 x 30 (R200)"),
	RES9 = 9 UMETA(DisplayName = "320 x 240 x 90 (R200)"),
	RES10 = 10 UMETA(DisplayName = "320 x 240 x 60 (R200)"),
	RES11 = 11 UMETA(DisplayName = "320 x 240 x 30 (R200)"),
};

// RSSDK Pixel Format exposed to Blueprint (see pxcimage.h)
UENUM(BlueprintType) 
enum class ERealSensePixelFormat : uint8 {
	PIXEL_FORMAT_ANY = 0,  // Unknown/undefined
	COLOR_RGB32,    // BGRA layout
	DEPTH_G16_MM,   // 16-bit unsigned integer with precision mm.
};

// Supported RealSense camera models
UENUM(BlueprintType) 
enum class ECameraModel : uint8 {
	None = 0 UMETA(DisplayName = " "),
	F200 = 1 UMETA(DisplayName = "Front-Facing (F200)"),
	SR300 = 2 UMETA(DisplayName = "Short-Range (SR300)"),
	R200 = 3 UMETA(DisplayName = "World-Facing (R200)"),
	Other = 4 UMETA(DisplayName = "Unknown Camera Model")
};

// Supported modes for the 3D Scanning middleware
UENUM(BlueprintType) 
enum class EScan3DMode : uint8 {
	OBJECT = 0 UMETA(DisplayName = "Object"),
	FACE = 1 UMETA(DisplayName = "Face")
};

// File types supported by the 3D Scanning middleware for saving scans 
UENUM(BlueprintType) 
enum class EScan3DFileFormat : uint8 {
	OBJ = 0 UMETA(DisplayName = "OBJ")
};

// Basic 32-bit color structure (RGBA) 
USTRUCT(BlueprintType) 
struct FSimpleColor
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 R;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 G;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 B;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 A;
};

// Resolution of a RealSense camera stream
USTRUCT(BlueprintType) 
struct FStreamResolution
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fps;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERealSensePixelFormat format;
};

// Used to pass joint types back to UE4 in a blueprint readable way
UENUM(BlueprintType)
enum class EJointType : uint8
{
	JOINT_ANKLE_LEFT,
	JOINT_ANKLE_RIGHT,
	JOINT_ELBOW_LEFT,
	JOINT_ELBOW_RIGHT,
	JOINT_FOOT_LEFT,
	JOINT_FOOT_RIGHT,
	JOINT_HAND_LEFT,
	JOINT_HAND_RIGHT,
	JOINT_HAND_TIP_LEFT,
	JOINT_HAND_TIP_RIGHT,
	JOINT_HEAD,
	JOINT_HIP_LEFT,
	JOINT_HIP_RIGHT,
	JOINT_KNEE_LEFT,
	JOINT_KNEE_RIGHT,
	JOINT_NECK,
	JOINT_SHOULDER_LEFT,
	JOINT_SHOULDER_RIGHT,	
	JOINT_SPINE_BASE,
	JOINT_SPINE_MID,
	JOINT_SPINE_SHOULDER,
	JOINT_THUMB_LEFT,
	JOINT_THUMB_RIGHT,  
	JOINT_WRIST_LEFT,
	JOINT_WRIST_RIGHT
};

// Used to pass skeletal data back to UE4
USTRUCT(Blueprintable)
struct FSkeletonData
{
	GENERATED_USTRUCT_BODY()

 	UPROPERTY()
 	FVector Location;

 	UPROPERTY()
 	EJointType JointType;
};

// Used to pass hand data
USTRUCT(Blueprintable)
struct FHandData
{
	GENERATED_USTRUCT_BODY()

 	UPROPERTY()
 	FString Name;
};

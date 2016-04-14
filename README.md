### <b>RealSense Plugin for Unreal Engine 4 (facial expression fork)</b>

#### Changes in this fork
This fork is a modification to the HeadTracking project to test how hard it is to get facial expression data from the RealSense SDK. It is a quick and dirty hack on the SessionManager and the Component files, and probably will not recemble the final plugin at all.
One interesting note is that the function flag for head tracing is the same as with expression tracking, this was a bit confusing as the enum used in the plugin did not really match the module name of the RealSense SDK.

#### Overview
The RealSense Plugin provides support for the Intel RealSense SDK to Unreal Engine 4 developers by exposing features of the SDK to the Blueprints Visual Scripting System. 

The plugin is architected as a set of components, each of which encapsulates a specific set of features. Is also makes use of an actor known as the RealSense Session Manager, which manages access to the RealSense SDK functions and maintains the master copy of all RealSense data. It is instantiated automatically when the first RealSense component is created and it allows for the use of multiple instances of the same RealSense component class, easing the process of sharing data between objects.

RealSense processing takes place on its own dedicated thread. On every tick of the game thread, the RealSense Session Manager polls for new RealSense data, and updates the RealSense components accordingly. This separation helps keep the game thread running quickly even when the RealSense thread is doing some heavy lifting.

- - -

For more details, you can read this [article](https://software.intel.com/en-us/articles/intel-realsense-sdk-plug-in-for-unreal-engine-4).

You can also check out these tutorial videos to get started using the RealSense plugin: 

https://youtu.be/mrIiBssoI0w

https://youtu.be/WMqG3UZkBTE

- - -

#### Hardware Requirements
* RealSense Camera: [F200 Front-Facing RealSense Camera](http://click.intel.com/intel-realsense-developer-kit.html) __OR__ [R200 World-Facing RealSense Camera](http://click.intel.com/intel-realsense-developer-kit-r200.html)
* 4th Generation Intel(R) CPU or higher

#### Software Requirements
* [Intel(R) RealSense(TM) SDK R5](https://software.intel.com/en-us/intel-realsense-sdk/download)
* Unreal Engine 4.8 or higher
* Windows 8.1 or 10
* Visual Studio 2013 or higher

#### Featured Components
* Camera Streams - Provides access to raw color and depth image buffers
* Scan 3D - Supports the scanning of faces and objects into 3D models

#### In-Progress Components
* Head Tracking - Provides data for the user's head position and rotation
* Scene Perception - Supports the scanning of small scenes into 3D models

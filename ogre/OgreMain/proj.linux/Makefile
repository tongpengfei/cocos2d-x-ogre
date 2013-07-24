CC      = gcc
#CC		= @echo "compiling $@" && gcc
CXX     = g++
#CXX     = @echo "compiling $@" && g++

SO_TARGET = libOgreMain.so

CCFLAGS = -Wall
CCFLAGS += -g3 -O0
CXXFLAGS = -Wall -fPIC
CXXFLAGS += -g3 -O0
VISIBILITY = 

#CXXFLAGS += -DOGRE_NONCLIENT_BUILD -DOGRE_GUI_GLX -fvisibility=hidden -fvisibility-inlines-hidden -DOGRE_GCC_VISIBILITY -MD -MP -MF -Wno-deprecated
CXXFLAGS += -DOGRE_NONCLIENT_BUILD -fvisibility=hidden -fvisibility-inlines-hidden -DOGRE_GCC_VISIBILITY -Wno-deprecated

DEFINES = -DLINUX
DEFINES += -DDEBUG

SDK_PATH = ../../..
COCOS2DX_PATH = $(SDK_PATH)/cocos2dx
INCLUDES =  -I. \
			-I../include \
			-I../include/GLX \
			-I../../Build \
			-I../src/nedmalloc \
			-I$(COCOS2DX_PATH)/platform/third_party/linux/libfreetype2 \

#			-I$(COCOS2DX_PATH)/cocoa \
			-I$(COCOS2DX_PATH)/include \
			-I$(COCOS2DX_PATH)/platform\
			-I$(COCOS2DX_PATH)/platform/linux\
			-I$(COCOS2DX_PATH)/kazmath/include \
			-I$(COCOS2DX_PATH)/kazmath/include/kazmath \
			-I$(SDK_PATH)/extensions/ \
			-I$(COCOS2DX_PATH)/ \
#			-I../include/gtk \


SO_OBJECTS =   \
					../src/GLX/OgreTimer.o \
					../src/OgreAlignedAllocator.o \
					../src/OgreAnimable.o \
					../src/OgreAnimation.o \
					../src/OgreAnimationState.o \
					../src/OgreAnimationTrack.o \
					../src/OgreArchiveManager.o \
					../src/OgreAutoParamDataSource.o \
					../src/OgreAxisAlignedBox.o \
					../src/OgreBillboardChain.o \
					../src/OgreBillboard.o \
					../src/OgreBillboardParticleRenderer.o \
					../src/OgreBillboardSet.o \
					../src/OgreBone.o \
					../src/OgreBorderPanelOverlayElement.o \
					../src/OgreCamera.o \
					../src/OgreCodec.o \
					../src/OgreColourValue.o \
					../src/OgreCommon.o \
					../src/OgreCompositionPass.o \
					../src/OgreCompositionTargetPass.o \
					../src/OgreCompositionTechnique.o \
					../src/OgreCompositorChain.o \
					../src/OgreCompositor.o \
					../src/OgreCompositorInstance.o \
					../src/OgreCompositorManager.o \
					../src/OgreConfigFile.o \
					../src/OgreControllerManager.o \
					../src/OgreConvexBody.o \
					../src/OgreDataStream.o \
					../src/OgreDDSCodec.o \
					../src/OgreDefaultHardwareBufferManager.o \
					../src/OgreDefaultSceneQueries.o \
					../src/OgreDeflate.o \
					../src/OgreDepthBuffer.o \
					../src/OgreDistanceLodStrategy.o \
					../src/OgreDualQuaternion.o \
					../src/OgreDynLib.o \
					../src/OgreDynLibManager.o \
					../src/OgreEdgeListBuilder.o \
					../src/OgreEntity.o \
					../src/OgreException.o \
					../src/OgreExternalTextureSource.o \
					../src/OgreExternalTextureSourceManager.o \
					../src/OgreFileSystem.o \
					../src/OgreFont.o \
					../src/OgreFontManager.o \
					../src/OgreFrustum.o \
					../src/OgreGpuProgram.o \
					../src/OgreGpuProgramManager.o \
					../src/OgreGpuProgramParams.o \
					../src/OgreGpuProgramUsage.o \
					../src/OgreHardwareBufferManager.o \
					../src/OgreHardwareIndexBuffer.o \
					../src/OgreHardwareOcclusionQuery.o \
					../src/OgreHardwarePixelBuffer.o \
					../src/OgreHardwareVertexBuffer.o \
					../src/OgreHighLevelGpuProgram.o \
					../src/OgreHighLevelGpuProgramManager.o \
					../src/OgreImage.o \
					../src/OgreInstanceBatch.o \
					../src/OgreInstanceBatchHW.o \
					../src/OgreInstanceBatchHW_VTF.o \
					../src/OgreInstanceBatchShader.o \
					../src/OgreInstanceBatchVTF.o \
					../src/OgreInstancedEntity.o \
					../src/OgreInstancedGeometry.o \
					../src/OgreInstanceManager.o \
					../src/OgreKeyFrame.o \
					../src/OgreLight.o \
					../src/OgreLodStrategy.o \
					../src/OgreLodStrategyManager.o \
					../src/OgreLog.o \
					../src/OgreLogManager.o \
					../src/OgreManualObject.o \
					../src/OgreMaterial.o \
					../src/OgreMaterialManager.o \
					../src/OgreMaterialSerializer.o \
					../src/OgreMath.o \
					../src/OgreMatrix3.o \
					../src/OgreMatrix4.o \
					../src/OgreMemoryAllocatedObject.o \
					../src/OgreMemoryNedAlloc.o \
					../src/OgreMemoryNedPooling.o \
					../src/OgreMemoryTracker.o \
					../src/OgreMesh.o \
					../src/OgreMeshManager.o \
					../src/OgreMeshSerializer.o \
					../src/OgreMeshSerializerImpl.o \
					../src/OgreMovableObject.o \
					../src/OgreMovablePlane.o \
					../src/OgreNode.o \
					../src/OgreNumerics.o \
					../src/OgreOptimisedUtil.o \
					../src/OgreOptimisedUtilGeneral.o \
					../src/OgreOptimisedUtilSSE.o \
					../src/OgreOverlayContainer.o \
					../src/OgreOverlay.o \
					../src/OgreOverlayElementCommands.o \
					../src/OgreOverlayElement.o \
					../src/OgreOverlayElementFactory.o \
					../src/OgreOverlayManager.o \
					../src/OgrePanelOverlayElement.o \
					../src/OgreParticle.o \
					../src/OgreParticleEmitterCommands.o \
					../src/OgreParticleEmitter.o \
					../src/OgreParticleIterator.o \
					../src/OgreParticleSystem.o \
					../src/OgreParticleSystemManager.o \
					../src/OgrePass.o \
					../src/OgrePatchMesh.o \
					../src/OgrePatchSurface.o \
					../src/OgrePixelCountLodStrategy.o \
					../src/OgrePixelFormat.o \
					../src/OgrePlane.o \
					../src/OgrePlatformInformation.o \
					../src/OgrePolygon.o \
					../src/OgrePose.o \
					../src/OgrePrecompiledHeaders.o \
					../src/OgrePredefinedControllers.o \
					../src/OgrePrefabFactory.o \
					../src/OgreProfiler.o \
					../src/OgreProgressiveMesh.o \
					../src/OgrePVRTCCodec.o \
					../src/OgreQuaternion.o \
					../src/OgreRectangle2D.o \
					../src/OgreRenderQueue.o \
					../src/OgreRenderQueueInvocation.o \
					../src/OgreRenderQueueSortingGrouping.o \
					../src/OgreRenderSystemCapabilities.o \
					../src/OgreRenderSystemCapabilitiesManager.o \
					../src/OgreRenderSystemCapabilitiesSerializer.o \
					../src/OgreRenderSystem.o \
					../src/OgreRenderTarget.o \
					../src/OgreRenderTexture.o \
					../src/OgreRenderToVertexBuffer.o \
					../src/OgreRenderWindow.o \
					../src/OgreResourceBackgroundQueue.o \
					../src/OgreResource.o \
					../src/OgreResourceGroupManager.o \
					../src/OgreResourceManager.o \
					../src/OgreRibbonTrail.o \
					../src/OgreRoot.o \
					../src/OgreRotationSpline.o \
					../src/OgreSceneManager.o \
					../src/OgreSceneManagerEnumerator.o \
					../src/OgreSceneNode.o \
					../src/OgreSceneQuery.o \
					../src/OgreScriptCompiler.o \
					../src/OgreScriptLexer.o \
					../src/OgreScriptParser.o \
					../src/OgreScriptTranslator.o \
					../src/OgreSearchOps.o \
					../src/OgreSerializer.o \
					../src/OgreShadowCameraSetup.o \
					../src/OgreShadowCameraSetupFocused.o \
					../src/OgreShadowCameraSetupLiSPSM.o \
					../src/OgreShadowCameraSetupPlaneOptimal.o \
					../src/OgreShadowCameraSetupPSSM.o \
					../src/OgreShadowCaster.o \
					../src/OgreShadowTextureManager.o \
					../src/OgreShadowVolumeExtrudeProgram.o \
					../src/OgreSimpleRenderable.o \
					../src/OgreSimpleSpline.o \
					../src/OgreSkeleton.o \
					../src/OgreSkeletonInstance.o \
					../src/OgreSkeletonManager.o \
					../src/OgreSkeletonSerializer.o \
					../src/OgreSmallVector.o \
					../src/OgreStaticGeometry.o \
					../src/OgreStreamSerialiser.o \
					../src/OgreStringConverter.o \
					../src/OgreString.o \
					../src/OgreStringInterface.o \
					../src/OgreStringSerialiser.o \
					../src/OgreSubEntity.o \
					../src/OgreSubMesh.o \
					../src/OgreTagPoint.o \
					../src/OgreTangentSpaceCalc.o \
					../src/OgreTechnique.o \
					../src/OgreTextAreaOverlayElement.o \
					../src/OgreTexture.o \
					../src/OgreTextureManager.o \
					../src/OgreTextureUnitState.o \
					../src/OgreUnifiedHighLevelGpuProgram.o \
					../src/OgreUserObjectBindings.o \
					../src/OgreUTFString.o \
					../src/OgreVector2.o \
					../src/OgreVector3.o \
					../src/OgreVector4.o \
					../src/OgreVertexIndexData.o \
					../src/OgreViewport.o \
					../src/OgreWireBoundingBox.o \
					../src/OgreWorkQueue.o \
					../src/OgreZip.o \
					../src/Threading/OgreDefaultWorkQueueStandard.o \
					../src/OgreFreeImageCodec.o \
#					../src/Threading/OgreDefaultWorkQueueTBB.o \
#					../src/OgreParticleScriptCompiler.o \
#					../src/OgreWindowEventUtilities.o \
#					../src/OSX/macUtils.o \
					../src/OSX/OgreConfigDialog.o \
					../src/OSX/OgreTimer.o \
					../src/WIN32/OgreConfigDialog.o \
					../src/WIN32/OgreErrorDialog.o \
					../src/WIN32/OgreMinGWSupport.o \
					../src/WIN32/OgreTimer.o \
					../src/Android/OgreConfigDialog.o \
					../src/Android/OgreErrorDialog.o \
					../src/Android/OgreTimer.o \
					../src/GLX/OgreConfigDialog.o \
					../src/GLX/OgreErrorDialog.o \
					../src/gtk/OgreConfigDialog.o \
					../src/gtk/OgreErrorDialog.o \
					../src/iOS/OgreConfigDialog.o \
					../src/iOS/OgreErrorDialog.o \
					../src/iOS/OgreTimer.o \
					../src/NaCl/OgreConfigDialog.o \
					../src/NaCl/OgreErrorDialog.o \
					../src/NaCl/OgreTimer.o \



LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
STATICLIBS_DIR = $(COCOS2DX_PATH)/platform/third_party/linux/libraries/lib64
else
STATICLIBS_DIR = $(COCOS2DX_PATH)/platform/third_party/linux/libraries
endif
STATICLIBS = 
#STATICLIBS = $(STATICLIBS_DIR)/libfreetype.a \
				$(STATICLIBS_DIR)/libxml2.a \
				$(STATICLIBS_DIR)/libpng.a \
				$(STATICLIBS_DIR)/libjpeg.a \
				$(STATICLIBS_DIR)/libtiff.a \

SHAREDLIBS = -lglfw -lcurl
#SHAREDLIBS += -Wl,-rpath,$(COCOS2DX_PATH)/platform/third_party/linux/glew-1.7.0/glew-1.7.0/lib
#SHAREDLIBS += -L$(COCOS2DX_PATH)/platform/third_party/linux/glew-1.7.0/glew-1.7.0/lib -lGLEW

#SHAREDLIBS += -lfreetype
#SHAREDLIBS += -lX11 -lXext -lGL -lXrandr -lXxf86vm -lGLU
#SHAREDLIBS += -lXaw -lXt -lSM -lICE
SHAREDLIBS += -lGL -lGLU
SHAREDLIBS += -lfreeimage
SHAREDLIBS += -Wl,-Bsymbolic-functions -lzzip -lz

#debug: SHAREDLIBS += -L$(SDK_PATH)/lib/linux/Debug -lcocos2d -lrt -lz -lcocosdenshion
debug: SHAREDLIBS += -L$(SDK_PATH)/lib/linux/Debug -lrt -lz
debug: SHAREDLIBS += -Wl,-rpath,$(SDK_PATH)/lib/linux/Debug/
debug: $(SO_TARGET)

####### Build rules
$(SO_TARGET): $(SO_OBJECTS) 
	$(CXX) $(CXXFLAGS) $(DEFINES) $(INCLUDES) $(SO_OBJECTS) -shared -o $@ $(SHAREDLIBS) $(STATICLIBS)

####### Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean: 
	rm -f $(SO_OBJECTS) $(SO_TARGET) core

install: $(SO_TARGET)
	cp *.so $(SDK_PATH)/lib/linux/Debug

all : install

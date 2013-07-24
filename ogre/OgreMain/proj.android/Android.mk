LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos_libogremain_static

LOCAL_MODULE_FILENAME := libogremain

LOCAL_CFLAGS += -g
LOCAL_CFLAGS += -fpermissive
LOCAL_CFLAGS += -fexceptions
LOCAL_CFLAGS += -DANDROID
LOCAL_CFLAGS += -D_GLIBCXX_PERMIT_BACKWARD_HASH
LOCAL_CFLAGS += -DOGRE_NONCLIENT_BUILD=1
LOCAL_CFLAGS += -DHAVE_USR_INCLUDE_MALLOC_H

LOCAL_SRC_FILES := \
				   ../src/OgreMemoryAllocatedObject.cpp\
				   ../src/OgreMemoryNedAlloc.cpp\
				   ../src/OgreMemoryNedPooling.cpp\
				   ../src/OgreMemoryTracker.cpp\
				   ../src/OgreAlignedAllocator.cpp\
				   ../src/OgreAnimable.cpp\
				   ../src/OgreAnimation.cpp\
				   ../src/OgreAnimationState.cpp\
				   ../src/OgreAnimationTrack.cpp\
				   ../src/OgreArchiveManager.cpp\
				   ../src/OgreAutoParamDataSource.cpp\
				   ../src/OgreAxisAlignedBox.cpp\
				   ../src/OgreBillboard.cpp\
				   ../src/OgreBillboardChain.cpp\
				   ../src/OgreBillboardParticleRenderer.cpp\
				   ../src/OgreBillboardSet.cpp\
				   ../src/OgreBone.cpp\
				   ../src/OgreBorderPanelOverlayElement.cpp\
				   ../src/OgreCamera.cpp\
				   ../src/OgreCodec.cpp\
				   ../src/OgreColourValue.cpp\
				   ../src/OgreCommon.cpp\
				   ../src/OgreCompositionPass.cpp\
				   ../src/OgreCompositionTargetPass.cpp\
				   ../src/OgreCompositionTechnique.cpp\
				   ../src/OgreCompositor.cpp\
				   ../src/OgreCompositorChain.cpp\
				   ../src/OgreCompositorInstance.cpp\
				   ../src/OgreCompositorManager.cpp\
				   ../src/OgreConfigFile.cpp\
				   ../src/OgreControllerManager.cpp\
				   ../src/OgreConvexBody.cpp\
				   ../src/OgreDataStream.cpp\
				   ../src/OgreDDSCodec.cpp\
				   ../src/OgreDefaultHardwareBufferManager.cpp\
				   ../src/OgreDefaultSceneQueries.cpp\
				   ../src/OgreDeflate.cpp\
				   ../src/OgreDepthBuffer.cpp\
				   ../src/OgreDistanceLodStrategy.cpp\
				   ../src/OgreDualQuaternion.cpp\
				   ../src/OgreDynLib.cpp\
				   ../src/OgreDynLibManager.cpp\
				   ../src/OgreEdgeListBuilder.cpp\
				   ../src/OgreEntity.cpp\
				   ../src/OgreException.cpp\
				   ../src/OgreExternalTextureSource.cpp\
				   ../src/OgreExternalTextureSourceManager.cpp\
				   ../src/OgreFileSystem.cpp\
				   ../src/OgreFont.cpp\
				   ../src/OgreFontManager.cpp\
				   ../src/OgreFrustum.cpp\
				   ../src/OgreGpuProgram.cpp\
				   ../src/OgreGpuProgramManager.cpp\
				   ../src/OgreGpuProgramParams.cpp\
				   ../src/OgreGpuProgramUsage.cpp\
				   ../src/OgreHardwareBufferManager.cpp\
				   ../src/OgreHardwareIndexBuffer.cpp\
				   ../src/OgreHardwareOcclusionQuery.cpp\
				   ../src/OgreHardwarePixelBuffer.cpp\
				   ../src/OgreHardwareVertexBuffer.cpp\
				   ../src/OgreHighLevelGpuProgram.cpp\
				   ../src/OgreHighLevelGpuProgramManager.cpp\
				   ../src/OgreImage.cpp\
				   ../src/OgreInstanceBatch.cpp\
				   ../src/OgreInstanceBatchHW.cpp\
				   ../src/OgreInstanceBatchHW_VTF.cpp\
				   ../src/OgreInstanceBatchShader.cpp\
				   ../src/OgreInstanceBatchVTF.cpp\
				   ../src/OgreInstancedEntity.cpp\
				   ../src/OgreInstancedGeometry.cpp\
				   ../src/OgreInstanceManager.cpp\
				   ../src/OgreKeyFrame.cpp\
				   ../src/OgreLight.cpp\
				   ../src/OgreLodStrategy.cpp\
				   ../src/OgreLodStrategyManager.cpp\
				   ../src/OgreLog.cpp\
				   ../src/OgreLogManager.cpp\
				   ../src/OgreManualObject.cpp\
				   ../src/OgreMaterial.cpp\
				   ../src/OgreMaterialManager.cpp\
				   ../src/OgreMaterialSerializer.cpp\
				   ../src/OgreMath.cpp\
				   ../src/OgreMatrix3.cpp\
				   ../src/OgreMatrix4.cpp\
				   ../src/OgreMesh.cpp\
				   ../src/OgreMeshManager.cpp\
				   ../src/OgreMeshSerializer.cpp\
				   ../src/OgreMeshSerializerImpl.cpp\
				   ../src/OgreMovableObject.cpp\
				   ../src/OgreMovablePlane.cpp\
				   ../src/OgreNode.cpp\
				   ../src/OgreNumerics.cpp\
				   ../src/OgreOptimisedUtil.cpp\
				   ../src/OgreOptimisedUtilGeneral.cpp\
				   ../src/OgreOptimisedUtilSSE.cpp\
				   ../src/OgreOverlay.cpp\
				   ../src/OgreOverlayContainer.cpp\
				   ../src/OgreOverlayElement.cpp\
				   ../src/OgreOverlayElementCommands.cpp\
				   ../src/OgreOverlayElementFactory.cpp\
				   ../src/OgreOverlayManager.cpp\
				   ../src/OgrePanelOverlayElement.cpp\
				   ../src/OgreParticle.cpp\
				   ../src/OgreParticleEmitter.cpp\
				   ../src/OgreParticleEmitterCommands.cpp\
				   ../src/OgreParticleIterator.cpp\
				   ../src/OgreParticleSystem.cpp\
				   ../src/OgreParticleSystemManager.cpp\
				   ../src/OgrePass.cpp\
				   ../src/OgrePatchMesh.cpp\
				   ../src/OgrePatchSurface.cpp\
				   ../src/OgrePixelCountLodStrategy.cpp\
				   ../src/OgrePixelFormat.cpp\
				   ../src/OgrePlane.cpp\
				   ../src/OgrePlatformInformation.cpp\
				   ../src/OgrePolygon.cpp\
				   ../src/OgrePose.cpp\
				   ../src/OgrePrecompiledHeaders.cpp\
				   ../src/OgrePredefinedControllers.cpp\
				   ../src/OgrePrefabFactory.cpp\
				   ../src/OgreProfiler.cpp\
				   ../src/OgreProgressiveMesh.cpp\
				   ../src/OgrePVRTCCodec.cpp\
				   ../src/OgreQuaternion.cpp\
				   ../src/OgreRectangle2D.cpp\
				   ../src/OgreRenderQueue.cpp\
				   ../src/OgreRenderQueueInvocation.cpp\
				   ../src/OgreRenderQueueSortingGrouping.cpp\
				   ../src/OgreRenderSystem.cpp\
				   ../src/OgreRenderSystemCapabilities.cpp\
				   ../src/OgreRenderSystemCapabilitiesManager.cpp\
				   ../src/OgreRenderSystemCapabilitiesSerializer.cpp\
				   ../src/OgreRenderTarget.cpp\
				   ../src/OgreRenderTexture.cpp\
				   ../src/OgreRenderToVertexBuffer.cpp\
				   ../src/OgreRenderWindow.cpp\
				   ../src/OgreResource.cpp\
				   ../src/OgreResourceBackgroundQueue.cpp\
				   ../src/OgreResourceGroupManager.cpp\
				   ../src/OgreResourceManager.cpp\
				   ../src/OgreRibbonTrail.cpp\
				   ../src/OgreRoot.cpp\
				   ../src/OgreRotationSpline.cpp\
				   ../src/OgreSceneManager.cpp\
				   ../src/OgreSceneManagerEnumerator.cpp\
				   ../src/OgreSceneNode.cpp\
				   ../src/OgreSceneQuery.cpp\
				   ../src/OgreScriptCompiler.cpp\
				   ../src/OgreScriptLexer.cpp\
				   ../src/OgreScriptParser.cpp\
				   ../src/OgreScriptTranslator.cpp\
				   ../src/OgreSearchOps.cpp\
				   ../src/OgreSerializer.cpp\
				   ../src/OgreShadowCameraSetup.cpp\
				   ../src/OgreShadowCameraSetupFocused.cpp\
				   ../src/OgreShadowCameraSetupLiSPSM.cpp\
				   ../src/OgreShadowCameraSetupPlaneOptimal.cpp\
				   ../src/OgreShadowCameraSetupPSSM.cpp\
				   ../src/OgreShadowCaster.cpp\
				   ../src/OgreShadowTextureManager.cpp\
				   ../src/OgreShadowVolumeExtrudeProgram.cpp\
				   ../src/OgreSimpleRenderable.cpp\
				   ../src/OgreSimpleSpline.cpp\
				   ../src/OgreSkeleton.cpp\
				   ../src/OgreSkeletonInstance.cpp\
				   ../src/OgreSkeletonManager.cpp\
				   ../src/OgreSkeletonSerializer.cpp\
				   ../src/OgreSmallVector.cpp\
				   ../src/OgreStaticGeometry.cpp\
				   ../src/OgreStreamSerialiser.cpp\
				   ../src/OgreString.cpp\
				   ../src/OgreStringConverter.cpp\
				   ../src/OgreStringInterface.cpp\
				   ../src/OgreSubEntity.cpp\
				   ../src/OgreSubMesh.cpp\
				   ../src/OgreTagPoint.cpp\
				   ../src/OgreTangentSpaceCalc.cpp\
				   ../src/OgreTechnique.cpp\
				   ../src/OgreTextAreaOverlayElement.cpp\
				   ../src/OgreTexture.cpp\
				   ../src/OgreTextureManager.cpp\
				   ../src/OgreTextureUnitState.cpp\
				   ../src/OgreUnifiedHighLevelGpuProgram.cpp\
				   ../src/OgreUserObjectBindings.cpp\
				   ../src/OgreUTFString.cpp\
				   ../src/OgreVector2.cpp\
				   ../src/OgreVector3.cpp\
				   ../src/OgreVector4.cpp\
				   ../src/OgreVertexIndexData.cpp\
				   ../src/OgreViewport.cpp\
				   ../src/OgreWireBoundingBox.cpp\
				   ../src/OgreWorkQueue.cpp\
				   ../src/OgreZip.cpp\
				   ../src/OgreStringSerialiser.cpp\
				   ../src/Android/OgreAndroidLogListener.cpp \
				   ../src/Android/OgreAPKFileSystemArchive.cpp \
				   ../src/Android/OgreAPKZipArchive.cpp \
				   ../src/Android/OgreConfigDialog.cpp \
				   ../src/Android/OgreErrorDialog.cpp \
				   ../src/Android/OgreFileSystemLayer.cpp \
				   ../src/Android/OgreTimer.cpp \
				   ../src/Threading/OgreDefaultWorkQueueStandard.cpp\
				   ../src/OgreFreeImageCodec.cpp\
#				   ../src/OgreWindowEventUtilities.cpp\


LOCAL_EXPORT_LDLIBS := -llog\
						-lz \
						-lGLESv2 \
#					   -lEGL

LOCAL_EXPORT_LDLIBS += -landroid

SDK_PATH = ../../..
COCOS2DX_PATH = $(SDK_PATH)/cocos2dx
LOCAL_C_INCLUDES := $(LOCAL_PATH) 
DEPENDENCIES_PATH:= $(LOCAL_PATH)/../../dependencies
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../extensions
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Build
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../include/GLX
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../src/nedmalloc
LOCAL_C_INCLUDES += $(COCOS2DX_PATH)/platform/third_party/linux/libfreetype2
LOCAL_C_INCLUDES += $(DEPENDENCIES_PATH)/libfreeimage/include
LOCAL_C_INCLUDES += $(DEPENDENCIES_PATH)/libzzip/include
LOCAL_C_INCLUDES += $(DEPENDENCIES_PATH)/libfreetype/include

LOCAL_WHOLE_STATIC_LIBRARIES := libzzip
LOCAL_WHOLE_STATIC_LIBRARIES += libfreeimage
LOCAL_WHOLE_STATIC_LIBRARIES += libfreetype

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

include $(BUILD_STATIC_LIBRARY)

#$(call import-add-path, $(LOCAL_PATH)/libs)
$(call import-add-path, $(LOCAL_PATH)/../../dependencies)

#$(call import-module,cocos2dx)
#$(call import-module,libiconv)
$(call import-module,libfreeimage)
$(call import-module,libzzip)
$(call import-module,libfreetype)

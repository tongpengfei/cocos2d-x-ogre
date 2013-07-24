LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos_libogrerender_static

LOCAL_MODULE_FILENAME := libogrerender

LOCAL_CFLAGS += -g
LOCAL_CFLAGS += -fpermissive
LOCAL_CFLAGS += -fexceptions
LOCAL_CFLAGS += -frtti
LOCAL_CFLAGS += -DANDROID
LOCAL_CFLAGS += -D_GLIBCXX_PERMIT_BACKWARD_HASH


LOCAL_SRC_FILES := \
				   ../GLES2/src/OgreGLES2Context.cpp\
				   ../GLES2/src/OgreGLES2DefaultHardwareBufferManager.cpp\
				   ../GLES2/src/OgreGLES2DepthBuffer.cpp\
				   ../GLES2/src/OgreGLES2EngineDll.cpp\
				   ../GLES2/src/OgreGLES2FBOMultiRenderTarget.cpp\
				   ../GLES2/src/OgreGLES2FBORenderTexture.cpp\
				   ../GLES2/src/OgreGLES2FrameBufferObject.cpp\
				   ../GLES2/src/OgreGLES2GpuProgram.cpp\
				   ../GLES2/src/OgreGLES2GpuProgramManager.cpp\
				   ../GLES2/src/OgreGLES2HardwareBufferManager.cpp\
				   ../GLES2/src/OgreGLES2HardwareIndexBuffer.cpp\
				   ../GLES2/src/OgreGLES2HardwareOcclusionQuery.cpp\
				   ../GLES2/src/OgreGLES2HardwarePixelBuffer.cpp\
				   ../GLES2/src/OgreGLES2HardwareVertexBuffer.cpp\
				   ../GLES2/src/OgreGLES2PixelFormat.cpp\
				   ../GLES2/src/OgreGLES2Plugin.cpp\
				   ../GLES2/src/OgreGLES2RenderSystem.cpp\
				   ../GLES2/src/OgreGLES2RenderTexture.cpp\
				   ../GLES2/src/OgreGLES2Support.cpp\
				   ../GLES2/src/OgreGLES2Texture.cpp\
				   ../GLES2/src/OgreGLES2TextureManager.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESExtSupport.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESGpuProgram.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESLinkProgram.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESLinkProgramManager.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESProgramCommon.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESPreprocessor.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESProgram.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESProgramFactory.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESProgramManagerCommon.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESProgramPipeline.cpp\
				   ../GLES2/src/GLSLES/src/OgreGLSLESProgramPipelineManager.cpp\
				   ../GLES2/src/Android/OgreAndroidGLContext.cpp\
				   ../GLES2/src/Android/OgreAndroidGLSupport.cpp\
				   ../GLES2/src/Android/OgreAndroidWindow.cpp\



LOCAL_EXPORT_LDLIBS := -llog\
						-lz \
						-lGLESv2 \
#						-lEGL

SDK_PATH = ../../..
COCOS2DX_PATH = $(SDK_PATH)/cocos2dx
LOCAL_C_INCLUDES := $(LOCAL_PATH) 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../OgreMain/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../GLES2/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../GLES2/include/Android
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../GLES2/src/GLSLES/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../GLES2/src/GLSLES/include/Android

#LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_libogremain_static

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

include $(BUILD_STATIC_LIBRARY)

#$(call import-add-path, $(LOCAL_PATH)/libs)

#$(call import-module,cocos2dx)
$(call import-module,ogre/OgreMain/proj.android)

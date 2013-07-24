LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos_libogrecomponents_static

LOCAL_MODULE_FILENAME := libogrecomponents

LOCAL_CFLAGS += -g
LOCAL_CFLAGS += -fpermissive
LOCAL_CFLAGS += -fexceptions
LOCAL_CFLAGS += -frtti
LOCAL_CFLAGS += -DANDROID
LOCAL_CFLAGS += -D_GLIBCXX_PERMIT_BACKWARD_HASH


LOCAL_SRC_FILES := \
					../RTShaderSystem/src/OgreShaderCGProgramProcessor.cpp \
					../RTShaderSystem/src/OgreShaderCGProgramWriter.cpp \
					../RTShaderSystem/src/OgreShaderExDualQuaternionSkinning.cpp \
					../RTShaderSystem/src/OgreShaderExHardwareSkinning.cpp \
					../RTShaderSystem/src/OgreShaderExHardwareSkinningTechnique.cpp \
					../RTShaderSystem/src/OgreShaderExIntegratedPSSM3.cpp \
					../RTShaderSystem/src/OgreShaderExLayeredBlending.cpp \
					../RTShaderSystem/src/OgreShaderExLinearSkinning.cpp \
					../RTShaderSystem/src/OgreShaderExNormalMapLighting.cpp \
					../RTShaderSystem/src/OgreShaderExPerPixelLighting.cpp \
					../RTShaderSystem/src/OgreShaderExTextureAtlasSampler.cpp \
					../RTShaderSystem/src/OgreShaderFFPColour.cpp \
					../RTShaderSystem/src/OgreShaderFFPFog.cpp \
					../RTShaderSystem/src/OgreShaderFFPLighting.cpp \
					../RTShaderSystem/src/OgreShaderFFPRenderStateBuilder.cpp \
					../RTShaderSystem/src/OgreShaderFFPTexturing.cpp \
					../RTShaderSystem/src/OgreShaderFFPTransform.cpp \
					../RTShaderSystem/src/OgreShaderFunctionAtom.cpp \
					../RTShaderSystem/src/OgreShaderFunction.cpp \
					../RTShaderSystem/src/OgreShaderGenerator.cpp \
					../RTShaderSystem/src/OgreShaderGLSLESProgramProcessor.cpp \
					../RTShaderSystem/src/OgreShaderGLSLESProgramWriter.cpp \
					../RTShaderSystem/src/OgreShaderGLSLProgramProcessor.cpp \
					../RTShaderSystem/src/OgreShaderGLSLProgramWriter.cpp \
					../RTShaderSystem/src/OgreShaderHLSLProgramProcessor.cpp \
					../RTShaderSystem/src/OgreShaderHLSLProgramWriter.cpp \
					../RTShaderSystem/src/OgreShaderMaterialSerializerListener.cpp \
					../RTShaderSystem/src/OgreShaderParameter.cpp \
					../RTShaderSystem/src/OgreShaderProgram.cpp \
					../RTShaderSystem/src/OgreShaderProgramManager.cpp \
					../RTShaderSystem/src/OgreShaderProgramProcessor.cpp \
					../RTShaderSystem/src/OgreShaderProgramSet.cpp \
					../RTShaderSystem/src/OgreShaderProgramWriter.cpp \
					../RTShaderSystem/src/OgreShaderProgramWriterManager.cpp \
					../RTShaderSystem/src/OgreShaderRenderState.cpp \
					../RTShaderSystem/src/OgreShaderScriptTranslator.cpp \
					../RTShaderSystem/src/OgreShaderSubRenderState.cpp \
					../RTShaderSystem/src/RTShaderHelper.cpp \


LOCAL_EXPORT_LDLIBS := -llog\
						-lz \
						-lGLESv2 \
#						-lEGL

SDK_PATH = ../../..
COCOS2DX_PATH = $(SDK_PATH)/cocos2dx
LOCAL_C_INCLUDES := $(LOCAL_PATH) 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../OgreMain/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../RTShaderSystem/include

#LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_libogremain_static

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

include $(BUILD_STATIC_LIBRARY)

#$(call import-add-path, $(LOCAL_PATH)/libs)

#$(call import-module,cocos2dx)
$(call import-module,ogre/OgreMain/proj.android)

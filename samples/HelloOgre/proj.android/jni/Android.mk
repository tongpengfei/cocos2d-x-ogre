LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hellocpp_shared

LOCAL_CFLAGS += -g
LOCAL_CFLAGS += -fpermissive
LOCAL_CFLAGS += -fexceptions
LOCAL_CFLAGS += -DDEBUG
LOCAL_CFLAGS += -DANDROID
LOCAL_CFLAGS += -DLOG_TRACE
LOCAL_CFLAGS += -D_GLIBCXX_PERMIT_BACKWARD_HASH
#NDK_TOOLCHAIN_VERSION:=4.4.3

LOCAL_MODULE_FILENAME := libhellocpp

SDK_PATH := ../../../..
COCOS2DX_PATH := $(SDK_PATH)/cocos2dx
OGREMAIN_PATH := $(SDK_PATH)/ogre/OgreMain

LOCAL_SRC_FILES := hellocpp/main.cpp \
					../../Classes/AppDelegate.cpp \
					../../Classes/helloogre.cpp \
					../../Classes/ogreapp.cpp \
#					../../Classes/skybox.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../ogre/OgreMain/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../ogre/components/RTShaderSystem/include
LOCAL_C_INCLUDES += /home/tpf/company/code/libcocos2dx/public/tui
#LOCAL_C_INCLUDES += $(NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.6/include/backward/
#LOCAL_C_INCLUDES += /home/tpf/tool/android-ndk-r8b/sources/cxx-stl/gnu-libstdc++/4.6/include

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static 
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_libogremain_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_libogrerender_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_libogrecomponents_static

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, $(LOCAL_PATH)/$(SDK_PATH)/cocos2dx/platform/third_party/android/prebuilt)\

$(call import-module,CocosDenshion/android)
$(call import-module,cocos2dx)
$(call import-module,extensions)
$(call import-module,ogre/OgreMain/proj.android)
$(call import-module,ogre/RenderSystems/proj.android)
$(call import-module,ogre/components/proj.android)
#$(call import-module,public/proj.android)

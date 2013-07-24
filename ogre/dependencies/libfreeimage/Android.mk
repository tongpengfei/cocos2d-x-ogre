LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libfreeimage
LOCAL_MODULE_FILENAME := libfreeimage
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/libFreeImage.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

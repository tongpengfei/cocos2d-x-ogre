LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libfreetype
LOCAL_MODULE_FILENAME := freetype
LOCAL_SRC_FILES := library/$(TARGET_ARCH_ABI)/libfreetype.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

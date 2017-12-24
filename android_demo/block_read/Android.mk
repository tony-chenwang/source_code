LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := blockread

LOCAL_SRC_FILES := \
    Block.cpp

LOCAL_C_INCLUDES := \
    $(TOP)/bionic/libc/include/\

LOCAL_SHARED_LIBRARIES :=  libutils liblog libcutils 

include $(BUILD_EXECUTABLE)
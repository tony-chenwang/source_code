LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := sysconf

LOCAL_SRC_FILES := \
    sysconf.cpp

LOCAL_C_INCLUDES := \
    $(TOP)/bionic/libc/include/

LOCAL_SHARED_LIBRARIES :=  libutils  libcutils liblog

include $(BUILD_EXECUTABLE)
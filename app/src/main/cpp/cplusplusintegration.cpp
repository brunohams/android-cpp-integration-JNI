#include <iostream>
#include <jni.h>
#include <memory>
#include "include/Calculator.h"
#include <android/log.h>

#define  LOG_TAG    "testjni"
#define  ALOG(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

extern "C" {
    JNIEXPORT jlong JNICALL
    Java_com_example_cplusplusintegration_NativeCalculator_create(JNIEnv *env, jobject thiz) {

        auto calculator = std::make_unique<calculator::Calculator>();

        if (not calculator) {
            ALOG("Failed to create the calculator.");
            calculator.reset(nullptr);
        }

        return reinterpret_cast<jlong>(calculator.release());
    }

    JNIEXPORT void JNICALL
    Java_com_example_cplusplusintegration_NativeCalculator_delete(JNIEnv *env, jobject thiz,
                                                                  jlong calculator_handle) {
        auto* calculator = reinterpret_cast<calculator::Calculator*>(calculator_handle);

        if (not calculator) {
            ALOG("Attempt to destroy an unitialized calculator.");
            return;
        }

        delete calculator;
    }

    JNIEXPORT jint JNICALL
    Java_com_example_cplusplusintegration_NativeCalculator_sum(JNIEnv *env, jobject thiz,
                                                               jlong calculator_handle, jint first,
                                                               jint second) {
        auto* calculator = reinterpret_cast<calculator::Calculator*>(calculator_handle);

        if (calculator) {
            return calculator->sum(static_cast<int>(first), static_cast<int>(second));
        } else {
            ALOG("Failed to execute sum, the calculator is not created");
        }

        return -1;
    }

    JNIEXPORT jint JNICALL
    Java_com_example_cplusplusintegration_NativeCalculator_minus(JNIEnv *env, jobject thiz,
                                                                 jlong calculator_handle, jint first,
                                                                 jint second) {
        auto* calculator = reinterpret_cast<calculator::Calculator*>(calculator_handle);

        if (calculator) {
            return calculator->minus(static_cast<int>(first), static_cast<int>(second));
        } else {
            ALOG("Failed to execute sum, the calculator is not created");
        }

        return -1;
    }

    JNIEXPORT jint JNICALL
    Java_com_example_cplusplusintegration_NativeCalculator_times(JNIEnv *env, jobject thiz,
                                                                 jlong calculator_handle, jint first,
                                                                 jint second) {
        auto* calculator = reinterpret_cast<calculator::Calculator*>(calculator_handle);

        if (calculator) {
            return calculator->times(static_cast<int>(first), static_cast<int>(second));
        } else {
            ALOG("Failed to execute sum, the calculator is not created");
        }

        return -1;
    }

    JNIEXPORT jint JNICALL
    Java_com_example_cplusplusintegration_NativeCalculator_divide(JNIEnv *env, jobject thiz,
                                                                  jlong calculator_handle, jint first,
                                                                  jint second) {
        auto* calculator = reinterpret_cast<calculator::Calculator*>(calculator_handle);

        if (calculator) {
            return calculator->divide(static_cast<int>(first), static_cast<int>(second));
        } else {
            ALOG("Failed to execute sum, the calculator is not created");
        }

        return -1;
    }
}

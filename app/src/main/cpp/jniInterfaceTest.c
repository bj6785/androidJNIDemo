//
// Created by kai.l on 3/22/2021.
//
#include "debug.h"
#include "jniInterfaceTest.h"
JNIEXPORT jint JNICALL Java_com_example_jnidemo_JniInterfaceTest_jniInterface1(
        JNIEnv *env, jobject clazz, jint num) {

    ALOGI("%s", "hello world");
    ALOGE("%s", "hello world");
    return 0;
}

JNIEXPORT jstring JNICALL Java_com_example_jnidemo_JniInterfaceTest_jniInterface2(
        JNIEnv *env, jobject clazz, jstring str) {

    return (*env)->NewStringUTF(env, "abc");
}

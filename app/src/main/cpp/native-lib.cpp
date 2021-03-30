#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    __android_log_print(ANDROID_LOG_INFO, "native", "stringFromJni in c native code./n");
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


#define NELEM(x)    (sizeof(x)/sizeof(x[0]))

JNIEXPORT jstring JNICALL
native_hello(JNIEnv *env, jclass clazz, jstring str)
{
    __android_log_print(ANDROID_LOG_INFO, "native", "hello() in c native code./n");
    __android_log_print(ANDROID_LOG_INFO, "native", "input param:%s./n", str);
    return str;
}

JNIEXPORT jstring JNICALL
native_world(JNIEnv *env, jclass clazz, jstring str)
{
    __android_log_print(ANDROID_LOG_INFO, "native", "world() in c native code./n");
    __android_log_print(ANDROID_LOG_INFO, "native", "input param:%s./n", str);
    return str;
}


JNIEXPORT void JNICALL
native_setStudent(JNIEnv *env, jclass clazz, jobject std)
{
    __android_log_print(ANDROID_LOG_INFO, "native", "setStudent() in c native code./n");
    jclass stu_jclass = env->GetObjectClass(std);
    jmethodID stu_methord_id = env->GetMethodID(stu_jclass, "getName", "()Ljava/lang/String;");
    jstring name = static_cast<jstring>(env->CallObjectMethod(std, stu_methord_id));
    const char * nameStr = env->GetStringUTFChars(name, JNI_FALSE);

    __android_log_print(ANDROID_LOG_INFO, "native", "method = %s, msg = %s\n",__FUNCTION__, nameStr);
    env->ReleaseStringUTFChars(name, nameStr);

}


/*****************************************************************************************************/
// 指定要注册的类
#define JNIREG_CLASS "com/example/jnidemo/MainActivity"

// 定义一个JNINativeMethod数组，其中的成员就是Java代码中对应的native方法
static JNINativeMethod gMethods[] = {
        { "hello", "(Ljava/lang/String;)Ljava/lang/String;", (void*)native_hello},
        { "world", "(Ljava/lang/String;)Ljava/lang/String;", (void*)native_world},
        { "setStudent", "(Ljava/lang/Object;)V", (void*)native_setStudent},
};

static int registerNativeMethods(JNIEnv* env, const char* className,
                                 JNINativeMethod* gMethods, int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

/***
 * 注册native方法
 */
static int registerNatives(JNIEnv* env) {
    if (!registerNativeMethods(env, JNIREG_CLASS, gMethods, NELEM(gMethods))) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

/**
 * 如果要实现动态注册，这个方法一定要实现
 * 动态注册工作在这里进行
 */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env = NULL;
    jint result = -1;
    __android_log_print(ANDROID_LOG_INFO, "native", "Jni_OnLoad");

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);

    if (!registerNatives(env)) { //注册
        return -1;
    }
    result = JNI_VERSION_1_6;
    return result;
}

JNIEXPORT void JNI_OnUnload(JavaVM* vm, void* reserved){
    __android_log_print(ANDROID_LOG_INFO, "native", "JNI_OnUnload");
}


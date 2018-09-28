#include <jni.h>
#include <string>
#include "TestClass.h"

extern "C" JNIEXPORT jstring

JNICALL
Java_bzh_buno_nativeapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
static TestClass *testClass = NULL;

extern "C" {
JNIEXPORT jstring Java_bzh_buno_nativeapp_MainActivity_stringFromCplus(
        JNIEnv *env,
        jobject /* this */,
        jstring input) {
    testClass = new TestClass();
    const char *msg = env->GetStringUTFChars(input, JNI_FALSE);
    std::string hello = testClass->getHelloString(msg);
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jobjectArray JNICALL Java_bzh_buno_nativeapp_MainActivity_arrayFromCplus(
        JNIEnv *env,
        jobject /* this */) {
    jobjectArray result;
    result = (jobjectArray)env->NewObjectArray(3,env->FindClass("java/lang/String"),env->NewStringUTF(""));
    std::string strings[] = {"Hello", "World", "!!"};
    for(int i=0; i<3; i++) {
        env->SetObjectArrayElement(result,i,env->NewStringUTF(strings[i].c_str()));
    }
    return result;
}
}

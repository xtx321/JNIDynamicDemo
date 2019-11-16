//
// Created by Administrator on 2019/11/14 0014.
//
#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>

//函数声明
jint test(JNIEnv *env, jclass clazz, jint x);

jint sum(JNIEnv *env, jclass clazz, jint a, jint b, jint c);
/**
 * 第一次调用c++中的方法时加载
 * @param vm   JavaVM 是java虚拟机在JNI层的代表, JNI全局中仅仅有一个javaVM结构中封装了一些函数指针(或叫函数表结构),
 *              这些函数指针主要是对JVM的操作接口
 * @param reserved
 * @return
 */
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {

    __android_log_print(ANDROID_LOG_DEBUG, "JNI_TAG", "enter jni_onload");

    JNIEnv *env = NULL;
    jint result = -1;
    //获取JNIEnv,JNIEnv是一个函数表. JNIEnv是当前java线程的执行环境, 一个JVM对应一个JavaVM结构,
    // 而一个JVM可能创建多个java线程,每个线程对应一个JNIEnv结构
    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    //  java层的函数 java层签名信息(参数类型)返回值类型 c++层函数指针
    const JNINativeMethod method[] = {
            {"test", "(I)I",   (void *) test},
            {"sum",  "(III)I", (void *) sum}
    };
    //获取java层类
    jclass jClassName = (*env)->FindClass(env, "com/xtx/jni/JNITest");
    //注册函数表,将java层函数和c++层函数关联起来
    jint ret = (*env)->RegisterNatives(env, jClassName, method, 2);//最后一个参数指定函数表大小

    if (ret != JNI_OK) {
        __android_log_print(ANDROID_LOG_DEBUG, "JNI_TAG", "enter jni register error");
        return -1;
    }

    return JNI_VERSION_1_6;


}


jint test(JNIEnv *env, jclass clazz, jint x) {
    return x + 10;
}

/**
 * 跟java层函数对应
 */
jint sum(JNIEnv *env, jclass clazz, jint a, jint b, jint c) {
    return a + b + c;
}

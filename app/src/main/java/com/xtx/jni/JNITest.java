package com.xtx.jni;

/**
 * Created by TianxinXie on 2019/11/14 0014
 */
public class JNITest {
    static {
        System.loadLibrary("jni_test");
    }

    public static native int test(int x);

    public static native int sum(int a, int b, int c);
}

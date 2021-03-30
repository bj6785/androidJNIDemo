package com.example.jnidemo;

import android.util.Log;

public class JniInterfaceTest {
    static {
        System.loadLibrary("native-lib");
    }

    public void callInter1() {
        Log.d("TAG", "java call Inter1:");
        int jniRet = jniInterface1(10);
        Log.d("TAG", "java return:" + jniRet);
    }

    public void callInter2() {
        Log.d("TAG", "call Inter2");
//        String jniRet = jniInterface2("Hello");
    }

    public native int jniInterface1(int num);

    public native String jniInterface2(String str);



    public static JniInterfaceTest instance = null;
    private JniInterfaceTest() {
    }

    public static JniInterfaceTest getInstance() {
        if (instance == null) {
            instance = new JniInterfaceTest();
        }
        return instance;
    }

}

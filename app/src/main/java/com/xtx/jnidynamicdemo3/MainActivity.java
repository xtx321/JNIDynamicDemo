package com.xtx.jnidynamicdemo3;

import android.os.Bundle;
import android.util.Log;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;

import com.xtx.jni.JNITest;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    public static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.btn1).setOnClickListener(this);
        Log.d(TAG,"onCreate");
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn1:
                test();
                break;

            default:
                break;
        }
    }

    private void test() {
        int test = JNITest.test(10);
        Log.d(TAG, "test=" + test);
        int sum = JNITest.sum(10, 20, 30);
        Log.d(TAG, "sum=" + sum);
    }

}

package com.example.jnidemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private Button jniButton1;
    private JniInterfaceTest jniInterfaceTest = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jniInterfaceTest = JniInterfaceTest.getInstance();

        jniButton1 = findViewById(R.id.jni_test1);
        jniButton1.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.jni_test1:
                jniInterfaceTest.callInter1();
                break;
        }

    }
}
package com.example.huozhenpeng.lametest;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setOnClickListener(new OnClickListener(){

            @Override
            public void onClick(View v) {
                String pcmPath = Environment.getExternalStorageDirectory()+"/ffmpeg.pcm";
                int audioChannels = 2;
                int bitRate = 128 * 1024;
                int sampleRate = 44100;
                String mp3Path =Environment.getExternalStorageDirectory()+"/lame.mp3";
                int ret = init(pcmPath, mp3Path,sampleRate,audioChannels, bitRate);
                if(ret >= 0) {
                    encode();
                    destroy();
                } else {
                }

            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native int init(String pcmPath,String mp3Path,int sampleRate,int audioChannels,int bitRate);
    public native void encode();
    public native void destroy();
}

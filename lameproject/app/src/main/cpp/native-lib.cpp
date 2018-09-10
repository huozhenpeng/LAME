#include <jni.h>
#include <string>

extern "C"
{
#include "lamemp3encoder.h"
}


Mp3Encoder* encoder=NULL;
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_huozhenpeng_lametest_MainActivity_init(JNIEnv *env, jobject instance,
                                                        jstring pcmPath_, jstring mp3Path_,
                                                        jint sampleRate, jint audioChannels,
                                                        jint bitRate) {
    const char *pcmPath = env->GetStringUTFChars(pcmPath_, 0);
    const char *mp3Path = env->GetStringUTFChars(mp3Path_, 0);

    // TODO
    encoder=new Mp3Encoder();
    int ret=encoder->Init(pcmPath,mp3Path,sampleRate,audioChannels,bitRate);

    env->ReleaseStringUTFChars(pcmPath_, pcmPath);
    env->ReleaseStringUTFChars(mp3Path_, mp3Path);
    //坑点，忘记写return值了，运行报错
    return ret;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_huozhenpeng_lametest_MainActivity_encode(JNIEnv *env, jobject instance) {

    // TODO
    encoder->Encode();

}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_huozhenpeng_lametest_MainActivity_destroy(JNIEnv *env, jobject instance) {

    // TODO
    encoder->Destroy();

}
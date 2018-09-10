//
// Created by 霍振鹏 on 2018/9/10.
//

#ifndef LAMEPROJECT_LAMEMP3ENCODER_H
#define LAMEPROJECT_LAMEMP3ENCODER_H

#include "../../../../../../Library/Android/sdk/ndk-bundle/platforms/android-21/arch-mips64/usr/include/stdio.h"

extern "C"
{
#include <android/log.h>
#include "lame/lame.h"
}


class Mp3Encoder {
private:
    FILE *pcmFile;
    FILE *mp3File;
    lame_t lameClient;
public:
    Mp3Encoder();

    ~Mp3Encoder();

    int Init(const char *pcmFilePath, const char *mp3FilePath, int sampleRate, int channels,
             int bitRate);

    void Encode();

    void Destroy();
};

#endif //LAMEPROJECT_LAMEMP3ENCODER_H

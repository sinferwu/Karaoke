#ifndef _AW_JAVA_AUDIO_H_
#define _AW_JAVA_AUDIO_H_

#include "CP_Audio.h"


#include <jni.h>
typedef struct tagANDROID_JAVA_AUDIO_PARAM
{
	JavaVM	*Jvm;
	jclass	Class;
	int		InSampleRate;
	int		OutSampleRate;
	int		InChannels;
	int		OutChannels;
}ANDROID_JAVA_AUDIO_PARAM;

#if 0
typedef enum tagAWJAVA_AUDIO_MODE
{
	AWJAVA_AUDIO_MODE_LEFT_CODEC_RIGHT_CODEC,
	AWJAVA_AUDIO_MODE_LEFT_SPI_RIGHT_SPI,
	AWJAVA_AUDIO_MODE_LEFT_MIXED_RIGHT_MIXED,
	AWJAVA_AUDIO_MODE_LEFT_CODEC_RIGHT_MIXED,
	AWJAVA_AUDIO_MODE_LEFT_SPI_RIGHT_MIXED,
	AWJAVA_AUDIO_MODE_LEFT_MIXED_RIGHT_CODEC,
	AWJAVA_AUDIO_MODE_LEFT_SPI_RIGHT_CODEC,
	AWJAVA_AUDIO_MODE_LEFT_MIXED_RIGHT_SPI,
	AWJAVA_AUDIO_MODE_LEFT_CODEC_RIGHT_SPI,
}AWJAVA_AUDIO_MODE;


typedef enum tagAWJAVA_AUDIO_CMD
{
	AWJAVA_AUDIO_CMD_SET_MODE,
	AWJAVA_AUDIO_CMD_SET_CODEC_LEFT_VOL,
	AWJAVA_AUDIO_CMD_SET_CODEC_RIGHT_VOL,
	AWJAVA_AUDIO_CMD_SET_SPI_LEFT_VOL,
	AWJAVA_AUDIO_CMD_SET_SPI_RIGHT_VOL,
	AWJAVA_AUDIO_CMD_SET_ECHO_VOL,
	AWJAVA_AUDIO_CMD_SET_EQ_100HZ_VOL,
	AWJAVA_AUDIO_CMD_SET_EQ_1KHZ_VOL,
	AWJAVA_AUDIO_CMD_SET_EQ_5KHZ_VOL,
	AWJAVA_AUDIO_CMD_TEST_LATENCY,
	AWJAVA_AUDIO_CMD_GET_LATENCY,
	AWJAVA_AUDIO_CMD_SET_MIC_EN,
	AWJAVA_AUDIO_CMD_GET_SPI_STATUS,
	AWJAVA_AUDIO_CMD_SET_BBE_EN,
	AWJAVA_AUDIO_CMD_SET_ECHO_DELAY,
	AWJAVA_AUDIO_CMD_SET_BBE_LEVEL,
	AWJAVA_AUDIO_CMD_GET_CODEC_LEFT_VPP,
	AWJAVA_AUDIO_CMD_GET_CODEC_RIGHT_VPP,
	AWJAVA_AUDIO_CMD_GET_SPI_LEFT_VPP,
	AWJAVA_AUDIO_CMD_GET_SPI_RIGHT_VPP,
	AWJAVA_AUDIO_CMD_SELECT_INPUT,
	AWJAVA_AUDIO_CMD_SET_TIME_START,
	AWJAVA_AUDIO_CMD_SET_TIME_DURATION,
	AWJAVA_AUDIO_CMD_SET_TIME_TEMPO,
	AWJAVA_AUDIO_CMD_SET_AGC_ENABLE,
	AWJAVA_AUDIO_CMD_SET_AGC_GAIN,
	AWJAVA_AUDIO_CMD_SET_AGC_TARGET,
	AWJAVA_AUDIO_CMD_SET_NOISE_AVOID,
}AWJAVA_AUDIO_CMD;
#endif

#if defined(__cplusplus)
extern "C" {
#endif


	int AWJavaAudio_Set (AUDIO_HANDLE Handle, int Cmd, int Data);

	AUDIO_IN_HANDLE AWJavaAudioIn_Open (AUDIO_HANDLE Handle, AUDIO_PARAM *Param);
	long AWJavaAudioIn_Close (AUDIO_IN_HANDLE Handle);
	long AWJavaAudioIn_Read (AUDIO_IN_HANDLE Handle, void *BufAddr, unsigned long Size);

	AUDIO_OUT_HANDLE AWJavaAudioOut_Open (AUDIO_HANDLE Handle, AUDIO_PARAM *Param);
	long AWJavaAudioOut_Close (AUDIO_OUT_HANDLE Handle);
	long AWJavaAudioOut_Write (AUDIO_OUT_HANDLE Handle, void *BufAddr, unsigned long Size);

	AUDIO_HANDLE AWJavaAudio_Init (ANDROID_JAVA_AUDIO_PARAM *Param);
	int AWJavaAudio_Finish (AUDIO_HANDLE Handle);

#if defined(__cplusplus)
}
#endif

#endif



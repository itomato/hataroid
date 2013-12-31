#ifndef __HATAROID_H__
#define __HATAROID_H__

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern void Debug_Printf(const char *a_pszformat, ...);
extern void usleep(int usecs);
extern int hasDialogResult();
extern int getDialogResult();
extern void clearDialogResult();

extern JavaVM *g_jvm;

struct JNIAudio
{
	JNIEnv *android_env;
	jobject android_mainActivity;

	jmethodID initAudio;
	jmethodID deinitAudio;
	jmethodID sendAudio;
	jmethodID pauseAudio;
	jmethodID playAudio;
};

struct JNIMainMethodCache
{
	JNIEnv *android_env;
	jobject android_mainActivity;

	JNIEnv *android_mainEmuThreadEnv;
	jmethodID showGenericDialog;
	jmethodID showOptionsDialog;
	jmethodID quitHataroid;
};

extern struct JNIAudio g_jniAudioInterface;

extern void showGenericDialog(const char *message, int ok, int noyes);
extern void showOptionsDialog();
extern int hasEmuCommands();
extern void processEmuCommands();
extern void clearEmuCommands();
extern void RequestAndWaitQuit();


#ifdef __cplusplus
};  /* end of extern "C" */
#endif /* __cplusplus */

#endif //__HATAROID_H__
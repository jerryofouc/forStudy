#include<stdio.h>
#include<jni.h>
#include"HelloWorld.h"
JNIEXPORT void JNICALL
	Java_HelloWorld_print(JNIEnv *env, jobject obj){
	printf("Hello World!\n");
	return;
}

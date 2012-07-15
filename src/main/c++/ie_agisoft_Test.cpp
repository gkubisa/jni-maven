#include <jni.h>
#include <stdio.h>
#include "ie_agisoft_Test.h"

JNIEXPORT void JNICALL Java_ie_agisoft_Test_hello(JNIEnv *, jobject) {
	printf("Hello World\n");
#ifdef __cplusplus
	printf("__cplusplus is defined\n");
#else
	printf("__cplusplus is NOT defined\n");
#endif
	return;
}

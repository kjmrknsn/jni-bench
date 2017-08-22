#include "jnibench_Jni.h"

JNIEXPORT jbyteArray JNICALL Java_jnibench_Jni_copy(JNIEnv *env, jobject obj, jbyteArray in) {
    jsize n = env->GetArrayLength(in);
    jbyteArray out = env->NewByteArray(n);
    jbyte *outElements = env->GetByteArrayElements(out, 0);
    jbyte *inElements = env->GetByteArrayElements(in, 0);
    for (int i = 0; i < n; i++) {
        outElements[i] = inElements[i];
    }
    env->ReleaseByteArrayElements(in, inElements, 0);
    env->ReleaseByteArrayElements(out, outElements, 0);
    return out;
}

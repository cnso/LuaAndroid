#include <jni.h>
#include <unistd.h>
JNIEXPORT jint JNICALL
Java_com_jash_luaandroid_MainActivity_getId(JNIEnv *env, jobject instance) {
    return 1;

}

extern "C"
jstring
Java_com_jash_luaandroid_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject instance) {
//    jmethodID methodID = env->GetMethodID(env->GetObjectClass(instance), "getFilesDir", "()Ljava/io/File;");
//    jobject file = env->CallObjectMethod(instance, methodID);
//    methodID = env->GetMethodID(env->GetObjectClass(file), "getAbsolutePath", "()Ljava/lang/String;");
//    jstring path = (jstring) env->CallObjectMethod(file, methodID);
//    chdir(env->GetStringUTFChars(path, JNI_FALSE));
//    char buf[50];
//    getcwd(buf, sizeof(buf));
    return env->NewStringUTF("cplusplus");
}

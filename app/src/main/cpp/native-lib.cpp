#include <jni.h>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include <unistd.h>
extern "C"
jint
Java_com_jash_luaandroid_MainActivity_getId(JNIEnv *env, jobject instance) {
    jmethodID methodID = env->GetMethodID(env->GetObjectClass(instance), "getFilesDir", "()Ljava/io/File;");
    jobject file = env->CallObjectMethod(instance, methodID);
    methodID = env->GetMethodID(env->GetObjectClass(file), "getAbsolutePath", "()Ljava/lang/String;");
    jstring path = (jstring) env->CallObjectMethod(file, methodID);
    chdir(env->GetStringUTFChars(path, JNI_FALSE));
    return 1;

}

extern "C"
jstring
Java_com_jash_luaandroid_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject instance) {
//    char buf[50];
//    getcwd(buf, sizeof(buf));
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    lua_getglobal(L, "_VERSION");
    const char *version = lua_tostring(L, -1);
    lua_pop(L, 1);
    lua_close(L);
    return env->NewStringUTF(version);
}

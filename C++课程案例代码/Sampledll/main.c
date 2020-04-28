// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the shared library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

// A function adding two integers and returning the result
#include "com_xuetang9_kenny_Sample.h"
//实现自定义头文件的方法

/*
 * Class:     com_xuetang9_kenny_Sample
 * Method:    intMethod
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_xuetang9_kenny_Sample_intMethod
  (JNIEnv * env, jobject obj, jint intNum)
{

    return intNum;
}

#include <jni.h>
#include <string>
#include "event2/event.h"
#include "common.h"

struct event_base *eb;
struct event   *ev_engine;
static void
xqc_client_engine_callback(int fd, short what, void *arg)
{
    LOGE("timer wakeup now:");
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_libeventcmakebuilddemo_MainActivity_stringFromJNI(
        JNIEnv* env,
    jobject /* this */) {
    LOGE("test test A");

    eb = event_base_new();

    ev_engine = event_new(eb, -1, 0, xqc_client_engine_callback, eb);
     struct timeval tv;
    tv.tv_sec = 6;
    tv.tv_usec = 0;
    event_add(ev_engine, &tv);

    LOGE("event_base_dispatch start");
    event_base_loop(eb,EVLOOP_ONCE); //EVLOOP_NONBLOCK -EVLOOP_NO_EXIT_ON_EMPTY -EVLOOP_ONCE
    LOGE("event_base_dispatch end");

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_libeventcmakebuilddemo_MainActivity_stringFromJNI2(
        JNIEnv* env,
        jobject /* this */) {
    LOGE("test test B");

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    event_add(ev_engine, &tv);

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
#include "StreamClientState.h"

StreamClientState::StreamClientState() {
    iter = nullptr;
    session = nullptr;
    subsession = nullptr;
    streamTimerTask = nullptr;
    duration = 0;
}

StreamClientState::~StreamClientState() {
    delete iter;
    if (session != nullptr) {
        UsageEnvironment &env = session->envir();

        env.taskScheduler().unscheduleDelayedTask(streamTimerTask);
        Medium::close(session);
    }
}
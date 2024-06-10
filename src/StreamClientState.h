#ifndef RTSP_CLIENT_STREAMCLIENTSTATE_H
#define RTSP_CLIENT_STREAMCLIENTSTATE_H

#include "rtspClientFactory.h"

class StreamClientState {
public:
    StreamClientState();

    virtual ~StreamClientState();

public:
    MediaSubsessionIterator *iter;
    MediaSession *session;
    MediaSubsession *subsession;
    TaskToken streamTimerTask;
    double duration;
};

#endif

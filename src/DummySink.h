//
// Created by 김경호 on 6/11/24.
//

#ifndef RTSP_CLIENT_DUMMYSINK_H
#define RTSP_CLIENT_DUMMYSINK_H
#define DUMMY_SINK_RECEIVE_BUFFER_SIZE 100000
#define DEBUG_PRINT_EACH_RECEIVED_FRAME 1

#include "rtspClientFactory.h"

class DummySink : public MediaSink {
public:
    static DummySink *createNew(UsageEnvironment &env,
                                MediaSubsession &subsession, // identifies the kind of data that's being received
                                char const *streamId = NULL); // identifies the stream itself (optional)

private:
    DummySink(UsageEnvironment &env, MediaSubsession &subsession, char const *streamId);

    // called only by "createNew()"
    virtual ~DummySink();

    static void afterGettingFrame(void *clientData, unsigned frameSize,
                                  unsigned numTruncatedBytes,
                                  struct timeval presentationTime,
                                  unsigned durationInMicroseconds);

    void afterGettingFrame(unsigned frameSize, unsigned numTruncatedBytes,
                           struct timeval presentationTime, unsigned durationInMicroseconds);

private:
    // redefined virtual functions:
    virtual Boolean continuePlaying();

private:
    u_int8_t *fReceiveBuffer;
    MediaSubsession &fSubsession;
    char *fStreamId;
};

#endif //RTSP_CLIENT_DUMMYSINK_H

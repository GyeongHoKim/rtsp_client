const addon = require('bindings')('rtsp_client');

// RTSPClient 클래스 정의
class RTSPClient {
    constructor(options) {
        this.client = new addon.RtspClientNapi(options);
    }

    connect(url) {
        return this.client.connect(url);
    }

    play() {
        return this.client.play();
    }

    pause() {
        return this.client.pause();
    }

    teardown() {
        return this.client.teardown();
    }
}

module.exports = {
    RTSPClient
};
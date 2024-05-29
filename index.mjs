import { createRequire } from 'module';
const require = createRequire(import.meta.url);

const addon = require('bindings')('addon');

class RTSPClient {
    constructor(options) {
        this.client = new addon.RTSPClient(options);
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

export { RTSPClient };
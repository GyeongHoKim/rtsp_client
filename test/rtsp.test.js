const addon = require('bindings')('rtsp_client');

test('test method returns test', () => {
    const factory = new addon.RTSPClientFactory();
    const test = factory.test();
    expect(test).toBe('test');
});

test('play method calls callback each packet', done => {
    const factory = new addon.RTSPClientFactory();
    const testURL = "rtsp://localhost:554/?guid=1234567890";
    const callback = (data) => {
        factory.teardown();
        expect(data).not.toBeNull();
        done();
    }
    factory.play(testURL, callback);
})
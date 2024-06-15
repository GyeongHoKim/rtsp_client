const addon = require('bindings')('rtsp_client.node');

test('test method returns test', () => {
    const client = new addon.GyeonghoRtspClient('rtsp://admin:pw@localhost:554/?guid=1234567890');
    const test = client.test();
    expect(test).toBe('test');
});

test('play method calls callback each packet', done => {
    const client = new addon.GyeonghoRtspClient('rtsp://admin:pw@localhost:554/?guid=1234567890');
    const callback = (buffer) => {
        client.teardown();
        expect(buffer.length).toBeGreaterThan(0);
        done();
    }
    client.play(callback);
})
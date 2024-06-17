const addon = require('bindings')('rtsp_client.node');
require('dotenv').config();
const testUrl = process.env.RTSP_URL;

test('is valid url', () => {
    const regex = new RegExp('rtsp://');
    expect(regex.test(testUrl)).toBe(true);
})

test('test method returns test', () => {
    const client = new addon.GyeonghoRtspClient(testUrl);
    const test = client.test();
    expect(test).toBe('test');
});

test('describe method returns sdp string', () => {
    const client = new addon.GyeonghoRtspClient(testUrl);
    const sdp_string = client.describe();
    expect(sdp_string.length).toBeGreaterThan(0);
});

test('play method calls callback each packet', done => {
    const client = new addon.GyeonghoRtspClient(testUrl);
    const callback = (buffer) => {
        client.teardown();
        expect(buffer.length).toBeGreaterThan(0);
        done();
    }
    const sdp_string = client.describe();
    expect(sdp_string.length).toBeGreaterThan(0);
    const setup_success = client.setup();
    expect(setup_success).toBe(true);
    done();
})
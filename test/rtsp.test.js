const addon = require('bindings')('rtsp_client');

test('test method returns test', () => {
    const client = new addon.RtspClientNapi({
        id: 'test',
        password: 'test',
        url: 'test'
    });
    const test = client.test();
    expect(test).toBe('test');
});
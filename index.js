const rtsp = require('bindings')('rtsp_client');

const client = new rtsp.RTSPClientWrapper('rtsp://example.com/stream');
client.connect();
client.play();
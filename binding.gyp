{
  "targets": [
    {
      "target_name": "addon",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "rtsp_client.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
        "./vcpkg/installed/arm64-osx/include"
      ],
      "libraries": [
        "./vcpkg/installed/arm64-osx/lib/libliveMedia.a",
        "./vcpkg/installed/arm64-osx/lib/libBasicUsageEnvironment.a",
        "./vcpkg/installed/arm64-osx/lib/libUsageEnvironment.a"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}

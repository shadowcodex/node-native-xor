{
    "targets": [{
        "target_name": "nodeNativeXor",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "cpp/main.cpp",
            "cpp/module/modulefunction.cpp"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
#!/usr/bin/bash
# 编译proto文件
# cp ../src/testData.proto .
# protoc --c_out=. testData.proto
# rm testData.pb-c.cc
# mv testData.pb-c.c testData.pb-c.cc

cd ../build/wasm-app
wamrc -o testapp.aot testapp.wasm
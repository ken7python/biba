emcc danmaku.cpp  \
    -o index.html \
    ./libraylib_web.a \
    --preload-file BGM.mp3 --preload-file gameover.mp3 --preload-file background.png  \
    -s TOTAL_MEMORY=671088640 \
    -s STACK_SIZE=125536 \
    -s USE_GLFW=3 \
    -s ASYNCIFY \
    -s ALLOW_MEMORY_GROWTH=1 \
    -DPLATFORM_WEB \
    -O2 \
    -Os \
    --shell-file=shell_minimal.html

python3 -m http.server 8080
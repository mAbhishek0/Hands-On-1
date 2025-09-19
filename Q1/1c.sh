mkfifo pipe1

echo "message through FIFO" > pipe1

cat < pipe1

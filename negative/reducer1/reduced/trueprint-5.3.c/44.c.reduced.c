enum { STREAM_FILE_END } input_buffer[4096];
short buffer_pointer;
int buffer_size;
buffered_read() {
  if (buffer_size)
    buffer_pointer = buffer_pointer + 1;
  airac_observe(input_buffer, buffer_pointer);
  buffered_read();
}

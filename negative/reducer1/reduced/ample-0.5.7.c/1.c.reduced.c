valof() {
  char *tmp =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  while (1) {
    airac_observe(tmp, 0);
    tmp++;
  }
}

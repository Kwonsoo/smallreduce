char readrequest_tmp___6;
readrequest() {
  char line[400];
  int end = &readrequest_tmp___6 - line;
  airac_observe(line, end);
}

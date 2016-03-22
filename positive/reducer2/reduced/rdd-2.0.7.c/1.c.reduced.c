int open_logfile_nprinter;
main() {
  int printers[2];
  unsigned tmp = open_logfile_nprinter++;
  airac_observe(printers, tmp);
}

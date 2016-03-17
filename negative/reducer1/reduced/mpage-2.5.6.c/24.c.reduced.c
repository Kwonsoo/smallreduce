do_args(argv) {
  int currarg = 1;
  while (1) {
    currarg++;
    airac_observe(argv, currarg);
  }
}

main(argc, argv) { do_args(argv); }

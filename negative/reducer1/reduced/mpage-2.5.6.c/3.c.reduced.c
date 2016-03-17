do_args(argv) {
  int currarg = 1;
  while (1) {
    airac_observe(argv, currarg);
    currarg++;
  }
}

main(argc, argv) { do_args(argv); }

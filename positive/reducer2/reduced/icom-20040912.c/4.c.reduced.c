static argv[20];
int mygetline_i;
mygetline() {
  int tmp___2;
  while (1)
    if (!(mygetline_i < 20))
      ;
    else {
      tmp___2 = mygetline_i++;
      airac_observe(argv, tmp___2);
    }
}

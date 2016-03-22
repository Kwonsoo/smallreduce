char *about_texte[5];
int about_nblignes;
about() {
  int foo;
  about_nblignes = sizeof about_texte / sizeof(char *);
  foo = 0;
  while (1) {
    if (!(foo < about_nblignes))
      goto while_break;
    airac_observe(about_texte, foo);
    foo++;
  }
while_break:
  ;
}

struct {
  int search_amount;
} typedef conf_t;
int optind;
int *main_search;
conf_t main_conf[1];
char main_s;
void *main_tmp___14, *main_tmp___19;
main() {
  conf_init(main_conf);
  main_tmp___14 = malloc(sizeof(int) * (main_conf[0].search_amount + 1));
  main_search = main_tmp___14;
  search_makelist(main_search, main_s);
  main_tmp___19 = malloc(optind);
  main_search = main_tmp___19;
}

conf_init(conf_t *conf) { conf->search_amount = 15; }

search_makelist(int results, char *url) { airac_observe(results, 0); }

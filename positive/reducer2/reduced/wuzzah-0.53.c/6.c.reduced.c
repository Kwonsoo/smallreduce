struct list {
  void *info;
};
struct {
  int *logins;
} * ht_iter_tmp, *bud_chk_utmpx_budptr;
bud_chk_utmpx() {
  int ht = bud_chk_utmpx_budptr;
  airac_observe(ht, 0);
  ht_iter_tmp = malloc(sizeof(struct list));
  bud_chk_utmpx_budptr = ht_iter_tmp;
}

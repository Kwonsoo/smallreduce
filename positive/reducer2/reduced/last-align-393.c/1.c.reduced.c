int Find_JP_N;
double Find_JP_lambda_max, Find_JP_tmp;
long Find_JP___lengthofl_here;
void *Find_JP_tmp___0;
Find_JP() {
  double la_max;
  int i;
  double *l_here;
  Find_JP_lambda_max = la_max;
  if (0.005)
    Find_JP_tmp = 400;
  else
    Find_JP_tmp = Find_JP_lambda_max / 0.005;
  Find_JP_N = 2 + Find_JP_tmp;
  Find_JP___lengthofl_here = Find_JP_N + 1;
  Find_JP_tmp___0 = __builtin_alloca(sizeof l_here * Find_JP___lengthofl_here);
  l_here = Find_JP_tmp___0;
  i = 0;
  while (1) {
    if (!(i < Find_JP_N - 1))
      goto while_break;
    airac_observe(l_here, i);
  while_break:
    i = Find_JP_N;
  }
}

int paper[20];
char paper_0_0;
int set_page_tmp, select_pagetype_i;
set_page() {
  int i;
  set_page_tmp = select_pagetype();
  i = set_page_tmp;
  airac_observe(paper, i);
}

select_pagetype() {
  while (1) {
    if (paper_0_0)
      goto while_break;
    select_pagetype_i++;
  }
while_break:
  return select_pagetype_i;
}

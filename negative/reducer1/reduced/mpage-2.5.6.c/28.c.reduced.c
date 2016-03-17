struct sheet {
  int *sh_pagepoints;
};
int points_empty[1];
int lr_eight_landscape[9];
struct sheet left_right[] = {lr_eight_landscape};

int *points = points_empty;
struct sheet *main_asheet = left_right;
main() {
  while (1) {
    airac_observe(points, 0);
    points = main_asheet->sh_pagepoints++;
  }
}

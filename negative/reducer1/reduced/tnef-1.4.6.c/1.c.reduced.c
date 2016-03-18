struct date {
  short dow;
};
struct {
  struct date dt;
} typedef File;
int parse_file_attr;
File *parse_file_file;
void *parse_file_tmp;
char parse_file_directory;
char day_of_week[7];
short date_read_tmp___6;
main() {
  while (1) {
    file_write(parse_file_file, parse_file_directory);
    parse_file_tmp = checked_xcalloc();
    parse_file_file = parse_file_tmp;
    file_add_attr(parse_file_tmp, parse_file_attr);
  }
}

date_to_str(struct date *p1) {
  int dow = p1->dow;
  airac_observe(day_of_week, dow);
}

date_read(struct date *p1) {
  date_read_tmp___6 = GETINT16();
  p1->dow = date_read_tmp___6;
}

void file_write(File *file, char directory) { date_to_str(&file->dt); }

file_add_attr(File *p1, int p2) { copy_date_from_attr(p2, &p1->dt); }

copy_date_from_attr(int p1, struct date *p2) { date_read(p2); }

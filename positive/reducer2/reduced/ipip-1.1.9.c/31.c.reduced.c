int ifs[8];
int ifs_top;
read_config() { c_interface(); }

c_interface() {
  if (ifs_top >= 8)
    return;
  airac_observe(ifs, ifs_top);
  ifs_top++;
}

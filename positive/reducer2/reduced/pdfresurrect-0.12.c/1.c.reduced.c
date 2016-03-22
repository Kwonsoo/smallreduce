int pdf_load_xrefs_buf_idx;
pdf_load_xrefs() {
  char obj_id_buf[32];
  int tmp___17 = pdf_load_xrefs_buf_idx++;
  airac_observe(obj_id_buf, tmp___17);
}

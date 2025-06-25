#ifndef PARSER_H
#define PARSER_H

typedef struct{
  char *name;
  char *type;
  char **constraints;
}Field;

typedef struct{
  char *field_name;
  char *type;
  void *data;
}Record;

typedef struct{
  char *name;
  int field_count;
  void **fields;
  void **records;
}Table;

#endif

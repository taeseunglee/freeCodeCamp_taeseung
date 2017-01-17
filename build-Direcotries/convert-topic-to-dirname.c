#include <stdio.h>

int main()
{
  FILE* fp_topic = NULL,
    *fp_dirname = NULL;
  char fn_topic[100] = {0},
       fn_dirname[100] = {0};
  
  printf("<System> Enter the Topic text filename\n>> ");
  scanf("%s", fn_topic);
  printf("<System> Enter the Directory text filename\n>> ");
  scanf("%s", fn_dirname);

  fp_topic = fopen(fn_topic, "r");
  fp_dirname = fopen(fn_dirname, "w");

  if (!fp_topic || !fp_dirname) {
    printf("file open error\n");
    return -1;
  }
  
  /* conversion part */
  int numbering = 1;
  char topic[103] = {0,};
  while(fgets(topic+3, 100, fp_topic) != NULL) {
    /* add a number to a directory name */
    topic[0] = numbering/10 + '0';
    topic[1] = numbering%10 + '0';
    topic[2] = '.';

    /* change space to '-' */
    int i;
    for (i = 3; topic[i] != '\n'; ++i) {
      if (topic[i] == ' ')
        topic[i] = '-';
    }
    topic[i] = 0;

    printf("dir : %s\n", topic);
    fprintf(fp_dirname, "%s\n", topic);

    ++numbering;
  }

  fclose(fp_topic);
  fclose(fp_dirname);

  return 0;
}

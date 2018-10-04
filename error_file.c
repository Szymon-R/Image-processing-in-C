 #include "error_file.h"

 void error_handling(const char* statement)
 {
     printf(statement);
      printf("%s\n",strerror(errno));
     return;
 }


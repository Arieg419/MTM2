#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "conversation.h"

char *strRev(char *str)
{
      char *p1, *p2;
      char* temp;

      if (str == NULL) {
            return str;
      }
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {		
      		*temp = *p1
            *p1 = *p2;
            *p2 = *p1;
      }
      return str;
}

int main() {
	char* origString="Shavua tov";
	strRev(origString);
	printf("%s\n", origString);
	return 0;
}
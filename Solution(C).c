
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char a[100], b[100];
    int c = 0, d = 0;
    int flag = 1;
    char k;
    int i, j, p, q, r;
    int x, y;
    int left, right, width;
    int count = 0;

    printf("Enter some text\n");

    fgets(a,sizeof(a),stdin);
      
    x = strlen(a);
    do {
        printf("Enter left justification number, right justification number and middle width number:\n");
        scanf("%d %d %d", &left, &right, &width);

        if (width > (left + right)) {
            flag = 1;
        }
        else {
            flag = 0;
            printf("Invalid. Width cannot be lesser than or equal to sum of left and right justification\n");
        }
    } while (flag == 0);

    // Remove multiple spaces
    while (a[c] != '\0') {
        if (a[c] == ' ') {
            int temp = c + 1;
            if (a[temp] != '\0') {
                while (a[temp] == ' ' && a[temp] != '\0') {
                    if (a[temp] == ' ') {
                        c++;
                    }
                    temp++;
                }
            }
        }
        b[d] = a[c];
        c++;
        d++;
    }

    b[d] = '\0';

    printf("\nRemoving multiple spaces (if any)\n%s\n", b);

    y = strlen(b);

    // To capitalize the letters which are followed by the symbol fullstop,full stop, comma, exclamation
    for (i = 0; i < strlen(b) - 1; i++) {
        if ((b[i] == '.' || b[i] == '!' || b[i] == ',') && (b[i + 1] != ' ')) {
            k = b[i + 1];
            while (k == ' ') {
                b[i] = NULL;
                i++;
                k = b[i + 1];
            }
            for (j = strlen(b); j >= i + 1; j--)
                b[j + 1] = b[j];
            b[i + 1] = ' ';
            b[i + 2] = toupper(b[i + 2]);
        }

        else if ((b[i] == '.' || b[i] == '!' || b[i] == ',') && (b[i + 1] == ' ')) {

            b[i + 2] = toupper(b[i + 2]);
            i += 1;
        }
    }

    printf("\nText after capitalizing:\n%s\n", b);

    printf("Final result =\n");
    //Print with left width and right width justification
    while (1) {
        for (j = 0; j < width; j++) {
            //left width
            for (p = 0; p < left; p++) {  
                printf("#");       
            }

            //middle width = left width + (total width - (left width + right width))
            for (q = left; q < left + (width - (left + right)); q++) {
                printf("%c ", b[count]);
                count++;
                if (count >= strlen(b))
                    exit(0);
            }
            //right width
            for (r = (left + (width - (left + right))); r < width; r++) {
                printf("*");
            }
            printf("\n");
        }

    }

}

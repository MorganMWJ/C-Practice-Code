#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum boolean{//giving a name for our new enum
        fal,tru
    };
    enum boolean skip3 = fal;
    printf("%d\n",fal);

    typedef enum {
        sun,mon,tues,wed=7,thus,fri,sat
    }weekday;
    //here we are not giving an enum name only a name for our new type
    //enums are ints
    //sun = 0 , mon = 1, tues = 2, so on...
    //can set vaules other than that default if wanted
    //but becasue wed=7 thus=8 and so on...
    weekday day1, day2, day3;
    day1 = sun;
    day2 = mon;
    day3 = thus;
    printf("%d\n",day1);
    printf("%d\n",day2);
    printf("%d\n",day3);
    return 0;
}

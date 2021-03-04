#include <stdarg.h>
#include <stdio.h>

void mini_print(char *, ...);

int main() {
    mini_print("%d, %s\n", 3, "a");
    return 0;
}

void mini_print(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

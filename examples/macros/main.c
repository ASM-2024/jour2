#include <err.h>
#include <stdio.h>
#include <string.h>

#define CRESET "\033[0m"
#define CBOLD "\033[1m"
#define CBLUE "\033[34m"

#define NAME(VAR) #VAR

#define VERBOSE_DEBUG

// Take a look at the `debug` target in the Makefile!
#ifdef VERBOSE_DEBUG
#define DBG(FMT, ...)                                                          \
        warnx("[" CBOLD CBLUE "DBG" CRESET "] %s:%d | " FMT,                   \
              strchr("/" __FILE__, '/') + 1, __LINE__, __VA_ARGS__)
// Here we define an empty behaviour for the macro if we did not compile for
// debugging. Therefore, we can keep the debugs in for submission, saving a bit
// of time that usually would have been wasted removing prints everywhere.
#else
#define DBG(FMT, ...) {}
#endif

int main(void)
{
    char *string_to_debug = "Hello, world!";

    // So, this will do something if and only if we define the macro
    // VERBOSE_DEBUG when compiling or somewhere prior to the DBG macro
    // definition in general (for example in another header included in this
    // file).
    DBG("%s = %s", NAME(string_to_debug), string_to_debug);
    
    printf("Did we debug \"%s\"?\n", string_to_debug);

// While this definitely works, it is not meant to actually be used in this way.
// If you ever feel the need to do something similar, please reconsider how your
// function or program works.
// When writing software in C this type of pattern usually only happens in the
// cases where some features are compiler- or platform-specific. So more or less
// never in the case of the S4.
#ifdef VERBOSE_DEBUG
    puts("Yes we did!");
#else
    puts("No we did not :(");
#endif

    return 0;
}

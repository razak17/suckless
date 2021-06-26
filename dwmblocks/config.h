// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
 /* Icon          Command             Update Interval     Update Signal */

    {" 📦 ",      "sb-pacpackages",   360,                    8},
    {" ",         "sb-cpusage",       10,                   18},
    {"",          "sb-memory",        12,                   26},
    {"",          "sb-swap",          37,                    2},
    {"",          "sb-volume",        0,                   10},
    {"",          "sb-battery",      17,                    3},
    {"",          "sb-internet",      3,                    4},
    {"",          "sb-clock",        60,                    5},
    // {"📦 ",       "sb-installed",     0,                   17},
    // {"",          "sb-disk",         10,                   21},
    // {"",          "sb-nettraf",       1,                   16},

    // {"",	"sb-memory",	10,	14},
};

// Sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char *delim = "|";

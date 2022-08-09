// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
 /* Icon          Command             Update Interval     Update Signal */

    {" ",         "dt-kernel",          0,                21},
 // {" ",         "sb-pacpackages",   360,                 8},
    {"",          "sb-cpusage",         5,                18},
    {"",          "sb-memory",         10,                26},
 // {"",          "sb-swap",           15,                 2},
    {"",          "sb-volume",          0,                10},
    {"",          "sb-battery",        25,                 3},
    {"",          "sb-internet",       10,                 4},
    {"",          "sb-clock",          60,                 5},
 // {"📦 ",       "sb-installed",       0,                17},
 // {"",          "sb-disk",           10,                21},
 // {"",          "sb-nettraf",         1,                16},

    // {"",	"sb-memory",	10,	14},
};

// Sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char *delim = "|";

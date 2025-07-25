// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /* Icon       Command            Update Interval   Update Signal */

    {" ",         "kernel",          0,                21},
    // {" ",         "pacpackages",   360,                 8},
    {"",          "cpuusage",        6,                18},
    {"",          "memory",          4,                26},
    // {"",          "swap",           15,                 2},
    {"",          "volume",          0,                10},
    // {"",          "bluetooth",       5,                 6},
    {"",          "internet",        2,                 4},
    {"",          "battery",         3,                 3},
    {"",          "clock",           1,                 5},
    // {"📦 ",       "installed",       0,                17},
    // {"",          "disk",           10,                21},
};

// Sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char *delim = " "; // |

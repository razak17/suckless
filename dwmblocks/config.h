// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/

    // {" 🔺 ", "dt-upt", 60, 2},
    {" 🔺 ", "sb-pacpackages", 0, 8},
    // {"📦 ", "sb-installed", 0, 17},
    // {"", "sb-cpu", 10, 17},
    {"", "sb-cpusage", 7, 18},
    // {"", "sb-disk", 10, 21},
    {"🧠 ", "dt-memory", 8, 26},
    {"💻 ", "sb-swap", 27, 2},
    {"", "sb-volume", 0, 10},
    {"", "sb-nettraf", 1, 16},
    {"", "sb-battery", 17, 3},
    // {" 🔆 ", "brightness", 6, 1},
    {"", "sb-internet", 7, 4},
    // {"", "vpn", 10, 0},
    // {" 🕑 ", "dt-clock", 5, 0},
    {"", "dt-clock", 59, 0},

    /* {"",	"sb-tasks",	10,	26},
    {"",	"sb-memory",	10,	14},
    {"",	"sb-music",	0,	11},
    {"",	"sb-clock",	60,	1}, */
};

// Sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char *delim = "|";

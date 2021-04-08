// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/

    {" 📦 ", "sb-pacpackages", 0, 8},
    // {"📦 ", "sb-installed", 0, 17},
    {"", "sb-cpusage", 7, 18},
    // {"", "sb-disk", 10, 21},
    {"", "sb-memory", 8, 26},
    {"🔁 ", "sb-swap", 27, 2},
    {"", "sb-volume", 0, 10},
    // {"", "sb-nettraf", 1, 16},
    {"", "sb-battery", 17, 3},
    {"", "sb-internet", 7, 4},
    {"", "sb-clock", 59, 0},

    // {"",	"sb-memory",	10,	14},
};

// Sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char *delim = "|";

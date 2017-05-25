
#include <curses.h>
#include <stdlib.h>

static WINDOW *s_win;
static int s_win_h;
static int s_win_w;

// tmp: mv to struct
static int buckets[100];
static int max = 100;

static inline int w_x(int x) { return s_win_h - ((x * s_win_h) / max); }
static inline int w_y(int y) { return /*(y * s_win_w) / 100*/y; }

static void init_window(void)
{
    if ( (s_win = initscr()) == NULL ) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }
    getmaxyx(s_win, s_win_h, s_win_w);
    refresh();
}

static void fini_window(void)
{
    delwin(s_win);
    endwin();
}

static void refresh_screen(int input)
{
    if (buckets[input] > max) {
        max *= 2;
        for (int i=0; i<100; i++) {
            for (int j=0; j<=max; j++) {
                if (j <= buckets[i]) {
                    mvaddch(w_x(j), i, '#');
                } else {
                    mvaddch(w_x(j), i, ' ');
                }
            }
        }
    } else {
        mvaddch(w_x(buckets[input]), w_y(input),'#');
    }

    refresh();
}

// interface
void alectrona_start_display(void)
{
    init_window();
    for (int i=0; i<100; i++) { buckets[i] = 0; }
}

void alectrona_finish(void)
{
    fini_window();
}

void alectrona_feed_one(int input)
{
    buckets[input]++;
    refresh_screen(input);
}


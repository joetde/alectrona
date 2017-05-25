
#pragma once

// first appoarch with int between 0 and 100
// auto scale + auto render

/**
 * Add a new point to the display
 */
void alectrona_feed_one(int input);

// future
void alectrona_buffer_one(int input);
void alectrona_flush_now(int input);
void alectrona_config(void *_); 

/**
 * Start ncurses
 */
void alectrona_start_display(void);

/**
 * Clear ncurses
 */
void alectrona_finish(void);


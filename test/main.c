
#include <stdlib.h>
#include <unistd.h> // sleep
#include <alectrona/alectrona.h>

int main(void)
{
    alectrona_start_display();
    for (int i=0; i<1000000; i++) { alectrona_feed_one(rand() % 100); usleep(5); }
    usleep(1000000);
    alectrona_finish();
    return 0;
}


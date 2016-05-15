#include "types.h"
#include "user.h"
#include "date.h"

int main(void) {
	struct rtcdate d;
	if (date(&d)) {
		printf(2, "date error\n");
		exit();
	}

	printf(1, "%d/%d/%d ", d.month, d.day, d.year);
	printf(1, "%d:%d:%d\n",d.hour, d.minute, d.second);
	exit();
}

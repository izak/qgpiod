#include <gpiod.h>
#include "qgpiod.h"

static const char* chipPath = "/dev/gpiochip0";

QGpiod::QGpiod() : mState(0)
{
	// Cerbo digital 1
	struct gpiod_chip *chip;
	chip = gpiod_chip_open(chipPath);
	mLine  = gpiod_chip_get_line(chip, GPIOD_LINE_NUMBER);
	gpiod_line_request_output(mLine, "out1", false, GPIOD_ACTIVE_STATE_HIGH);
}

void QGpiod::toggle()
{
	mState = !mState;
	gpiod_line_set_value(mLine, mState);
}

void QGpiod::set(int l)
{
	gpiod_line_set_value(mLine, mState = l);
}

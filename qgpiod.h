#ifndef _QGPIOD_H
#define _QGPIOD_H

#define GPIOD_LINE_NUMBER 6

class QGpiod
{
    public:
        static QGpiod& getInstance()
        {
            static QGpiod instance;
            return instance;
        }
		void toggle();
    private:
        QGpiod();
        QGpiod(QGpiod const&);
        void operator=(QGpiod const&);
		int mState;
		struct gpiod_line *mLine;
};
#endif

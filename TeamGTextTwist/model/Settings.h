#ifndef SETTINGS_H
#define SETTINGS_H

namespace model
{
    class Settings
    {
        public:
            Settings(int gameplayTime, bool reuseLetters);
            virtual ~Settings();

            int getGameplayTime();
            bool getReuseLetters();

        protected:

        private:
            int gameplayTime;
            bool reuseLetters;
    };
}


#endif // SETTINGS_H

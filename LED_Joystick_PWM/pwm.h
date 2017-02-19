#ifndef _AK_PWM
#define _AK_PWM

class AK_PWM {
    public:
        // Constructor
        AK_PWM() {}
        ~AK_PWM() {}
        // Declare the pin to be controlled and percent uptime
        AK_PWM(int pin, int percentup);
        
        // Public methods
        void setPeriod(int percentup);

    private:
        unsigned int _percentup = 50;
        int _pin;
        
        // Need to receive the pin to be controlled by PWM and keep it updated

}
#endif /* _AK_PWM */

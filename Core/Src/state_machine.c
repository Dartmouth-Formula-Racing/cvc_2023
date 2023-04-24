// #include "cmsis_os.h"

typedef enum CarState {
    precharge,
    ts_energized,
    drive
} CarState;

void update_state_machine(void);
CarState get_state(void);
void rtd_button_callback(void);

void update_state_machine() {
    CarState state = precharge;

    for (;;) {
        switch(state){ 
            case precharge: 
            if (voltages >= 0.9*packVoltage()) { 
                state = ts_energized;
            }
            break;

            case ts_energized:
                close AIR; 
                rtd_button_callback();
                state = drive;
            break; 

            case drive:
                if (voltages < 0.2*packVoltage()) { 
                    state= precharge;
                }
            break;

        }
        OSDelay(10);
    }

}

CarState get_state() {
    
    return state;
}

void rtd_button_callback() {

}
#include "cmsis_os.h"

Typedef enum CarState {
    precharge,
    ts_energized,
    drive
} CarState;

// pedal position 1 and 2 are two diff sensors, if absolute value of their difference is greater, dont move
int get_pedal_position1(void); //tell you how much the pedal is pressed down
int get_pedal_position2(void);
void set_torque_command(float); // how fast you want the car to go
CarState get_state(void);


#define LOWEST_PEDAL_POSITION 0;
#define HIGHEST_PEDAL_POSITION 100; //turning pedal position into a fraction
#define POSITION_DIFFERENCE_TOLERANCE 5;

// Make 2 global variables to store the range of possible pedal positions

// pedal position - lowest pedal position, then divide this number by  highest - lowest (how big the range is)

void torque_command() {

    for (;;) {
        float avergage_pedal_position, final_pedal_position;
        if (abs(get_pedal_position1()-get_pedal_position2()) > POSITION_DIFFERENCE_TOLERANCE) {
            final_pedal_position = 0;
            report_error("Pedal position set to 0 due to conflicting potentiometer readings");
        }
        else{
            average_pedal_position= (get_pedal_position_1()- get_pedal_position2());
            final_pedal_position = ((average_pedal_position-LOWEST_PEDAL_POSITION)/ (HIGHEST_PEDAL_POSITION-LOWEST_PEDAL_POSITION));
            }
        if ((final_pedal_position < LOWEST_PEDAL_POSITION) || (final_pedal_position > HIGHEST_PEDAL_POSITION)) {
            final_pedal_position = 0;
            report_error("Pedal position set to 0 due to potentiometer value out of range");
        }
        
        set_torque_command(final_pedal_position);
        OSDelay(10);
    }
}
            
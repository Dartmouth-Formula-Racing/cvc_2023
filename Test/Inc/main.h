typedef enum CarState {
    precharge,
    ts_energized,
    drive
} CarState;

void update_state_machine(void);
CarState get_state(void);
void rtd_button_callback(void);
int* get_voltages(void);

#define PACK_VOLTAGE 252;
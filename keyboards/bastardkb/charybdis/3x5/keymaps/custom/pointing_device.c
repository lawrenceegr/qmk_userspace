#include "pointing_device.h"
#include "cirque_pinnacle.h"
#include "pmw3360.h"

// Combined device initialization
void pointing_device_init_kb(void) {
    pmw3360_init();
    cirque_pinnacle_init();
}

// Combined report processing
report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    static report_mouse_t combined_report = {0};
    
    // Get reports from both devices
    report_pmw3360_t pmw_report = pmw3360_read_burst();
    report_cirque_pinnacle_t cirque_report = cirque_pinnacle_read_data();
    
    // Process PMW3360 (trackball) input - scale down for coarse control
    combined_report.x = pmw_report.x / 2;
    combined_report.y = pmw_report.y / 2;
    combined_report.buttons |= pmw_report.buttons;
    
    // Process Cirque (trackpad) input - keep original scale for precision
    combined_report.x += cirque_report.x;
    combined_report.y += cirque_report.y;
    combined_report.buttons |= cirque_report.buttons;
    
    // Handle tap gestures from Cirque
    if (cirque_report.tap) {
        combined_report.buttons |= MOUSE_BTN1;
    }
    
    return pointing_device_combine_reports(mouse_report, combined_report);
}

// Optional: Adjust DPI for both devices
void pointing_device_set_cpi_kb(uint16_t cpi) {
    pmw3360_set_cpi(cpi);
    // Cirque doesn't have DPI adjustment, but we can scale the output
    // Scaling would be handled in the report processing
}

// VGA Kirid Driver - Ports

/* OTHER */
#define VGA_MODE_CONTROL        0x3C0
#define VGA_OVERSCAN_REGISTER   0x3C0
#define VGA_COLOR_PLANE_ENABLE  0x3C0
#define VGA_HORIZONTAL_PANNING  0x3C0
#define VGA_COLOR_SELECT        0x3C0

#define VGA_CHARACTER_SELECT    0x3C4
#define VGA_MEMORY_MODE_REG     0x3C4

#define VGA_MODE_REGISTER       0x3CE
#define VGA_MISC_REGISTER       0x3CE // Miscellaneous Register

#define VGA_MODE_CONTROL_2      0x3D4


/* CRT CONTROLLER */
#define VGA_MISC_OUTPUT_REG     0x3C2 // Miscellaneous Output Register

#define VGA_CLOCK_MODE_REGISTER 0x3C4

#define VGA_HORIZONTAL_TOTAL    0x3D4
#define VGA_HOR_DISP_ENA_END    0x3D4 // Horizontal Display Enable End
#define VGA_HOR_BLANK_START     0x3D4 // Horizontal Blank Start
#define VGA_HOR_RETRACE_START   0x3D4 // Horizontal Retrace Start
#define VGA_HOR_RETRACE_END     0x3D4
#define VGA_VERTICAL_TOTAL      0x3D4
#define VGA_OVERFLOW_REGISTER   0x3D4
#define VGA_PRESET_ROW_SCAN     0x3D4
#define VGA_MAXIMUM_SCAN_LINE   0x3D4
#define VGA_VER_RETRACE_START   0x3D4 // Vertical Retrace Start
#define VGA_VER_RETRACE_END     0x3D4 // Vertical Retrace End
#define VGA_VER_DIS_ENA_END     0x3D4 // Vertical Display Enable End
#define VGA_LOGICAL_WIDTH       0x3D4
#define VGA_UNDERLINE_LOCATION  0x3D4
#define VGA_VER_BLANK_START     0x3D4 // Vertical Blank Start
#define VGA_VERTICAL_BLANK_END  0x3D4
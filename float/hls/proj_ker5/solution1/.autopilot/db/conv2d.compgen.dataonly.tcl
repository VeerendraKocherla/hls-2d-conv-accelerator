# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_control {
kernel_in_0_0 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 16
	offset_end 23
}
kernel_in_0_1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
kernel_in_0_2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 32
	offset_end 39
}
kernel_in_0_3 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 40
	offset_end 47
}
kernel_in_0_4 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 48
	offset_end 55
}
kernel_in_1_0 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 56
	offset_end 63
}
kernel_in_1_1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 64
	offset_end 71
}
kernel_in_1_2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 72
	offset_end 79
}
kernel_in_1_3 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 80
	offset_end 87
}
kernel_in_1_4 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 88
	offset_end 95
}
kernel_in_2_0 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 96
	offset_end 103
}
kernel_in_2_1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 104
	offset_end 111
}
kernel_in_2_2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 112
	offset_end 119
}
kernel_in_2_3 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 120
	offset_end 127
}
kernel_in_2_4 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 128
	offset_end 135
}
kernel_in_3_0 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 136
	offset_end 143
}
kernel_in_3_1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 144
	offset_end 151
}
kernel_in_3_2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 152
	offset_end 159
}
kernel_in_3_3 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 160
	offset_end 167
}
kernel_in_3_4 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 168
	offset_end 175
}
kernel_in_4_0 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 176
	offset_end 183
}
kernel_in_4_1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 184
	offset_end 191
}
kernel_in_4_2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 192
	offset_end 199
}
kernel_in_4_3 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 200
	offset_end 207
}
kernel_in_4_4 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 208
	offset_end 215
}
img_size { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 216
	offset_end 223
}
ap_start {
	mailbox_input_ctrl 0
	mailbox_output_ctrl 0
	auto_restart_enabled 1
	auto_restart_counter_num 0
	auto_restart_counter_offset 16
	auto_restart_counter_size 32
}
ap_done { }
ap_ready { }
ap_idle { }
}
dict set axilite_register_dict control $port_control



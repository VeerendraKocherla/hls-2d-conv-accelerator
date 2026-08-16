set SynModuleInfo {
  {SRCNAME conv2d MODELNAME conv2d RTLNAME conv2d IS_TOP 1
    SUBMODULES {
      {MODELNAME conv2d_fadd_32ns_32ns_32_5_full_dsp_1 RTLNAME conv2d_fadd_32ns_32ns_32_5_full_dsp_1 BINDTYPE op TYPE fadd IMPL fulldsp LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME conv2d_fmul_32ns_32ns_32_4_max_dsp_1 RTLNAME conv2d_fmul_32ns_32ns_32_4_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME conv2d_mul_32ns_32ns_64_1_1 RTLNAME conv2d_mul_32ns_32ns_64_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME conv2d_line_buf_0 RTLNAME conv2d_line_buf_0 BINDTYPE storage TYPE ram_2p IMPL bram LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME conv2d_control_s_axi RTLNAME conv2d_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
      {MODELNAME conv2d_regslice_both RTLNAME conv2d_regslice_both BINDTYPE interface TYPE interface_regslice INSTNAME conv2d_regslice_both_U}
    }
  }
}
